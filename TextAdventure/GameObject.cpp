#include "GameObject.hpp"

// Getters and setters
const char* GameObject::name() const {
	return this->_name;
}


void GameObject::setName(const char* newVal) {
	_setCStr(&this->_name, newVal);
}


const char* GameObject::description() const {
	return this->_description;
}


void GameObject::setDescription(const char* newVal) {
	_setCStr(&this->_description, newVal);
}


// Constructors, deconstructor, and operators
GameObject::GameObject(void) :
_name(nullptr),
_description(nullptr) {
}


GameObject::GameObject(const GameObject& other) {
	_setCStr(&this->_name, other._name);
	_setCStr(&this->_description, other._description);
}


GameObject::~GameObject(void) {
	if (this->_name) {
		delete[] this->_name;
	}

	if (this->_description) {
		delete[] this->_description;
	}
}


GameObject& GameObject::operator=(const GameObject& rhs) {
	_setCStr(&this->_name, rhs._name);
	_setCStr(&this->_description, rhs._description);

	return *this;
}


// Methods
void GameObject::_setCStr(char** destination, const char* source) {
	uint sLen = strlen(source) + 1;		// Length of source including null-terminator

	// If destination has been allocated
	if (*destination) {	
		uint dLen = strlen(*destination);	// Length of destination
		
		// Resize destination if necessary
		if (dLen < sLen) {
			delete[] *destination;
			*destination = new char[sLen];
		}
	}
	else {
		*destination = new char[sLen];
	}

	// Copy source into destination
	strcpy_s(*destination, sLen, source);
}