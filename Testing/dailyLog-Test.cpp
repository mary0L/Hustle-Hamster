#include "testing.h"
#include "../Hustle-Hamster/dailyLog.h"
#include "../Hustle-Hamster/Journal.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

// Test dailyRating method by checking terminal output
void testDailyRating(Journal &journal)
{
    std::istringstream input("10\n"           // Simulating incorrect user input
                            "a\n"           // Simulating incorrect user input
                            "3\n");         // Simulating correct user input "3"

    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    dailyRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    int rating = journal.getDayRating();
    assert(rating == 3);

}

void testSleepRating(Journal &journal)
{
    std::istringstream input("10\n"           // Simulating incorrect user input
                            "a\n"           // Simulating incorrect user input
                            "3\n");            // Simulating correct user input "3"

    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test sleepRating function with mock input
    sleepRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    // Get sleep rating and check it is correct
    int rating = journal.getSleepRating();
    assert(rating == 3);
}

void testMoodRating(Journal &journal)
{
    std::istringstream input("Happy\n");    // Simulating correct user input "Happy"

    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test moodRating function with mock input
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
    std::cerr << "Actual output:" << answer << std::endl;
    assert(answer == "This is a long answer");
}

void testDidActivity(Journal &journal)
{
    std::istringstream input("3\n"           // Simulating incorrect user input
                            "y\n");          // Simulating correct user input "y"

    std::streambuf *cinbuf = std::cin.rdbuf();    // Save original buffer
    std::cin.rdbuf(input.rdbuf());                // Redirect std::cin to read from input

    string activity = "Activity 1";

    // Test didActivity function with mock input
    didActivity(activity, journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    std::istringstream input2("n\n");             // Simulating user input "n"
    std::cin.rdbuf(input2.rdbuf());               // Redirect std::cin to read from input
    
    // Test didActivity function with mock input
    string activity2 = "Activity 2";
    didActivity(activity2, journal);

    std::cin.rdbuf(cinbuf);                        // Restore cin buffer.

    std::vector<std::string> activities = journal.getActivities();
    assert(activities.size() == 1);
    assert(activities[0] == "Activity 1");
}

void testExportEntry(Journal& journal)
{
    std::istringstream input("g\n"     // Simulating incorrect user input
                            "n\n");    // Simulating correct user input "n"
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    exportEntry(journal);

    string expectedOutcome =
        "       Do you want to export today's entry? (y/n)\n"
        "g\n"
        "       Please Enter a Valid input\n"
        "       y or Y for Yes\n"
        "       n or N for No\n"
        "n\n\n"
        "I'll return you to the main menu now and you can decide to keep hanging out, or leave whenever you want!\n\n"
        ;



}

int main()
{   
    // Set up Journal object
    Journal journal = Journal();

    // Run tests
    testDailyRating(journal);
    testSleepRating(journal);
    testMoodRating(journal);
    testLongAnswer(journal);
    testDidActivity(journal);
    testExportEntry(journal);

    // Delete the journal object
    journal.~Journal();

    return 0;
}
