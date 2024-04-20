#include "UUID.h"

#include <random>

namespace Lila {

	static std::random_device device;
	static std::mt19937_64 engine(device());
	static std::uniform_int_distribution<unsigned long long> uniformDist;

	UUID::UUID() : id(uniformDist(engine)) {}

}