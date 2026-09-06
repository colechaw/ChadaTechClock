#include "Clock.h" // Reference clock header file
#include <iostream> // Reference input/output stream library
#include <string> // Bring string in to use with my functions
#include <cstdlib> // Reference to clear console window between choices

using namespace std; // Shortcut to avoid tying std::

// Function prototypes
string drawMenu();
string clockFace();
void initalizeClock();

// Variables
int userSelection; // Holds the user's menu selection
Clock myClock; // Create instance of Clock class
int hours;
int minutes;
int seconds;

int main() {

	initalizeClock(); // Call function to initialize clock

	while (userSelection != 4) {
		system("cls"); // Clear console window

		cout << clockFace() << endl; // Call function to draw clock
		cout << drawMenu() << endl; // Call function to draw menu

		cin >> userSelection; // Capture user input

		switch (userSelection) { // Evaluate user input
			case 1:
				myClock.addHour(); // addHour() function of myClock
				break;
			case 2: 
				myClock.addMinute(); // addMinute() function of myClock
				break;
			case 3: 
				myClock.addSecond(); // addSecond() function of myClock
				break;
		}
	}
	return 0;
}

// Function definitions

void initalizeClock() {
	cout << "Enter the hours 0-23:"; // Ask for hours
	cin >> hours; // Get hours
	cout << "Enter the minutes 0-59:"; // Ask for minutes
	cin >> minutes; // Get minutes
	cout << "Enter the seconds 0-59:"; // Ask for seconds
	cin >> seconds; // Get seconds

	// Initialize myClock with user input
	myClock = Clock(hours, minutes, seconds); 
}

// Print clock face to console
string clockFace() { 
	string result = "*************************   *************************\n";
	result += "*     12-Hour Clock     *   *     24-Hour Clock     *\n";
	result += "*      ";
	result += myClock.getTime12();
	result += "      *   *        ";
	result += myClock.getTime24();
	result += "       *\n";
	result += "*************************   *************************\n";
	return result;
}

// Print menu to console
string drawMenu() {
	string result = "*************************\n";
	result += "* 1. Add One Hour       *\n";
	result += "* 2. Add One Minute     *\n";
	result += "* 3. Add One Second     *\n";
	result += "* 4. Exit Program       *\n";
	result += "*************************\n";
	return result;
}