#include "Item.hpp"

// Getters and setters
Item::Functionality Item::functionality() const {
	return this->_functionality;
}


void Item::setFunctionality(Item::Functionality newVal) {
	this->_functionality = newVal;
}


// Constructors, deconstructor, and operators
Item::Item(void) :
GameObject(),
_functionality(nullptr) {
	GameObject::GameObject();
}


Item::Item(const Item& other) :
GameObject(other) {
	this->_functionality = other._functionality;
}


Item::~Item(void) {
}


Item& Item::operator=(const Item& rhs) {
	GameObject::operator=(rhs);
	this->_functionality = rhs._functionality;

	return *this;
}


void Item::operator()(GameObject& target) {
	this->_functionality(target);
}