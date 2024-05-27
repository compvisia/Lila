#pragma once

#include "Lila/Core/Logger.h"

#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>

namespace Lila {

	std::string getContents(std::string filePath) {
		std::string contents = "";

		if (!std::filesystem::exists(filePath)) {
			lila_error("Path does not exist. %s/%s", std::filesystem::current_path().c_str(), filePath.c_str());
			return contents;
		}

		std::ifstream file;
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		try {
			file.open(filePath);

			std::stringstream stream;
			stream << file.rdbuf();

			file.close();

			contents = stream.str();
		}
		
		catch (std::ifstream::failure& exception) {
			lila_error("FileUtils.getContents exception %s", exception.what());
		}

		return contents;
	}

}