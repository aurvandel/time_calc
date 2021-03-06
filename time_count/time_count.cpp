// time_count.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KronosTime.h"


/* In order to maintain consistent time reporting, Kronos rounds clock punch times to the nearest 15‐minute mark.
In order to round to 15 minutes, the actual time punches are rounded on the quarter hour.
Anything within and including 7 minutes is rounded down to the nearest quarter hour. */

void getClockInTime(KronosTime& clock_in) {
	int input_hour, input_minute;
	std::cout << "Enter the hour you clocked in: ";
	std::cin >> input_hour;
	std::cout << "Enter the minutes you clocked in: ";
	std::cin >> input_minute;
	clock_in.setTime(input_hour, input_minute);
}

void getFutureTime(KronosTime& proposed_time) {
	int input_hour, input_minute;
	std::cout << "Enter the hour you will clock out: ";
	std::cin >> input_hour;
	std::cout << "Enter the minutes you will clock out: ";
	std::cin >> input_minute;
	proposed_time.setTime(input_hour, input_minute);
}

void lunch(KronosTime& kt) {
	bool lunch;
	std::string lunch_y_n;
	std::cout << "Did you take a lunch? (y/n) ";
	std::cin >> lunch_y_n;
	if (lunch_y_n == "y") {
		lunch = true;
	}
	else {
		lunch = false;
	}
	kt.setLunch(lunch);
}

int showMenu( std::istream& is ) {
	int choice;
	std::cout << "1 - Check time using current time" << std::endl;
	std::cout << "2 - Time clock calculator" << std::endl;
	is >> choice;
	return choice;
}

int main()
{
	int choice = showMenu(std::cin);
	int keep_working;
	KronosTime current_time, clock_in, hours_worked, future_time;
	getClockInTime(clock_in);
	lunch(clock_in);
	if (choice == 1) {
		hours_worked = current_time - clock_in;
	}
	else if (choice == 2) {
		getFutureTime(future_time);
		hours_worked = future_time - clock_in;
	}
	keep_working = hours_worked.getKeepWorking();
	std::cout << "You've worked " << hours_worked << std::endl;
	std::cout << "Work another " << keep_working << " minutes" << std::endl;

	system("pause");
    return 0;
}

