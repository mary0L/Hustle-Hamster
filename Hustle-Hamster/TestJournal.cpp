#include "Journal.h"
#include "Date.h"
#include <iostream>
#include <cassert>


Journal journal = Journal();
Date date = Date();

void testDate() {
    try
    {
        journal = Journal(date);
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

void testHammyThoughts() {
    try
    {
        journal.addHammyThoughts("This is a test thought");
        journal.addHammyThoughts("This is another test thought");
        assert (journal.getHammyThoughts().size() == 2);
        assert (journal.getHammyThoughts()[0] == "This is a test thought");
        assert (journal.getHammyThoughts()[1] == "This is another test thought");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "Journal Hammy Thoughts failed";
    }
    
    
}

void testTextEntry() {
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
    testHammyThoughts();
    testTextEntry();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
