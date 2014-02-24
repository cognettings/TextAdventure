#include "Character.hpp"

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


const Room* Character::room() const {
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