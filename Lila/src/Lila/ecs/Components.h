#pragma once

#include "Lila/utils/Vectors.h"

#include <string>

namespace Lila {

    struct Tag {
        char name[64] = "NULL";
    };

    struct Transform {
        Vec3 position = Vec3(0,0,0);
        Vec3 rotation = Vec3(0,0,0);
        Vec3 scale    = Vec3(1,1,1);
    };

}