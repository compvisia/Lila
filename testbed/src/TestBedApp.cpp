#define Entry
#include <Lila/Lila.h>

class TestBedApp : public Lila::Application {
public:
    TestBedApp(std::string name) { name_m = name; }

    void create() override {
        lila_info("Creating Testbed");
    }

    void run() override {
        lila_info("Running Testbed");
    }


};

Lila::Shared<Lila::Application> createApplication() {
    return Lila::makeShared<TestBedApp>("TestBed");
}