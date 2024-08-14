#include "Journal.h"

Journal:: Journal() {
	date = Date();
}

Journal::Journal(Date date) {
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

vector<string> Journal::getHammyThoughts() {
	return this->hammyThoughts;
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

void Journal::setMood(string mood) {
	this->mood = mood;
}

void Journal::addActivity(string activity) {
	this->activities.push_back(activity);
}

void Journal::addHammyThoughts(string hammyThought) {
	this->hammyThoughts.push_back(hammyThought);
}

void Journal::setTextEntry(string textEntry) {
	this->textEntry = textEntry;
}