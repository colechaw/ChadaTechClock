/*******************************************************************************
NAME -    Charles Cole

CLASS -   Project 1 CS 210 - Chada Tech Clock 

PURPOSE - Create a clock that can be controlled by user input from menu,
          rendering the output to the console window, accept next command until
          user selects 'exit', then end the program.
********************************************************************************/

#include "Clock.h"
#include <iostream>
#include <string>
#include <cstdlib> // Reference to clear console window between choices

// Function prototypes
void showMenu();
void showClockFace();
int validateInput(int min, int max, std::string prompt);
void initalizeClock();

// Variables
Clock myClock;

int main() {

	// Variables
	int userSelection = 0; // Holds the user's menu selection

	// Start the clock with h:m:s
	initalizeClock();

	// Loop until the user selects 4, exit
	while (userSelection != 4) {

		// ****************** Update display *******************************
		system("cls");
		showClockFace();
		showMenu();
		// ******************************************************************

		// Capture user input throught the validateInput() method
		userSelection = validateInput(1, 4, "Select a choice from the menu: \n");

		// Evaluate user input, call myClock functions
		switch (userSelection) {
			case 1:
				myClock.addHour();
				break;
			case 2: 
				myClock.addMinute();
				break;
			case 3: 
				myClock.addSecond();
				break;
		}
	}
	return 0;
}


// Creates clock object and sets the h/m/s after requesting them
// from user when program starts
void initalizeClock() {

	// Get and validate input
	int hours = validateInput(0, 23, 
		"Please enter the hour\nType a number between 0-23: \n");
	int minutes = validateInput(0, 59, 
		"Please enter the minute\nType a number between  0-59: \n");
	int seconds = validateInput(0, 59, 
		"Please enter the second\nType a number between  0-59: \n");
    
	// Initialize myClock
	myClock = Clock(hours, minutes, seconds);
}


// Asks for and returns choice if passes validation
int validateInput(int min, int max, std::string prompt) {
	
	// Variables
	int input = 0;

	// Loop until conditions met
	while (!input) {

		std::cout << prompt;
		std::cin >> input;

		// Check if they entered a string
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		// Check that input is between min and max to validate
		else if ((input >= min) && (input <= max)) {
			return input;
		}

		// Repeat the loop
		input = 0;
		std::cout << "Invalid choice\n";
	}

	// Should not reach this
	return 9999; // test value
}


// *************************** Update Display from here down ***************************
// Print clock face to console
void showClockFace() {
	std::cout 
	<< "*************************   *************************\n"
	<< "*     12-Hour Clock     *   *     24-Hour Clock     *\n"
	<< "*      "
	<< myClock.getTime12()
	<< "      *   *        "
	<< myClock.getTime24()
	<< "       *\n"
	<< "*************************   *************************\n"
	<< std::endl;
}

// Print menu to console
void showMenu() {
	std::cout
		<< "*************************\n"
		<< "* 1 - Add One Hour      *\n"
		<< "* 2 - Add One Minute    *\n"
		<< "* 3 - Add One Second    *\n"
		<< "* 4 - Exit Program      *\n"
		<< "*************************\n"
		<< std::endl;
}