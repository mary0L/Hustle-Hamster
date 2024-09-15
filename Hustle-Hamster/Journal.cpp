#include "Journal.h"

Journal:: Journal() {
	date = Date();
}

Journal::Journal(const Date &date) {
	this->date = date;
}

Date Journal::getDate() {
	return this->date;
}

int Journal::getDayRating() {
	return this->dayRating;
}

int Journal::getSleepRating() {
	return this->sleepRating;
}

string Journal::getMood() {
	return this->mood;
}

vector<string> Journal::getActivities() {
	return this->activities;
}


string Journal::getTextEntry() {
	return this->textEntry;
}

void Journal::setDayRating(int dayRating) {
	this->dayRating = dayRating;
}

void Journal::setSleepRating(int sleepRating) {
	this->sleepRating = sleepRating;
}

void Journal::setMood(const string &mood) {
	this->mood = mood;
}

void Journal::addActivity(string activity) {
	this->activities.push_back(activity);
}

void Journal::setTextEntry(const string &textEntry) {
	this->textEntry = textEntry;
}

bool Journal::didActivity(const string& activity) {
	vector<string>::iterator start = this->activities.begin();
	vector<string>::iterator end = this->activities.end();

	vector<string>::iterator it = find(start, end, activity);

	if (it != end) {
		return true;
	}
	else {
		return false;
	}
}