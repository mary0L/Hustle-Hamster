// Comment to test PR

#pragma once

#include <string>
#include <vector>

using namespace std;

class Date {
private:
	int day = 0;
	int month = 0;
	int year = 0;
	int wkDay = 0;

	vector<string> wkDays = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

public:
	/*
	 * Default constructor. Constructs a Date object with the current date of the system.
	 */
	Date();

	/*
	 * Constructor that takes in values to initialise fields.
	 *
	 * @param day The current day of the month (1 - 31).
	 * @param month The current month of the year (1 - 12).
	 * @param year The current year.
	 * @param wkDay The currend day of the week (1 - 7, where 1 is Monday)
	 */
	Date(int day, int month, int year, int wkDay);

	int getDay();

	int getMonth();

	int getYear();

	int getWkDay();

	string getWkDayString();
};