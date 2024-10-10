#include "../Hustle-Hamster/includes/all_includes.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

void testExportJournal(Journal &journal)
{
    exportJournal(journal);

    string filename = getFileName();
    string dirPath = getHamsterHangoutPath();
    string filePath = dirPath + filename;

    std::ifstream inFile(filePath);
    assert(inFile.is_open());
}

int main(){

    // Set up Journal object
    Journal dailyEntry = Journal();

    dailyEntry.setDayRating(5);
    dailyEntry.setSleepRating(3);
    dailyEntry.setMood("Sad");
    dailyEntry.setTextEntry("This is a test entry.");
    dailyEntry.addActivity("Activity 1");
    dailyEntry.addActivity("Activity 2");

    // Tear down - Delete the journal object
    dailyEntry.~Journal();

    return 0;
}