#include "LayerStack.h"

namespace Lila {

    LayerStack::LayerStack() {
        stack.reserve(256);
    }

    LayerStack::~LayerStack() {
        stack.empty();
    }

    void LayerStack::pushLayer(Layer layer) {
        stack.push_back(layer);
    }

    void LayerStack::popLayer(Layer layer) {
        for(int i = 0; i < stack.size(); i++) {
            if(layer.getTitle() != stack[i].getTitle()) continue;

            stack.erase(stack.begin() + i);
        }
    }

    void LayerStack::onImGui() {
        for(Layer layer : stack) {
            layer.onImGui();
        }
    }
};