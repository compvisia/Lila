#pragma once

extern Lila::Application* Lila::CreateApp();

int main(int argc, char** argv) {

	auto app = Lila::CreateApp();

	info("Created Application: %s", app->getName().c_str());

	app->run();
	
	delete app;

	return 0;
}