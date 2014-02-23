#ifndef _CONTROLLER_ACTIONS_HPP
#define _CONTROLLER_ACTIONS_HPP

#include "GameObject.hpp"

namespace controllerActions {
	// Debugging
	void setDescription(GameObject& target, const char* arg);
	void print(GameObject& target, const char* arg);
	
	// Movement
	void up(GameObject& target, const char* arg);
	void down(GameObject& target, const char* arg);
	void left(GameObject& target, const char* arg);
	void right(GameObject& target, const char* arg);
	
	// Inventory
	void pickup(GameObject& target, const char* arg);
	void drop(GameObject& target, const char* arg);
	void equip(GameObject& target, const char* arg);
	void unequip(GameObject& target, const char* arg);
	void use(GameObject& target, const char* arg);

	// Info
	void inventory(GameObject& target, const char* arg);
	void inspect(GameObject& target, const char* arg);
	void help(GameObject& target, const char* arg);
	void look(GameObject& target, const char* arg);
}

#endif