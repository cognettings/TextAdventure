#include "Controller.hpp"
#include <iostream>

// Getters and setters
const Controller::ActionMap& Controller::actions() const {
	return this->_actions;
}


void Controller::setActions(const ActionMap& newVal) {
	this->_actions = newVal;
}


const GameObject* Controller::target() const {
	return this->_target;
}


void Controller::setTarget(GameObject* newVal) {
	this->_target = newVal;
}


// Constructor, deconstructor, and operators
Controller::Controller() {
	_target = nullptr;
}


Controller::Controller(const Controller& other) {
	this->_actions = other._actions;
	this->_target = other._target;
}


Controller::~Controller() {
}


Controller& Controller::operator=(const Controller& rhs) {
	this->_actions = rhs._actions;
	this->_target = rhs._target;

	return *this;
}


// Methods
void Controller::addAction(const char* actionName, Action action) {
	this->_actions.insert(ActionMapType(actionName, action));
}


std::string Controller::prompt() {
	std::string input;				// User input from console
	std::string requestedAction;	// First word from input
	std::string requestedArgs;		// Rest of words from input
	size_t endAction;				// Location of the space between first and rest of words
	Action action;					// The function received from Controller actions

	std::cout << "Prompt: ";
	std::getline(std::cin, input);

	// Convert input to lower case
	for (size_t i = 0; i < input.length(); ++i) {
		char& current = input[i];
		if (current >= 'A' && current <= 'Z') {
			current += 'a' - 'A';
		}
	}

	endAction = input.find(" ", 0);
	
	// If user provided only one word, then don't check for more
	if (endAction == std::string::npos) {
		requestedAction = input;
		requestedArgs = "";
	}
	// Else parse rest of input
	else {
		requestedAction = input.substr(0, endAction);
		requestedArgs = input.substr(endAction + 1, input.length());
	}

	// As long as user doesn't submit 'quit'
	if (requestedAction != "quit") {
		try {
			// Get the associated action and perfom it on this Controller's target
			action = this->_actions.at(requestedAction.c_str());
			action(*(this->_target), requestedArgs.c_str());
		}
		catch (std::exception e) {
			// No function has been associated with the user's requested action
			std::cout << "Invalid input.\n";
		}

		std::cout << "\n";
	}

	return requestedAction;
}