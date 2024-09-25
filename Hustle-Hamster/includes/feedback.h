/**
 * @file feedback.h
 * @author Mary O'Leary
 *
 * @brief This file contains methods pertaining to the feedback in response to user input
 *
 * This file has methods triggered after the user has entered their short answer questions, to get a comprehensive overview of their input. 
 */

#pragma once

#include "all_includes.h"


/**
* A method to provide motivation and advice in response to incompleted "Go Outside" activity
*
*/
void outsideFeedback();

/**
* A method to provide motivation and advice in response to incompleted "Drink Water" activity
*
*/
void hydrationFeedback();

/**
* A method to provide motivation and advice in response to incompleted "Exercise" activity
*
*/
void exerciseFeedback();

/**
* A method to provide motivation and advice in response to incompleted "Socialise" activity
*
*/
void socialiseFeedback();

/**
* A method to provide motivation and advice in response to the daily sleep rating
*
*/
void sleepFeedback();

/**
* A method to which chooses randomly from either the uncompleted activities or, if none, provides general feedback
*
* @param uncompletedActivities a list of the activities not completed by the user
*/
void activityAdvice(vector<string>& uncompletedActivities);

/**
* A method to go through and check what activities have been completed or not
*
* @param dailyEntry the daily Journal entry
*/
void checkCompletion(Journal& dailyEntry);

/**
* A testing method that will probably become the central method
* 
* @param dailyEntry the daily Journal entry
*/
void hammyEvaluation(Journal& dailyEntry);