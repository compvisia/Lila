#include "UUID.h"

#include <random>

namespace Lila {

	static std::random_device device;
	static std::mt19937_64 engine(device());
	static std::uniform_int_distribution<u64> uniformDist;

	UUID::UUID() : id_m(uniformDist(engine)) {}

}