#pragma once

extern Lila::Application* Lila::CreateApp();

int main(int argc, char** argv) {

	auto app = Lila::CreateApp();
	std::string appName = app->getName();
	info("Created Application: %s", appName.c_str());

	app->run();
	
	delete app;
	info("Deleted Application: %s", appName.c_str());
	
	return 0;
}