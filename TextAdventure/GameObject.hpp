#ifndef _GAME_OBJECT_HPP
#define _GAME_OBJECT_HPP

#include "types.hpp"
#include <string>

class GameObject {
private:	// Properties
	char* _name;
	char* _description;
public:		// Getters and setters
	const char* name() const;
	void setName(const char* newVal);
	const char* description() const;
	void setDescription(const char* newVal);
public:		// Constructors, deconstructor, and operators
	GameObject(void);
	GameObject(const GameObject& other);
	virtual ~GameObject(void);
	GameObject& operator=(const GameObject& rhs);
private:	// Methods
	void _setCStr(char** destination, const char* source);
};

#endif