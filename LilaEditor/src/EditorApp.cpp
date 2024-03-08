#define Entry
#include "Lila/Lila.h"

#include "Editor/Editor.h"

class EditorApp : public Lila::Application {
public:
    EditorApp(Lila::ApplicationSpecs specs) { 
        this->specs = specs;
        init();
    }

    void run() override {
        
    }

};

Lila::Application* Lila::CreateApp() {
    Lila::ApplicationSpecs specs;
    specs.name = "EditorApp";

    return new EditorApp(specs);
}