#pragma once
#include "Date.h"
#include <vector>

class Journal {
private:
	Date date;
	int dayRating = 0;
	int sleepRating = 0;
	int moodRating = 0;
	vector<string> activities;
	vector<string> hammyThoughts;
	string textEntry = "";

public:
	/**
	* Default constructor, constructs journal for the current date.
	*/
	Journal();

	/**
	* Construct a journal for the provided date.
	* 
	* @param date The date to construct the journal for
	*/
	Journal(Date date);

	Date getDate();

	int getDayRating();

	int getSleepRating();

	int getMoodRating();

	vector<string> getActivities();

	vector<string> getHammyThoughts();

	string getTextEntry();

	void setDayRating(int dayRating);

	void setSleepRating(int sleepRating);

	void getMoodRating(int moodRating);

	void addActivity(string activity);



};