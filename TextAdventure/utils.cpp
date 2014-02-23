#include <cstring>
#include "utils.hpp"

bool utils::strcmp::operator()(const char* c1, const char* c2) const {
	int result = std::strcmp(c1, c2);
	return result < 0;
}