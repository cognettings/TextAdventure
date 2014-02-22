#ifndef _STATS_HPP
#define _STATS_HPP

#include "types.hpp"

/**
 * A stat class to keep track of item or character stats.
 */
class Stats {
private:	// Properties
	uint _strength;
public:		// Getters and setters
	uint strength() const;
	void setStrength(uint newVal);
public:		// Constructors, deconstructor, and operators
	Stats(void);
	Stats(const Stats& other);
	~Stats(void);
	Stats& operator=(const Stats& rhs);
};

#endif