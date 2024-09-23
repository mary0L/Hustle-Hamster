#include <ctime>
#include "all_includes.h"

using namespace std;

Date::Date() {
	time_t now = time(0);

	struct tm date = *localtime(&now);

	day = date.tm_mday;
	month = date.tm_mon + 1;
	year = date.tm_year + 1900;
	wkDay = date.tm_wday + 1;
	}

Date::Date(int day, int month, int year, int wkDay) {
	this->day = day;
	this->month = month;
	this->year = year;
	this->wkDay = wkDay;
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

int Date::getWkDay() {
	return wkDay;
}

string Date::getWkDayString() {
	return wkDays[wkDay - 1];
}

string Date::getMonthName() {
	return monthNames[month - 1];
}