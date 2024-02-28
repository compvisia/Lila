#include "Lila/Lila.h"

class EditorApp : public Lila::Application {
public:
    EditorApp() { name = "Editor"; };

    void run() override {
        
    }

};

Lila::Application* Lila::CreateApp() {
    return new EditorApp();
}