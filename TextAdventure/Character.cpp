#include "Character.hpp"
#include "EquipItem.hpp"

// Getters and setters
const Character::ItemMap& Character::inventory() const {
	return this->_inventory;
}


void Character::setInventory(const ItemMap& newVal) {
	this->_inventory = newVal;
}


const Character::ItemMap& Character::equipment() const {
	return this->_equipment;
}


void Character::setEquipment(const ItemMap& newVal) {
	this->_equipment = newVal;
}


const Stats& Character::baseStats() const {
	return this->_baseStats;
}


void Character::setBaseStats(const Stats& newVal) {
	this->_baseStats = newVal;
}


Room* Character::room() const {
	return this->_room;
}


void Character::setRoom(Room* newVal) {
	this->_room = newVal;
}


// Constructors, deconstructor, and operators
Character::Character(void) {
	this->_room = nullptr;
}


Character::Character(const Character& other) {
	this->_inventory = other._inventory;
	this->_equipment = other._equipment;
	this->_baseStats = other._baseStats;
	this->_room = other._room;
}


Character::~Character(void) {
}


Character& Character::operator=(const Character& rhs) {
	this->_inventory = rhs._inventory;
	this->_equipment = rhs._equipment;
	this->_baseStats = rhs._baseStats;
	this->_room = rhs._room;

	return *this;
}

// Methods
void Character::addItem(const Item& toAdd) {
	Item* newItem = new Item;
	*newItem = toAdd;

	this->_inventory.insert(ItemMapType(newItem->name(), newItem));
}


void Character::removeItem(const char* itemName) {
	Item itemCopy;
	ItemMapIter pos = this->_inventory.find(itemName);

	// If the specified item exists in this Room, then remove and return it
	if (pos != this->_inventory.end()) {
		itemCopy = *(pos->second);
		this->_inventory.erase(pos);
	}
	else {
		throw (std::out_of_range("I don't see the \"" + std::string(itemName) + "\" in your inventory."));
	}
}


void Character::equipItem(const char* itemName) {
	//EquipItem* item = new 
	//ItemMapIter pos = this->_inventory.find(itemName);

	//// If this Character has the specified item, then equip it
	//if (pos != this->_inventory.end()) {

	//}
}


void Character::unequipItem(const char* itemName) {

}


void Character::dropItem(const char* itemName) {

}

