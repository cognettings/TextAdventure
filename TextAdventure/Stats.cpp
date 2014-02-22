#include "Stats.hpp"

// Getters and setters
uint Stats::strength() const {
	return this->_strength;
}


void Stats::setStrength(uint newVal) {
	this->_strength = newVal;
}


// Constructors, deconstructor, and operators
Stats::Stats(void) :
_strength(0) {
}


Stats::Stats(const Stats& other) {
	this->_strength = other._strength;
}

	
Stats::~Stats(void) {
}


Stats& Stats::operator=(const Stats& rhs) {
	this->_strength = rhs._strength;

	return *this;
}
