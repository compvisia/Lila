#pragma once

namespace Lila {
    
    class Layer {
    public:
        Layer(const char* title) { m_title = title; };

        virtual void onImGui() {};



        const char* getTitle() { return m_title; }
    private:
        const char* m_title;
    };

}
