#pragma once
#include <string> // Use string object

class Clock
{
	private:
		int hours;
		int minutes;
		int seconds;

	public:
		Clock(int hours = 0, int minutes = 0, int seconds = 0);

		void addHour();
		void addMinute();
		void addSecond();	
		std::string getTime24();
		std::string getTime12();
};

