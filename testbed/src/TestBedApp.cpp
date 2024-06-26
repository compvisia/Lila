#define Entry
#include <Lila/Lila.h>

#include "Lila/Assets/AssetManager.h"

#include "Platform/OpenGL/OpenGL.h"

class TestEvent : public Lila::Event {};
class TestHandler : public Lila::EventHandler {
public:
    void onEvent(Lila::Event& e) override {
        if(Lila::isIstanceOf<Lila::Event, TestEvent>(&e)) {
            lila_info("TestEvent handled")
        }
    }
};

class TestBedApp : public Lila::Application {
public:
    TestBedApp(std::string name) { name_m = name; }

    void create() override {
        lila_info("Creating Testbed");
    }

    void run() override {
        lila_info("Running Testbed");

        Lila::AssetManager am;
        
        Lila::Asset ass;
        ass.assetId = 10;
        ass.type = Lila::ASSET_TYPE_MATERIAL;
        ass.path = "Lila/assets/template.mat";

        Lila::Shared<Lila::Asset> asset = am.registerAsset(ass);
        
        am.loadAsset(asset->assetId);

        Lila::Shared<Lila::Asset> a = am.getAsset(10);
        
        lila_debug("%d %d %s", a->assetId, a->type, a->path.c_str());
        
        am.unloadAsset(asset->assetId);

        Lila::Shared<Lila::Asset> al = am.getAsset(10);
        
        lila_debug("%d %d %s", al->assetId, al->type, al->path.c_str());

        TestHandler testHandler;
        Lila::EventBus::addHandler(testHandler);

        TestEvent testEvent;
        Lila::EventBus::fireEvent(testEvent);

        Lila::Unique<Lila::Window> window = Lila::makeUnique<Lila::Window>("Window");

        std::vector<f32> vertices = {
             1.0f, -1.0f, -1.0f,
             1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f,  1.0f,
            -1.0f, -1.0f, -1.0f,
             1.0f,  1.0f, -1.0f,
             1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f,  1.0f,
            -1.0f,  1.0f, -1.0f
        };

        std::vector<u32> indices = {
            5, 1, 4,
            5, 4, 8,
            3, 7, 8,
            3, 8, 4,
            2, 6, 3,
            6, 7, 3,
            1, 5, 2,
            5, 6, 2,
            5, 8, 6,
            8, 7, 6,
            1, 2, 3,
            1, 3, 4
        };

        OpenGL::GLGeometry g = OpenGL::GLGeometry(vertices, indices);
        OpenGL::GLShader s = OpenGL::GLShader("Lila/assets/shaders/cube.vert","Lila/assets/shaders/cube.frag");
        
        while(window->isOpen()) {
            window->render();

            s.bind();

            g.render();

            s.unbind();

            window->update();
        }
    }
};

Lila::Shared<Lila::Application> createApplication() {
    return Lila::makeShared<TestBedApp>("TestBed");
}