#pragma once

#include <bitset>

namespace Lila {

    const int MAX_ENTITIES = 2048;

    typedef unsigned long long Entity;
    typedef std::bitset<32> Mask;

    struct EntityInfo {
        Entity entity;
        Mask mask;
    };

    
}