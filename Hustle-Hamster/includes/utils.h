/**
 * @file utils.h
 * @author Abby Fernandes, Katelynn Wink
 * 
 * @brief File containing utility functions to be used throughout the application.
 * 
 * This file contains several functions, global variables, and preprocessor directives that are necessary for this application, but would clutter up the main file significantly.
 */

#pragma once

#include <fstream>
#include <limits>
#include <random>
#include <sys/stat.h>


#include "all_includes.h"

/**
 *  Development Process only so that developers
 *  can use MACOS and Windows
 */
#if defined(_WIN32) || defined(_WINDOWS)
#define WIN32_LEAN_AND_MEAN // Necessary to remove ambiguity errors caused in windows.h library
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
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

/**
 * Get the desktop path of the current user. 
 * 
 * @return The desktop path of the current use. Will throw an exception if there is an issue with obtaining the path.
 */
string getDesktopPath();


/////////////////////////////////
//Code From Stacknoverflow
//"https://stackoverflow.com/questions/38931856/disallow-input-at-certain-times"/>

/**
 * Disables input
*/
void disableInput(void);

/**
 * Enables input
*/
void enableInput(void);

/**
 * Discards the last line that was input
*/
void discardInputLine(void);

#if defined(_WIN32) || defined(_WINDOWS)

/** 
 * Sets console mode
 * 
 * @param bit console mode flag to control behaviour
 * @param onElseOff boolean, off or on
*/
void setConsoleMode(DWORD bit, bool onElseOff);

/** 
 * Discard the input buffer that currently exists 
 * 
*/
void discardInputBuffer(); 

#else
/**
 * Sets terminal settings
 * 
 * @param fd the terminal that we are configuring
 * @param bit flag to change to off or on
 * @param onElseOff if flag is on otherwise off
*/
void setTermiosBit(int fd, tcflag_t bit, int onElseOff );

/**
 * Discards the input buffer that has anything that has been previously input
*/
void discardInputBuffer(void);

#endif
/**
 * Turns off Echo so user input is not seen in terminal
*/
void turnEchoOff(void);

/**
 * Turns on Echo so user can see their input
*/
void turnEchoOn(void);

/**
 * System will not wait for enter key to be pressed to continue
*/
void turnCanonOff(void);

/**
 * System will wait for enter key to be pressed to continue
*/
void turnCanonOn(void);

/**
* Get a random number from zero to the maximum value.
*
* Adapted from this Reddit post:
* https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
*
* @param max The maximum value (inclusive)
*/
int randomNumber(int max);

/**
* Create a directory called HamsterHangout on the user's desktop.
* 
*/
void createHamsterHangoutDirectory();

/**
 * Get file name for the daily journal.
 * 
 * Journals named in the format: "journal-{year}-{month}-{day}.txt"
 *
 * @return The file name for the  daily journal.
 */
string getFileName();