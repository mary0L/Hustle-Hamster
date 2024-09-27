/**
 * @file menuHelp.h
 * @author Katelynn Wink
 * 
 * @brief File containing the menu display functions.
 * 
 * This file contains the menu display functions, so as to not clutter the main file.
 * 
 * @see dailyLog.h
 */

#pragma once

#include "all_includes.h"

/**
 * Method to display the help menu.
*/
void helpMenu();

/**
 * Prints a tutorial for the user.
 */
void howToUse();

/**
 * Lets the user know what the exit button does.
 */
void howToUseExit();

/**
 * How does the help menu work.
 */
void howToUseHowToUse();

/**
 * Prints a tutorial for how to use Daily log.
 */
void howToUseDailyLog();

/**
 * Lets the user know where our data is from.
 */
void whereIsOurDataFrom();

/**
 * Lets the user know where their files are saved..
 */
void whereAreMyFilesSaved();

/**
 * Print the help menu so that hammy will not introduce you to menu everytime. 
*/
void printHelpMenu();