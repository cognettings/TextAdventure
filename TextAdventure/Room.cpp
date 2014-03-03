#include <map>
#include "Room.hpp"

// Getters and setters
Room* Room::up() const {
	return this->_up;
}


void Room::setUp(Room* newVal) {
	this->_up = newVal;
	newVal->_down = this;
}


Room* Room::down() const {
	return this->_down;
}


void Room::setDown(Room* newVal) {
	this->_down = newVal;
	newVal->_up = this;
}


Room* Room::left() const {
	return this->_left;
}


void Room::setLeft(Room* newVal) {
	this->_left = newVal;
	newVal->_right = this;
}


Room* Room::right() const {
	return this->_right;
}


void Room::setRight(Room* newVal) {
	this->_right = newVal;
	newVal->_left = this;
}


const Room::ItemMap& Room::items() const {
	return this->_items;
}


void Room::setItems(const ItemMap& newVal) {
	this->_items = newVal;
}


// Constructor, deconstructor, and operators
Room::Room(void) :
_up(nullptr),
_down(nullptr),
_left(nullptr),
_right(nullptr) {
}


Room::Room(const Room& other) {
	this->_up = other._up;
	this->_down = other._down;
	this->_left = other._left;
	this->_right = other._right;
	this->_items = other._items;
}


Room::~Room(void) {
}


Room& Room::operator=(const Room& rhs) {
	this->_up = rhs._up;
	this->_down = rhs._down;
	this->_left = rhs._left;
	this->_right = rhs._right;
	this->_items = rhs._items;

	return *this;
}


// Methods
void Room::addItem(const Item& toAdd) {
	Item* newItem = new Item;
	*newItem = toAdd;

	this->_items.insert(ItemMapType(newItem->name(), newItem));
}


Item& Room::removeItem(const char* itemName) {
	Item itemCopy;
	ItemMapIter pos = this->_items.find(itemName);

	// If the specified item exists in this Room, then remove and return it
	if (pos != this->_items.end()) {
		itemCopy = *(pos->second);
		this->_items.erase(pos);
	}
	else {
		throw (std::out_of_range("I don't see the \"" + std::string(itemName) + "\" in this room."));
	}

	return std::move(itemCopy);
}

