#include <iostream>
#include "headers.hpp"
#include "controllerActions.hpp"

// Debugging
void controllerActions::setDescription(GameObject& target, const char* arg) {
	target.setDescription(arg);
}


void controllerActions::print(GameObject& target, const char* arg) {
	std::cout << "Name: " << target.name() << "\n";
	std::cout << "Description: " << target.description() << "\n";
}


// Movement
void controllerActions::up(GameObject& target, const char* arg) {
	Character* character = dynamic_cast<Character*>(&target);
	Room* room = character->room()->up();

	if (room) {
		character->setRoom(room);
	}
	else {
		std::cout << "You can not go that way.\n";
	}
}


void controllerActions::down(GameObject& target, const char* arg) {
	Character* character = dynamic_cast<Character*>(&target);
	Room* room = character->room()->down();

	if (room) {
		character->setRoom(room);
	}
	else {
		std::cout << "You can not go that way.\n";
	}
}


void controllerActions::left(GameObject& target, const char* arg) {
	Character* character = dynamic_cast<Character*>(&target);
	Room* room = character->room()->left();

	if (room) {
		character->setRoom(room);
	}
	else {
		std::cout << "You can not go that way.\n";
	}
}


void controllerActions::right(GameObject& target, const char* arg) {
	Character* character = dynamic_cast<Character*>(&target);
	Room* room = character->room()->right();

	if (room) {
		character->setRoom(room);
	}
	else {
		std::cout << "You can not go that way.\n";
	}
}


// Inventory
void controllerActions::pickup(GameObject& target, const char* arg) {

}


void controllerActions::drop(GameObject& target, const char* arg) {

}


void controllerActions::equip(GameObject& target, const char* arg) {

}


void controllerActions::unequip(GameObject& target, const char* arg) {

}


void controllerActions::use(GameObject& target, const char* arg) {

}


// Info
void controllerActions::inventory(GameObject& target, const char* arg) {

}


void controllerActions::inspect(GameObject& target, const char* arg) {

}


void controllerActions::help(GameObject& target, const char* arg) {
	std::cout << "Available actions:\n"
			  << "\tMovement: up, down, left, right\n"
			  << "\tInfo: help, look\n";
}


void controllerActions::look(GameObject& target, const char* arg) {
	Character* character = dynamic_cast<Character*>(&target);
	Room* room = character->room();

	std::cout << "Room name: " << room->name() << "\n"
			  << "Description: " << room->description() << "\n";
}