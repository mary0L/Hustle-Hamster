#include "../Hustle-Hamster/includes/all_includes.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>
#include <fstream>
#include <filesystem>


void testExportJournal(Journal &journal)
{
    Date date = Date(30, 9, 2024, 1);
    Journal dailyEntry = Journal(date);

    dailyEntry.setDayRating(5);
    dailyEntry.setSleepRating(3);
    dailyEntry.setMood("Sad");
    dailyEntry.setTextEntry("This is a test entry.");
    dailyEntry.addActivity("Activity 1");
    dailyEntry.addActivity("Activity 2");

    std::ostringstream mockFile;

    writeToFile(mockFile, journal);

    string expectedOutput =
        "============ September 30 2024 ============\n"
        "You rated your day a 5/5\n"
        "You rated your sleep a 3/5\n"
        "You said that today you felt: Sad\n\n"
        "Here are the activities you completed today:\n"
        " * Activity 1\n"
        " * Activity 2\n\n"
        "And finally, here is your daily journal entry:"
        "This is a test entry.";

    assert(mockFile.str() == expectedOutput);

}

int main(){

    return 0;
}