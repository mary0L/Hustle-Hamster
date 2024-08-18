#include "Journal.h"
#include "Date.h"
#include <iostream>
#include <cassert>

/**
 *  Development Process only so that developers
 *  can use MACOS or Windows
 * 
*/
#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

Journal journal = Journal();

void testDate() {
    Date date = Date(2021, 1, 1, 6);
    journal = Journal(date);
    assert (journal.getDate().getYear() == 2021);
    assert (journal.getDate().getMonth() == 1);
    assert (journal.getDate().getDay() == 1);
    assert (journal.getDate().getWkDay() == 6);
}

void testDayRating() {
    journal.setDayRating(5);
    assert (journal.getDayRating() == 5);
}

void testSleepRating() {
    journal.setSleepRating(5);
    assert (journal.getSleepRating() == 5);
}

void testMood() {
    journal.setMood("Happy");
    assert (journal.getMood() == "Happy");
}

void testActivities() {
    journal.addActivity("Activity 1");
    journal.addActivity("Activity 2");
    journal.addActivity("Activity 3");
    assert (journal.getActivities().size() == 3);
    assert (journal.getActivities()[0] == "Activity 1");
    assert (journal.getActivities()[1] == "Activity 2");
    assert (journal.getActivities()[2] == "Activity 3");
}

void testHammyThoughts() {
    journal.addHammyThoughts("This is a test thought");
    journal.addHammyThoughts("This is another test thought");
    assert (journal.getHammyThoughts().size() == 2);
    assert (journal.getHammyThoughts()[0] == "This is a test thought");
    assert (journal.getHammyThoughts()[1] == "This is another test thought");
}

void testTextEntry() {
    journal.setTextEntry("This is a test entry");
    assert (journal.getTextEntry() == "This is a test entry");
}

int main() {
    testDate();
    testDayRating();
    testSleepRating();
    testMood();
    testActivities();
    testHammyThoughts();
    testTextEntry();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
