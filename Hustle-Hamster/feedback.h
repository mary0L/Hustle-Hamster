/**
 * @file feedback.h
 * @author Mary O'Leary
 *
 * @brief This file contains methods pertaining to the feedback in response to user input
 *
 * This file has methods triggered after the user has entered their short answer questions, to get a comprehensive overview of their input. 
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "utils.h"
#include "Journal.h"

 /*
 * A method which gives the personal sleep rating and advice on how this might impact wellbeing as well as how to improve
 *
 */
void sleepFeedback();

/*
* A method to go through and check what activities have been completed or not
*
* @param dailyEntry the daily Journal entry
*/
void checkAdvice(Journal& dailyEntry);

/*
* A testing method that will probably become the central method
* 
* @param dailyEntry the daily Journal entry
*/
void hammyEvaluation(Journal& dailyEntry);