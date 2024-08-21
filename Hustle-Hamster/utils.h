#pragma once

#include "Journal.h"

/**
 *  Development Process only so that developers
 *  can use MACOS and Windows
 *
*/
#ifdef _WINDOWS
#define WIN32_LEAN_AND_MEAN // Necessary to remove ambiguity errors caused in windows.h library
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

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
 * Method to print Hammy the Hamster Friend
*/
void printHammy();