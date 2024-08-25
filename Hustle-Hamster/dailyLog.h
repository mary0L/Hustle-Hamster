/**
 * @file dailyLog.h
 * @author Katelynn Wink
 * 
 * @brief File containing the daily log functions.
 * 
 * This file contains the  daily log  functions triggered once user selects daily log, so as to not clutter the main file.
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

#include "utils.h"
#include "Journal.h"


/**
 * Method to ask and set the users daily rating
 * 
 * @param dailyEntry the daily Journal entry
*/
void dailyRating(Journal &dailyEntry);

/**
 * Method to ask and set the users sleep rating
 * 
 * @param dailyEntry the daily Journal entry
*/
void sleepRating(Journal &dailyEntry);

/**
 * Method to ask and store users mood rating
 * 
 * @param dailyEntry the daily Journal entry
*/
void moodRating(Journal &dailyEntry);

/**
 * Method to ask the user if they performed an activity
 * Then stores if they have done the activity
 * 
 * @param activity the activity hammy asks user if they performed
 * @param dailyEntry the daily Journal entry
*/
void didActivity(const string &activity, Journal &dailyEntry);

/**
 * Runs through methods to complete the daily log
*/
int dailyLog();