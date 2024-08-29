#include "../Hustle-Hamster/dailyLog.h"
#include "../Hustle-Hamster/Journal.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

void testDailyRating(Journal &journal)
{
    std::istringstream input("3\n");           // Simulating user input "3"
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test dailyRating function with mock input
    dailyRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    int rating = journal.getDayRating();
    assert(rating == 3);
}

void testIncorrectDailyRating(Journal &journal)
{
    std::istringstream input("6\n"
                            "abc\n"
                            "3\n");           
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test dailyRating function with mock input
    dailyRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    int rating = journal.getDayRating();
    assert(rating == 3);
}

void testSleepRating(Journal &journal)
{
    std::istringstream input("4\n");           // Simulating user input "4"
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test sleepRating function with mock input
    sleepRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    int rating = journal.getSleepRating();
    assert(rating == 4);
}

void testIncorrectSleepRating(Journal &journal)
{
    std::istringstream input("6\n"
                            "abc\n"
                            "3\n");           
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test dailyRating function with mock input
    sleepRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    int rating = journal.getSleepRating();
    assert(rating == 3);
}

void testMoodRating(Journal &journal)
{
    std::istringstream input("Happy\n");       // Simulating user input "Happy"
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test moodRating function with mock input
    moodRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    std::string mood = journal.getMood();
    assert(mood == "Happy");
}

void testIncorrectMoodRating(Journal &journal)
{
    std::istringstream input("123\n"
                            "Happy\n");       
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test dailyRating function with mock input
    moodRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    std::string mood = journal.getMood();
    assert(mood == "Happy");
}

void testLongAnswer(Journal &journal)
{
    std::istringstream input("This is a long answer\n"); // Simulating user input "This is a long answer"
    std::streambuf *cinbuf = std::cin.rdbuf();          // Save original buffer
    std::cin.rdbuf(input.rdbuf());                      // Redirect std::cin to read from input

    // Test longAnswer function with mock input
    longAnswer(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    std::string answer = journal.getTextEntry();
    assert(answer == "This is a long answer");
}

void testNoLongAnswer(Journal &journal)
{
    std::istringstream input("\n");                     // Simulating user input "\n"
    std::streambuf *cinbuf = std::cin.rdbuf();          // Save original buffer
    std::cin.rdbuf(input.rdbuf());                      // Redirect std::cin to read from input

    // Test longAnswer function with mock input
    longAnswer(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    std::string answer = journal.getTextEntry();
    assert(answer == "");
}

void testDidActivity(Journal &journal)
{
    std::istringstream input("y\n");              // Simulating user input "y"
    std::streambuf *cinbuf = std::cin.rdbuf();    // Save original buffer
    std::cin.rdbuf(input.rdbuf());                // Redirect std::cin to read from input

    string activity = "Activity 1";

    // Test didActivity function with mock input
    didActivity(activity, journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    std::istringstream input2("n\n");             // Simulating user input "n"
    std::cin.rdbuf(input2.rdbuf());               // Redirect std::cin to read from input
    
    string activity2 = "Activity 2";
    didActivity(activity2, journal);

    std::cin.rdbuf(cinbuf);                        // Restore cin buffer.

    std::vector<std::string> activities = journal.getActivities();
    assert(activities.size() == 1);
    assert(activities[0] == "Activity 1");
}

void testIncorrectDidActivities(Journal &journal)
{
    std::istringstream input("abc\n"
                            "y\n");              // Simulating user input "abc" and "y"
    std::streambuf *cinbuf = std::cin.rdbuf();    // Save original buffer
    std::cin.rdbuf(input.rdbuf());                // Redirect std::cin to read from input

    string activity = "Activity 1";

    // Test didActivity function with mock input
    didActivity(activity, journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);
                       
    std::vector<std::string> activities = journal.getActivities();
    assert(activities.size() == 1);
    assert(activities[0] == "Activity 1");
}

int main()
{   
    // Set up Journal object
    Date date = Date();
    Journal journal = Journal(date);

    // Run tests
    testDailyRating(journal);
    testIncorrectDailyRating(journal);

    testSleepRating(journal);
    testIncorrectSleepRating(journal);

    testMoodRating(journal);
    testIncorrectMoodRating(journal);

    testLongAnswer(journal);
    testNoLongAnswer(journal);

    testDidActivity(journal);
    testIncorrectDidActivities(journal);

    // Delete the journal object
    journal.~Journal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
