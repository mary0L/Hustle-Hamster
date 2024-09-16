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

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "utils.h"
#include "dailyLog.h"

void testMethod();
/**
 * Method to display the help menu.
 * Will present users with options and the user will select one.
 * The method will then direct user to the selected option.
*/
void helpMenu();

/**
 * Prints a tutorial for the user.
 */
void howToUse();