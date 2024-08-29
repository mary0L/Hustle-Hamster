#include "../Hustle-Hamster/Journal.h"
#include "../Hustle-Hamster/Date.h"
#include <iostream>
#include <cassert>

void testDate(Journal &journal, Date &date)
{

    int j_day = journal.getDate().getDay();
    int j_month = journal.getDate().getMonth();
    int j_year = journal.getDate().getYear();
    int j_wkDay = journal.getDate().getWkDay();

    int day = date.getDay();
    int month = date.getMonth();
    int year = date.getYear();
    int wkDay = date.getWkDay();

    assert(j_day == day);
    assert(j_month == month);
    assert(j_year == year);
    assert(j_wkDay == wkDay);
}

void testDayRating(Journal &journal)
{
    journal.setDayRating(5);

    int day = journal.getDayRating();

    assert(day == 5);
}

void testSleepRating(Journal &journal)
{
    journal.setSleepRating(5);

    int sleep = journal.getSleepRating();

    assert(sleep == 5);
}

void testMood(Journal &journal)
{
    journal.setMood("Happy");

    string mood = journal.getMood();

    assert(mood == "Happy");
}

void testActivities(Journal &journal)
{
    journal.addActivity("Activity 1");
    journal.addActivity("Activity 2");
    journal.addActivity("Activity 3");

    int a_size = journal.getActivities().size();
    string a1 = journal.getActivities()[0];
    string a2 = journal.getActivities()[1];
    string a3 = journal.getActivities()[2];

    assert(a_size == 3);
    assert(a1 == "Activity 1");
    assert(a2 == "Activity 2");
    assert(a3 == "Activity 3");
}

void testTextEntry(Journal &journal)
{
    journal.setTextEntry("This is a test entry");
    
    string text = journal.getTextEntry();
    assert(text == "This is a test entry");
}

int main()
{
    Date date = Date();
    Journal journal = Journal(date);

    testDate(journal, date);
    testDayRating(journal);
    testSleepRating(journal);
    testMood(journal);
    testActivities(journal);
    testTextEntry(journal);

    // Delete the journal object
    journal.~Journal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}