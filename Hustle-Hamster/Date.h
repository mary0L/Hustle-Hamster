#pragma once

#include <string>
#include <vector>

using namespace std;

/**
 * @author Abby Fernandes
 * 
* Class for storing dates.
* 
* This class is used to make date handling throughout the application simpler by abstracting c++ date mechanisms. 
* 
*/
class Date {
private:
	int day = 0;
	int month = 0;
	int year = 0;
	int wkDay = 0;

	vector<string> wkDays = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	vector<string> monthNames = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

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
	 * @param wkDay The current day of the week (1 - 7, where 1 is Monday)
	 */
	Date(int day, int month, int year, int wkDay);

	/**
	* Get the day of the month from this Date object as an integer (1 - 31).
	* 
	* @return Day of the month as an integer.
	*/
	int getDay();

	/**
	 * Get the month from this Date object as an integer (1 - 12).
	 * 
	 * @return Month as an integer.
	 */
	int getMonth();

	/**
	 * Get the year from this Date object as an integer.
	 * 
	 * @return Year as an integer. 
	 */
	int getYear();

	/** 
	 * Get the day of the week from this Date object as an integer (1 - 7, where 1 is Monday).
	 * 
	 * @return Day of the week as an integer.
	 */
	int getWkDay();

	/** 
	 * Get the day of the week from this Date object as a string (e.g. Monday).
	 * 
	 * @return Day of the week as a string.
	 */
	string getWkDayString();

	/** 
	 * Get the month from this Date object as a string (e.g. January).
	 * 
	 * @return Month of the week as a string.
	 */
	string getMonthName();
};