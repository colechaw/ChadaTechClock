/*******************************************************************************
NAME -    Charles Cole

CLASS -   Project 1 CS 210 - Chada Tech Clock

PURPOSE - *.h file for clock.cpp, it defines the variables and methods the object
          will use.
********************************************************************************/

#pragma once
#include <string>

class Clock
{
	private:
		int hours;
		int minutes;
		int seconds;
		std::string composeResult(int hours, int minutes, int seconds, std::string prefix);

	public:
		Clock(int hours = 0, int minutes = 0, int seconds = 0);

		void addHour();
		void addMinute();
		void addSecond();	
		std::string getTime24();
		std::string getTime12();
};

