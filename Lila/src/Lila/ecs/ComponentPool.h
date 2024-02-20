#pragma once

#include "Entity.h"

#include <vector>

namespace Lila {

    static int s_componentCounter = 0;
    template <class T>
    int GetId() {
        static int s_componentId = s_componentCounter++;
        return s_componentId;
    }

    class ComponentPool {
    public:
        ComponentPool(size_t size) {
            byteSize = size + 1;
            data = new char[byteSize * MAX_ENTITIES];
        }

        ~ComponentPool() {
            delete [] data;
        }

        inline void* get(size_t index) {
            return data + index * byteSize;
        }


        char* data { nullptr };
        size_t byteSize { 0 };


    };

}
