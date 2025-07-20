#pragma once

#include <memory>

template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr inline Shared<T> shared(Args&& ... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template<typename T, typename ... Args>
constexpr inline Unique<T> unique(Args&& ... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}
