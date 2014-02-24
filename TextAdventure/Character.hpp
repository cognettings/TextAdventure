#ifndef _CHARACTER_HPP
#define _CHARACTER_HPP

#include <map>
#include "GameObject.hpp"
#include "Item.hpp"
#include "Stats.hpp"
#include "Room.hpp"

class Character :
public GameObject {
typedef std::map<const char*, Item*> ItemMap;


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
	const Room* room() const;
	void setRoom(Room* newVal);


public:		// Constructors, deconstructor, and operators
	Character(void);
	Character(const Character& other);
	virtual ~Character(void);
	Character& operator=(const Character& rhs);
};

#endif