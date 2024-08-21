#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype> 
#include <sstream>
#include <vector>
#include "utils.h"
#include <fstream>

using namespace std;

void delay(int time) {
    Sleep(time);
}

void TYPE(const string& p) {
    cout << "       ";
    for (char c : p) {
        cout << c << flush;
        Sleep(30);
    }
    cout << endl;
}

void printHammy() {
    cout << "   o _ o\n";
    cout << "  ( -.-)\n";
    cout << "o_(\")(\")\n";
    cout << "       \\\n";
}

void printReport(Journal& dailyEntry) {
    stringstream dayRate;
    stringstream sleepRate;
    stringstream moodRate;

    dayRate << "You rated your day a " << dailyEntry.getDayRating() << "/5";
    TYPE(dayRate.str());
    sleepRate << "You rated your sleep a " << dailyEntry.getSleepRating() << "/5";
    TYPE(sleepRate.str());
    moodRate << "You said your mood today was: " << dailyEntry.getMood();
    TYPE(moodRate.str());

    if (!dailyEntry.getActivities().empty()) {
        TYPE("Here are the activities you completed today:");
        for (const string& activity : dailyEntry.getActivities()) {
            TYPE(activity);
        }
    }
    else {
        TYPE("You didn't complete any activities today!");
        TYPE("Tomorrow is a new day and you can start fresh!");
    }
}

void exportJournal(Journal& journalEntry) {
    string day = to_string(journalEntry.getDate().getDay());
    string month = to_string(journalEntry.getDate().getMonth());
    string year = to_string(journalEntry.getDate().getYear());

    string filename = "journal-" + day + "-" + month + "-" + year;

#ifdef _WINDOWS
    string homeDir = getenv("USERPROFILE");
    string path = homeDir + "/Desktop/" + filename + ".txt";
#else
    string homeDir = getenv("HOME");
#endif

    cout << homeDir;

    /*ofstream txtFile(path);

    txtFile << "testing...";

    txtFile.close();*/
}