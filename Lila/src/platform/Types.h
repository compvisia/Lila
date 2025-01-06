#pragma once

//---------------------------------------------------------//
//---------------------- Basic types ----------------------//
//---------------------------------------------------------//

#include <cstdint>

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using b8  = uint8_t;
using b16 = uint16_t;
using b32 = uint32_t;
using b64 = uint64_t;

using f32 = float;
using f64 = double;

using c8 = char;
using c16 = char16_t;
using c32 = char32_t;

//------------------------------------------------------------//
//--------------------- Containers types ---------------------//
//------------------------------------------------------------//

#include <vector>

template<typename T>
using vec = std::vector<T>;

//----------------------------------------------------------//
//---------------------- String types ----------------------//
//----------------------------------------------------------//

#include <string>

using str = std::string;

//----------------------------------------------------------//
//---------------------- Memory types ----------------------//
//----------------------------------------------------------//

#include <memory>

template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T>
using Unique = std::unique_ptr<T>;

//--------------------------------------------------------------//
//---------------------- Memory functions ----------------------//
//--------------------------------------------------------------//

template<typename T, typename ... Args>
constexpr inline Shared<T> shared(Args&& ... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

template<typename T, typename ... Args>
constexpr inline Unique<T> unique(Args&& ... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}