#ifndef _ROOM_HPP
#define _ROOM_HPP

#include <map>
#include "GameObject.hpp"
#include "Item.hpp"
#include "utils.hpp"

class Room :
public GameObject {
typedef std::multimap<const char*, Item*, utils::strcmp> ItemMap;
typedef ItemMap::value_type ItemMapType;
typedef ItemMap::iterator ItemMapIter;


private:	// Properties
	Room* _up;
	Room* _down;
	Room* _left;
	Room* _right;
	ItemMap _items;


public:		// Getters and setters
	Room* up() const;
	void setUp(Room* newVal);
	Room* down() const;
	void setDown(Room* newVal);
	Room* left() const;
	void setLeft(Room* newVal);
	Room* right() const;
	void setRight(Room* newVal);
	const ItemMap& items() const;
	void setItems(const ItemMap& newVal);


public:		// Constructor, deconstructor, and operators
	Room(void);
	Room(const Room& other);
	virtual ~Room(void);
	Room& operator=(const Room& rhs);


public:		// Methods
	void addItem(const Item& toAdd);
	Item& removeItem(const char* itemName);
};

#endif