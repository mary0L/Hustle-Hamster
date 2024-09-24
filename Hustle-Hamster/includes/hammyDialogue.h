/**
 * @file hammyDialogue.h
 * @author Katie Wink
 *
 * @brief File containing different hammy dialogue and responses
 *
 */

#pragma once

#include <vector>
#include "utils.h"

/* Vector with all responses to user selecting daily log */
extern vector<string> dailyLogR;

/* Vector with all questions for daily rating */
extern vector<string> dailyRatingQ;

/* Vector with all questions for sleep rating */
extern vector<string> sleepRatingQ;

/* Vector with all questions for mood */
extern vector<string> moodQ;

/* Vector with all responses to user selecting exit */
extern vector<string> exitResponses;

/* Rating system for day rating and sleep rating */
extern string ratingSystem;