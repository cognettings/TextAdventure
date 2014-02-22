#ifndef _FUNCTIONALITY_HPP
#define _FUNCTIONALITY_HPP

#include "headers.hpp"

namespace functionality {
	typedef void (*Functionality)(GameObject&);

	void test(GameObject& target);
}

#endif