#include "headers.hpp"
#include "functionality.hpp"

void testGameObject();
void testStats();
void testItem();

using std::cout;
using std::endl;
using std::cin;

int main() {
	testGameObject();
	testStats();
	testItem();

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
	i.setFunctionality(&functionality::test);

	GameObject g;
	g.setName("John");
	g.setDescription("GDD Student");

	cout << "g:\n" << g.name() << "\n" << g.description() << "\n\n";
	cout << "Test item interaction.\n";
	i(g);
	cout << "g:\n" << g.name() << "\n" << g.description() << "\n\n";

	cin.get();
}