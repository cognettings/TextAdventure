#ifndef _ITEM_HPP
#define _ITEM_HPP

#include "GameObject.hpp"

class Item :
public GameObject {
typedef void (*Action)(GameObject&);


private:	// Properties
	Action _action;


public:		// Getters and setters
	Action action() const;
	void setAction(Action newVal);


public:		// Constructor, deconstructor, and operators
	Item(void);
	Item(const Item& other);
	virtual ~Item(void);
	Item& operator=(const Item& rhs);
	void operator()(GameObject& target);
};

#endif