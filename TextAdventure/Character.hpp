#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

#include <map>
#include "GameObject.hpp"
#include "Item.hpp"
#include "Stats.hpp"
#include "Room.hpp"

class Character :
public GameObject {
typedef std::multimap<const char*, Item*> ItemMap;
typedef ItemMap::value_type ItemMapType;
typedef ItemMap::iterator ItemMapIter;


private:	// Properties
	ItemMap _inventory;
	ItemMap _equipment;
	Stats _baseStats;
	Room* _room;


public:		// Getters and setters
	const ItemMap& inventory() const;
	void setInventory(const ItemMap& newVal);
	const ItemMap& equipment() const;
	void setEquipment(const ItemMap& newVal);
	const Stats& baseStats() const;
	void setBaseStats(const Stats& newVal);
	Room* room() const;
	void setRoom(Room* newVal);


public:		// Constructors, deconstructor, and operators
	Character(void);
	Character(const Character& other);
	virtual ~Character(void);
	Character& operator=(const Character& rhs);


public:		// Methods
	void addItem(const Item& toAdd);
	void removeItem(const char* itemName);
	void equipItem(const char* itemName);
	void unequipItem(const char* itemName);
	void dropItem(const char* itemName);
};

#endif