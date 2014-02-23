#ifndef _CONTROLLER_HPP
#define _CONTROLLER_HPP

#include <map>
#include "GameObject.hpp"
#include "utils.hpp"

class Controller {
typedef void (*Action)(GameObject&, const char*);
typedef std::map<const char*, Action, utils::strcmp> ActionMap;
typedef ActionMap::value_type ActionMapType;


private:	// Properties
	ActionMap _actions;
	GameObject* _target;


public:		// Getters and setters
	const ActionMap& actions() const;
	void setActions(const ActionMap& newVal);
	const GameObject* target() const;
	void setTarget(GameObject* newVal);


public:		// Constructor, deconstructor, and operators
	Controller();
	Controller(const Controller& other);
	~Controller();
	Controller& operator=(const Controller& rhs);


public:		// Methods
	void addAction(const char* actionName, Action action);
	std::string prompt();
};

#endif