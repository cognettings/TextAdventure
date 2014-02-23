#ifndef _UTILS_HPP
#define _UTILS_HPP

namespace utils {
	// String literal comparison object
	typedef struct {
		bool operator() (const char* c1, const char* c2) const;
	} strcmp;
}

#endif