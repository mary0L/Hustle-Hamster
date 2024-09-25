/**
 * @file Journal.h
 * @author Abby Fernandes
 *
 * @brief File containing the class declaration for the Journal class.
 *
 */

#pragma once

#include "all_includes.h"


/**
 * @author Abby Fernandes
 * 
 * This class stores all of the associated information for a single Journal entry.
 * 
 * Such as the daily ratings, moods, date, etc. 
 * 
 */
class Journal {
private:
	Date date;
	int dayRating = 0;
	int sleepRating = 0;
	string mood = "";
	vector<string> activities;
	string textEntry = "";

public:
	/**
	* Default constructor, constructs journal for the current date of the system.
	*/
	Journal();

	/**
	* Construct a journal for the provided date.
	* 
	* @param date The Date to construct the journal for.
	*/
	Journal(const Date &date);

	/**
	* Get the date of this journal.
	* 
	* @return Date of this journal.
	*/
	Date getDate();

	/**
	* Get the overall rating of this day.
	* 
	* @return The day rating for this journal as an integer. 
	*/
	int getDayRating();

	/**
	* Get the rating for the sleep on this day.
	* 
	* @return The sleep rating for this journal as an integer.  
	*/
	int getSleepRating();

	/**
	* Get the mood from this day.
	* 
	* @return The mood for this journal as a string. 
	*/
	string getMood();

	/**
	* Get all of the activities completed on this day.
	* 
	* @return The collection of activities done in this journal. 
	*/
	vector<string> getActivities();

	/**
	* Get the journal entry from this day. 
	* 
	* @return The text entry for this journal as a string. 
	*/
	string getTextEntry();

	/**
	* Set the overall rating for this day. 
	* 
	* @param The rating to set. 
	*/
	void setDayRating(int dayRating);

	/**
	* Set the sleep rating for this day.
	* 
	* @param The rating to set. 
	*/
	void setSleepRating(int sleepRating);

	/**
	* Set the mood from this day. 
	* 
	* @param The mood to set. 
	*/
	void setMood(const string &mood);

	/**
	* Add an activity that was completed on this day. 
	* 
	* @param The activity to add. 
	*/
	void addActivity(string activity);

	/**
	* Set the text entry for this day. 
	* 
	* @param The text entry to add. 
	*/
	void setTextEntry(const string &textEntry);

	/**
	* Checks whether specified activity was recorded for this journal.
	* 
	* @param Activity to check for.
	* @return 1 (true) if the given activity was recorded, 0 (false) otherwise.
	*/
	bool didActivity(const string& activity);
};