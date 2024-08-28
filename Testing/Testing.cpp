#include "../Hustle-Hamster/Journal.h"
#include "../Hustle-Hamster/Date.h"
#include <iostream>
#include <cassert>

 /*  Development Process only so that developers
 *  can use MACOS or Windows
 * 
*/
#ifdef _WINDOWS
#define WIN32_LEAN_AND_MEAN // Necessary to remove ambiguity errors caused in windows.h library
#include <windows.h>
#else
#include <unistd.h>
#endif

void testDate() {
    Date date = Date();
    Journal journal = Journal(date);
    
    try
    {
        assert (journal.getDate().getDay() == date.getDay());
        assert (journal.getDate().getMonth() == date.getMonth());
        assert (journal.getDate().getYear() == date.getYear());
        assert (journal.getDate().getWkDay() == date.getWkDay());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "Journal Date failed";
    }
}

void testDayRating() {
    Journal journal;

    try
    {
        journal.setDayRating(5);
        assert (journal.getDayRating() == 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "Journal Day Rating failed";
    }
    

}

void testSleepRating() {
    Journal journal;

    try
    {
        journal.setSleepRating(5);
        assert (journal.getSleepRating() == 5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "Journal Sleep Rating failed";
    }
    
}

void testMood() {
    Journal journal;

    try
    {
        journal.setMood("Happy");
        assert (journal.getMood() == "Happy");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "Journal Mood failed";
    }
    

}

void testActivities() {
    Journal journal;

    try
    {
        journal.addActivity("Activity 1");
        journal.addActivity("Activity 2");
        journal.addActivity("Activity 3");
        assert (journal.getActivities().size() == 3);
        assert (journal.getActivities()[0] == "Activity 1");
        assert (journal.getActivities()[1] == "Activity 2");
        assert (journal.getActivities()[2] == "Activity 3");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "Journal Activities failed";
    }
    

}

void testTextEntry() {
    Journal journal;

    try
    {
        journal.setTextEntry("This is a test entry");
        assert (journal.getTextEntry() == "This is a test entry");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "Journal Text Entry failed";
    }
    

}

int main() {
    testDate();
    testDayRating();
    testSleepRating();
    testMood();
    testActivities();
    testTextEntry();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}