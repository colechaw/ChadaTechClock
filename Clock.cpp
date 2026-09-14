/*******************************************************************************
NAME -    Charles Cole

CLASS -   Project 1 CS 210 - Chada Tech Clock

PURPOSE - Clock object to be used in the main.cpp, isolates the functions and
          hides them from the main applications.
********************************************************************************/

#include "Clock.h"
#include <iomanip>
#include <sstream>

// Constructor
Clock::Clock(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}


// Function to increase clock by one hour
void Clock::addHour() {
	hours ++;
	
	// Check rollover
	if (hours > 23) {
		hours = 0;
	}
}


// Function to increase clock by one minute
void Clock::addMinute() {
	minutes ++;

	// Check rollover
	if (minutes > 59) {
		minutes = 0;
		addHour();
	}
}


// Function to increase clock by one second
void Clock::addSecond() {
	seconds ++;

	// Check rollover
	if (seconds > 59) {
		seconds = 0;
		addMinute();
	}
}


// Return time in 24-hour format, No AM / PM, set to empty string
std::string Clock::getTime24() {

	// Send to composeResult() for formatting, return result
	return composeResult(hours, minutes, seconds, ""); 
}


// Return time in 12-hour format
std::string Clock::getTime12() {

	int tempHour = hours;
	std::string amPm = " AM";

	// Set AM / PM
	if (hours > 11) {
		amPm = " PM";
	}

	// Get the hour, 12:00 will give us a 00
	tempHour = hours % 12;

	// Handle 12:00 pm 
	if (tempHour == 0) {
		tempHour = 12;
	}

    // Send to composeResult() for formatting, return result
	return composeResult(tempHour, minutes, seconds, amPm);
}


// Compose requested format, (hh:mm:ss AM/PM)
std::string Clock::composeResult(int hours, int minutes, int seconds, std::string prefix) {
	std::ostringstream result;

	result << std::setfill('0')
		<< std::setw(2) << hours << ":" 
		<< std::setw(2) << minutes << ":"
		<< std::setw(2) << seconds 
						<< prefix; // Followed by AM / PM / nothing

	return result.str();
}


