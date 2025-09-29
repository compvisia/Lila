#pragma once

#include <vector>
#include <algorithm>
#include <typeindex>
#include <functional>
#include <type_traits>
#include <unordered_map>

#include "Common/Types.h"

namespace Lila {

    class EventSubscription {
        friend class EventBus;
    public:
        EventSubscription() = default;
        EventSubscription(const EventSubscription&) = delete;
        EventSubscription& operator=(const EventSubscription&) = delete;

        EventSubscription(EventSubscription&& other) noexcept
            : bus_m(other.bus_m), type_m(other.type_m), id_m(other.id_m) {
            other.invalidate();
        };

        ~EventSubscription() {
            disconnect();
        }

        void disconnect();

    private:
        EventSubscription(void* bus, std::type_index type, u64 id)
            : bus_m(bus), type_m(type), id_m(id) {}

        void invalidate() {
            bus_m = nullptr;
            id_m = 0;
        }

    private:
        void* bus_m = nullptr;
        std::type_index type_m{typeid(void)};
        u64 id_m = 0;
    };

    class EventBus {
    public:
        EventBus() = default;
        ~EventBus() {
            listeners_m.clear();
        }

        template<typename EventType, typename Function>
        EventSubscription subscribe(Function&& function) {
            using TypeCleanup = std::decay_t<EventType>;

            std::type_index type = std::type_index(typeid(TypeCleanup));
            u64 id = nextId_m++;

            auto wrapper = std::function<void(const void*)>(
                [forward = std::forward<Function>(function)](const void* event) {
                    forward(*static_cast<const TypeCleanup*>(event));
                }
            );

            listeners_m[type].emplace_back(id, std::move(wrapper));

            return EventSubscription(this, type, id);
        }

        void unsubscribe(const EventSubscription& EventSubscription) {
            auto it = listeners_m.find(EventSubscription.type_m);

            if(it == listeners_m.end())
                return;

            auto &listenerEntries = it->second;

            listenerEntries.erase(std::remove_if(
                listenerEntries.begin(),
                listenerEntries.end(),
                [&](const ListenerEntry& entry) {
                    return entry.first == EventSubscription.id_m;
                }
            ), listenerEntries.end());

            if(listenerEntries.empty())
                listeners_m.erase(it);
        }

        template<typename EventType>
        void emit(const EventType& event) {
            using TypeCleanup = std::decay_t<EventType>;

            std::type_index type = std::type_index(typeid(TypeCleanup));
            auto it = listeners_m.find(type);

            if(it == listeners_m.end())
                return;

            auto &listenerEntries = it->second;

            for(auto& entry : listenerEntries) {
                entry.second(static_cast<const void*>(&event));
            }
        }

    private:
        using ListenerEntry = std::pair<u64, std::function<void(const void*)>>;

    private:
        std::unordered_map<std::type_index, std::vector<ListenerEntry>> listeners_m;
        u64 nextId_m{1};
    };

    // WHY? This function is defined here because it needs the definition of EventBus.
    inline void EventSubscription::disconnect() {
        if (!bus_m || id_m == 0) return;
        static_cast<EventBus*>(bus_m)->unsubscribe(*this);
        invalidate();
    };

} // namespace Lila
