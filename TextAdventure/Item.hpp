#ifndef _ITEM_HPP
#define _ITEM_HPP

#include "GameObject.hpp"

class Item :
public GameObject {
typedef void (*Functionality)(GameObject&);
private:	// Properties
	Functionality _functionality;
public:		// Getters and setters
	Functionality functionality() const;
	void setFunctionality(Functionality newVal);
public:
	Item(void);
	Item(const Item& other);
	virtual ~Item(void);
	Item& operator=(const Item& rhs);
	void operator()(GameObject& target);
};

#endif