#pragma once
#include <string> // Use string object

using namespace std; // Shortcut to avoid typing std::

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
		string getTime24();
		string getTime12();
};

