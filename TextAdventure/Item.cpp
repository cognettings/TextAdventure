#include "Item.hpp"

// Getters and setters
Item::Action Item::action() const {
	return this->_action;
}


void Item::setAction(Item::Action newVal) {
	this->_action = newVal;
}


// Constructors, deconstructor, and operators
Item::Item(void) :
GameObject(),
_action(nullptr) {
	GameObject::GameObject();
}


Item::Item(const Item& other) :
GameObject(other) {
	this->_action = other._action;
}


Item::~Item(void) {
}


Item& Item::operator=(const Item& rhs) {
	GameObject::operator=(rhs);
	this->_action = rhs._action;

	return *this;
}


void Item::operator()(GameObject& target) {
	this->_action(target);
}