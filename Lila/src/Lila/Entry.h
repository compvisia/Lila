#pragma once

#ifdef Entry

extern Lila::Application* Lila::CreateApp();

int main(int argc, char** argv) {
	lila_trace("Getting system information");

#ifdef __WIN64
	lila_info("Operating System: Windows 64-bit")
#elif defined(_WIN32) || defined(__CYGWIN__)
	lila_info("Operating System: Windows 32-bit")
#elif defined(__APPLE__)
	lila_info("Operating System: MacOS X")
#elif defined(__ANDROID__)
	lila_info("Operating System: Android")
#elif defined(__linux__)
	lila_info("Operating System: Linux")
#elif defined(__FreeBSD__)
	lila_info("Operating System: FreeBSD")
#elif defined(__unix__)
	lila_info("Operating System: Unix")
#else
	warn("Failed to identify Operating System")
#endif

#ifdef __cplusplus
	lila_info("C++ version: %ld", __cplusplus);
#else
	warn("Failed identify C++ version");
#endif

#ifdef _MSC_VER
	lila_info("MSVC version: %d", _MSC_VER);
#elif defined(__GNUC__)
	lila_info("GNU g++ version: %d.%d.%d", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif defined(__clang__)
	lila_info("LLVM clang version: %d.%d.%d", __clang_major__, __clang_minor__, __clang_patchlevel__)
#else
	warn("Failed identify C++ compiler");
#endif


	lila_trace("Creating Application");
	auto app = Lila::CreateApp();
	std::string appName = app->getSpecs().name;
	lila_info("Created Application: %s", appName.c_str());

	app->run();
	
	delete app;
	lila_info("Deleted Application: %s", appName.c_str());
	
	return 0;
}

#endif