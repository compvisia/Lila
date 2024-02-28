#include "Lila/Lila.h"
#include "Lila/core/Entry.h"

class EditorApp : public Lila::Application {
public:
    EditorApp() { name = "Editor"; };

    ~EditorApp() {}

    void run() override {
       
    }

};

Lila::Application* Lila::CreateApp() {
    return new EditorApp();
}