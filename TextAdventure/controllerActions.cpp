#include <iostream>
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

}


void controllerActions::down(GameObject& target, const char* arg) {

}


void controllerActions::left(GameObject& target, const char* arg) {

}


void controllerActions::right(GameObject& target, const char* arg) {

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

}


void controllerActions::look(GameObject& target, const char* arg) {

}