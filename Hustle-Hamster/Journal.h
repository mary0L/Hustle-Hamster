#pragma once
#include "Date.h"
#include <vector>

class Journal {
private:
	Date date;
	int dayRating = 0;
	int sleepRating = 0;
	string mood = "";
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
	* @param date The date to construct the journal for.
	*/
	Journal(const Date &date);

	/**
	* Get the date of this journal.
	*/
	Date getDate();

	/**
	* Get the overall rating of this day.
	*/
	int getDayRating();

	/**
	* Get the rating for the sleep on this day. 
	*/
	int getSleepRating();

	/**
	* Get the mood from this day.
	*/
	string getMood();

	/**
	* Get all of the activities completed on this day.
	*/
	vector<string> getActivities();

	/**
	* Get all of the thoughts provided by Hammy on this day.
	*/
	vector<string> getHammyThoughts();

	/**
	* Get the journal entry from this day. 
	*/
	string getTextEntry();

	/**
	* Set the overall rating for this day. 
	*/
	void setDayRating(int dayRating);

	/**
	* Set the sleep rating for this day.
	*/
	void setSleepRating(int sleepRating);

	/**
	* Set the mood from this day. 
	*/
	void setMood(const string &mood);

	/**
	* Add an activity that was completed on this day. 
	*/
	void addActivity(string activity);

	/**
	* Add a thought shared by Hammy on this day. 
	*/
	void addHammyThoughts(string hammyThought);

	/**
	* Set the text entry for this day. 
	*/
	void setTextEntry(const string &textEntry);
};