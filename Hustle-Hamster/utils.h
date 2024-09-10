/**
 * @file utils.h
 * @author Abby Fernandes, Katelynn Wink
 * 
 * @brief File containing utility functions to be used throughout the application.
 * 
 * This file contains several functions, global variables, and preprocessor directives that are necessary for this application, but would clutter up the main file significantly.
 */

#pragma once

#include "Journal.h"
#include "menuHelp.h"
#include "dailyLog.h"
#include <termios.h>

/**
 *  Development Process only so that developers
 *  can use MACOS and Windows
 */
#ifdef _WINDOWS
#define WIN32_LEAN_AND_MEAN // Necessary to remove ambiguity errors caused in windows.h library
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

/* The standard delay used for printing */
extern unsigned int stdDelay;
/* The Inital default activities */
extern vector<string> defaultActivities; 
/* Separator for formatting */
extern char separator[]; 

/**
 * Print the report for the given journal entry.
 *
 * @param journalEntry the daily Journal entry to print
*/
void printReport(Journal &journalEntry);

/**
 * Export the given journal entry to a text file.
 * 
 * @param journalEntry the journal entry to export.
 */
void exportJournal(Journal &journalEntry);

/**
 * Method to type out strings in terminal (animation)
 *
 * @param p string to print
 */
void TYPE(const string& p);

void delay(int time);

/**
 * Method to print Hammy the Hamster Friend.
 */
void printHammy();

/**
 * Prints the menu and calls method based on user input
 * 
 * (enter 0 for devs)
 * 
 * @see menuHelp.h
 */
void menu(); 

void disableInput(void);
void enableInput(void);

void discardInputBuffer(void);
void discardInputLine(void);

void setTermiosBit(int fd, tcflag_t bit, int onElseOff );
void turnEchoOff(void);
void turnEchoOn(void);
void turnCanonOff(void);
void turnCanonOn(void);