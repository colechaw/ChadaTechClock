/*******************************************************************************
NAME -    Charles Cole

CLASS -   Project 1 CS 210 - Chada Tech Clock

PURPOSE - Clock object to be used in the main.cpp, isolates the functions and
          hides them from the main applications.
*********************************************************************************/

#include "Clock.h" // Reference Clock header file
#include <iomanip> // We will use std::setfill(), ect from Standard library
#include <sstream> // We will use ostringstream from Standard library

// Constructor
Clock::Clock(int hours, int minutes, int seconds) {
	this->hours = hours; // set hours variable
	this->minutes = minutes; // set minutes variable
	this->seconds = seconds; // set seconds varialbe
}

// Function to increase clock by one hour
void Clock::addHour() {
		hours ++; // Add one hour

		// If hours = 24, roll hours back to 0
		if (hours == 24) {
			hours = 0;
		}
	}

// Function to increase clock by one minute
void Clock::addMinute() {
	minutes ++; // Add one minute

	// If minutes = 60, roll back to 0 and call addHour()
	if (minutes == 60) {
		minutes = 0;
		addHour(); // This should be handled in addHour()
	}
}

// Function to increase clock by one second
void Clock::addSecond() {
	seconds ++; // Add one second

	// If the second count = 60, roll seconds to 0 and call addMinute()
	if (seconds == 60) {
		seconds = 0;
		addMinute(); // This function should be handled in addMinute()
	}
}


std::string Clock::getTime24() {
	return composeResult(hours, minutes, seconds, "");
}

std::string Clock::getTime12() {
	int tempHour = hours; // Allows for manipulation of hours without disturbing clock hours variable
	std::string amPm = " AM"; // Placeholder for AM / PM, set to AM
	std::ostringstream result;  // Create ostringstream variable

	// Check to see if before or after noon
	if (hours >= 12) {
		amPm = " PM"; // Change to PM for afternoon values
		tempHour = hours - 12; // Subtract 12 from afternoon values
	}

	return composeResult(tempHour, minutes, seconds, amPm);
}

std::string Clock::composeResult(int hours, int minutes, int seconds, std::string prefix) {
	std::ostringstream result;  // Create ostringstream variable

	// Compose requested format, (hh:mm:ss AM/PM)
	result << std::setfill('0')
		<< std::setw(2) << hours << ":"
		<< std::setw(2) << minutes << ":"
		<< std::setw(2) << seconds << prefix;

	return result.str(); // Return as string
}


