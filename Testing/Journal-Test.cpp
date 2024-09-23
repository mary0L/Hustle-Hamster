#include "testing.h"
#include "all_includes.h"
#include <iostream>
#include <cassert>

// Test Date object using set and get methods
void testJournalDate(Journal &journal, Date &date)
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

void testDate(){
    Date date = Date(19, 9, 2024, 5);    
    
    string wkday = date.getWkDayString();
    string mnth = date.getMonthName();

    assert(wkday == "Friday");
    assert(mnth == "September");
}

// Test set and get daRating for Journal object
void testDayRating(Journal &journal)
{
    journal.setDayRating(5);

    int day = journal.getDayRating();

    assert(day == 5);
}

// Test set and get sleepRating for Journal object
void testSleepRating(Journal &journal)
{
    journal.setSleepRating(5);

    int sleep = journal.getSleepRating();

    assert(sleep == 5);
}

// Test set and get mood for Journal object
void testMood(Journal &journal)
{
    journal.setMood("Happy");

    string mood = journal.getMood();

    assert(mood == "Happy");
}

// Test add and get activities for Journal object
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

    bool didA1 = journal.didActivity("Activity 1");
    bool didA2 = journal.didActivity("Activity 2");
    bool didNotA4 = journal.didActivity("Activity 4");

    assert(didA1 == true);
    assert(didA2 == true);
    assert(didNotA4 == false);
}

// Test set and get textEntry for Journal object
void testTextEntry(Journal &journal)
{
    journal.setTextEntry("This is a test entry");
    
    string text = journal.getTextEntry();
    assert(text == "This is a test entry");
}

int main()
{
    //Setup new Journal object
    Date date = Date();
    Journal journal = Journal(date);

    // Test methods
    testJournalDate(journal, date);
    testDate();
    testDayRating(journal);
    testSleepRating(journal);
    testMood(journal);
    testActivities(journal);
    testTextEntry(journal);

    // Delete the journal object
    journal.~Journal();

    return 0;
}