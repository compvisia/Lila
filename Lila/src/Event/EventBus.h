#pragma once

#include <vector>
#include <algorithm>
#include <typeindex>
#include <functional>
#include <ranges>
#include <type_traits>
#include <unordered_map>

#include "Common/Types.h"

namespace Lila {

    class EventBus;

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

        EventSubscription&& operator=(EventSubscription&& other) noexcept {
            bus_m = other.bus_m;
            type_m = other.type_m;
            id_m = other.id_m;

            other.invalidate();
        };


        void disconnect();

        ~EventSubscription() {
            disconnect();
        }

        [[nodiscard]] b8 isValid() const {
            return bus_m && id_m != 0;
        }

    private:
        EventSubscription(EventBus* bus, std::type_index type, u64 id)
            : bus_m(bus), type_m(type), id_m(id) {}

        void invalidate() {
            bus_m = nullptr;
            id_m = 0;
        }

    private:
        EventBus* bus_m = nullptr;
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

            auto type = std::type_index(typeid(TypeCleanup));
            u64 id = nextId_m++;

            auto wrapper = std::function<void(const void*)>(
                [forward = std::forward<Function>(function)](const void* event) {
                    forward(*static_cast<const TypeCleanup*>(event));
                }
            );

            listeners_m[type].emplace_back(id, std::move(wrapper));

            return {this, type, id};
        }

        void unsubscribe(const EventSubscription& EventSubscription) {
            const auto it = listeners_m.find(EventSubscription.type_m);

            if (it == listeners_m.end())
                return;

            auto &listenerEntries = it->second;

            std::erase_if(
                listenerEntries,
                [&](const ListenerEntry& entry) {
                    return entry.first == EventSubscription.id_m;
                }
            );

            if (listenerEntries.empty())
                listeners_m.erase(it);
        }

        template<typename EventType>
        void emit(const EventType& event) {
            using TypeCleanup = std::decay_t<EventType>;

            const auto type = std::type_index(typeid(TypeCleanup));
            const auto it = listeners_m.find(type);

            if (it == listeners_m.end())
                return;

            auto &listenerEntries = it->second;

            for (auto &val: listenerEntries | std::views::values) {
                val(static_cast<const void*>(&event));
            }
        }

    private:
        using ListenerEntry = std::pair<u64, std::function<void(const void*)>>;

    private:
        std::unordered_map<std::type_index, std::vector<ListenerEntry>> listeners_m;
        u64 nextId_m{1};
    };

    inline void EventSubscription::disconnect() {
        if (!bus_m)
            return;

        static_cast<EventBus*>(bus_m)->unsubscribe(*this);
        invalidate();
    }

} // namespace Lila
