#include <stdio.h>
#include <cstring>
#include <sstream>
#include "headers.hpp"

void testGameObject();
void testStats();
void testItem();
void testController();
void testCharacter();
void gameLoop();

using std::cout;
using std::endl;
using std::cin;

int main() {
	/*testGameObject();
	testStats();
	testItem();
	testController();
	testCharacter();*/

	gameLoop();

	cout << "Press enter to close.\n";
	cin.get();
	return 0;
}


void testGameObject() {
	GameObject g;
	GameObject g2;

	// Setters
	g.setName("First");
	g.setDescription("That annoying guy that always posts, \"First!\"");

	// Copy assignment
	g2 = g;
	g2.setDescription("The second to be created.");

	// Copy constructor
	GameObject g3(g2);
	g3.setDescription("The youngest.");

	// Getters
	cout << "Setters and getters, constructor, copy constructor, copy assignment.\n";
	cout << "g:\n" << g.name() << "\n" << g.description() << endl << endl;
	cout << "g2:\n" << g2.name() << "\n" << g2.description() << endl << endl;
	cout << "g3:\n" << g3.name() << "\n" << g3.description() << endl << endl;
	
	cout << "Name change.\n";
	g.setName("SOMETHING INCREDIBLY LONG AND UNPRONOUNCABLE");
	cout << "g:\n" << g.name() << "\n" << g.description() << endl << endl;

	cin.get();
}


void testStats() {
	Stats s;
	Stats s2;

	// Setters
	s.setStrength(1);
	
	// Copy assignment
	s2 = s;

	// Copy constructor
	Stats s3(s2);

	// Getters
	cout << "s:\n" << "Strength: " << s.strength() << "\n\n";
	cout << "s2:\n" << "Strength: " << s2.strength() << "\n\n";
	cout << "s3:\n" << "Strength: " << s3.strength() << "\n\n";

	cin.get();
}


void testItem() {
	Item i;
	i.setAction(&itemActions::test);
	
	GameObject g;
	g.setName("John");
	g.setDescription("GDD Student");

	cout << "g:\n" << g.name() << "\n" << g.description() << "\n\n";
	cout << "Test item interaction.\n";
	i(g);
	cout << "g:\n" << g.name() << "\n" << g.description() << "\n\n";

	cin.get();
}


void testController() {
	GameObject g;
	g.setName("John");
	g.setDescription("A boring individual.");

	Controller c;
	c.setTarget(&g);
	c.addAction("setdescription", controllerActions::setDescription);
	c.addAction("print", controllerActions::print);

	while (c.prompt() != "quit"){}
}

void testCharacter() {
	Character c;
	c.setName("John");
}

void gameLoop() {
	// Set up the rooms
	Room up;
	up.setName("The North Pole");
	up.setDescription("The northern-most reaches of the land. It's very chilly up here");
	Room down;
	down.setName("The Deep South");
	down.setDescription("The southern peaks are very chilly.");
	Room left;
	left.setName("The Democracy");
	left.setDescription("Ugh, politics...");
	Room right;
	left.setName("The Republic");
	right.setDescription("Ugh, politics...");
	Room center;
	center.setName("Beginner's Palace");
	center.setDescription("A great place for the newbs.");
	center.setUp(&up);
	center.setDown(&down);
	center.setLeft(&left);
	center.setRight(&right);

	// Set up the character
	Character character;
	character.setName("Adventurer");
	character.setDescription("The soon-to-be savior of the world.");
	character.setRoom(&center);

	// Set up the controller
	Controller controller;
	controller.setTarget(&character);
	controller.addAction("up", controllerActions::up);
	controller.addAction("down", controllerActions::down);
	controller.addAction("left", controllerActions::left);
	controller.addAction("right", controllerActions::right);
	controller.addAction("help", controllerActions::help);
	controller.addAction("look", controllerActions::look);


	// Game loop
	cout << "Welcome! Type help for commands.\n\n";
	while (controller.prompt() != "quit"){}
	cout << "\nThe adventure has ended.\n";
}