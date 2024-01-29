#pragma once

#include "Layer.h"

#include <vector>

namespace Lila {
    
    class LayerStack {
    public:
        LayerStack();
        ~LayerStack();

        void pushLayer(Layer layer);
        void popLayer(Layer layer);

        void onImGui();

    private:
        std::vector<Layer> stack;
    };

}
