#include "Clock.h" // Reference clock header file
#include <iomanip> // Reference I/O object
#include <sstream> // Reference string stream object

using namespace std; // Shortcut to avoid typing std::

// Constructor
Clock::Clock(int hours, int minutes, int seconds) {
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

void Clock::addHour() {
		// add one hour
		hours ++;
		// if the hour count = 24, set hours to 0
		if (hours == 24) {
			hours = 0;
		}
	}

	void Clock::addMinute() {
		// add one minute
		minutes ++;
		if (minutes == 60) {
			minutes = 0;
			// if the minute count = 60, add an hour and set minutes to 0
			addHour();
		}
	}

	void Clock::addSecond() {
		// add one second
		seconds ++;
		// if the second count = 60, add a minute and set seconds to 0
		if (seconds == 60) {
			seconds = 0;
			addMinute();
		}
	}

	string Clock::getTime24() {
		// Variables
		ostringstream result;

		// Compose result
		result << setfill('0')
			<< setw(2) << hours << ":"
			<< setw(2) << minutes << ":"
			<< setw(2) << seconds;

		return result.str();
	}

	string Clock::getTime12() {
		// Variables
		int tempHour = hours;
		string amPm = "AM";
		ostringstream result;

		// Check to see if before or after noon
		if (hours >= 12) {
			amPm = "PM"; // Change to PM for afternoon values
			tempHour = hours - 12; // Subtract 12 from afternoon values
		}

		// Compose result
		result << setfill('0')
			<< setw(2) << tempHour << ":"
			<< setw(2) << minutes << ":"
			<< setw(2) << seconds << " " << amPm;

		return result.str();
	}


