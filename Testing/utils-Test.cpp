#include "../Hustle-Hamster/utils.h"
#include "../Hustle-Hamster/Journal.h"
#include "../Hustle-Hamster/Date.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

void testPrintReport(Journal &journal)
{
    // Get the output from the printReport function
    std::stringstream output;
    std::streambuf *coutbuf = std::cout.rdbuf(); 
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    // Call function being tested
    printReport(journal);

    // Reset cout buffer
    std::cout.rdbuf(coutbuf);

    // Check the output
    std::stringstream expectedOutput;
    expectedOutput << "You rated your day a 5/5";
    expectedOutput << "You rated your sleep a 3/5";
    expectedOutput << "You said your mood today was: Sad";
    expectedOutput << "----------------------------------------------------------";
    expectedOutput << "Here are the activities you completed today:";
    expectedOutput << "Activity 1";
    expectedOutput << "Activity 2";
    expectedOutput << "----------------------------------------------------------";
    expectedOutput << "Your thoughts on the day:";
    expectedOutput << "This is a test entry";
    expectedOutput << "----------------------------------------------------------";

    assert(output.str() == expectedOutput.str());
}

void testPrintHammy()
{
    // Get the output from the printHammy function
    std::stringstream output;
    std::streambuf *coutbuf = std::cout.rdbuf(); 
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    // Call function being tested
    printHammy();

    // Reset cout buffer
    std::cout.rdbuf(coutbuf);

    // Check the output
    std::stringstream expectedOutput;
    expectedOutput << "   o _ o\n";
    expectedOutput << "  ( -.-)\n";
    expectedOutput << "o_(\")(\")\n";
    expectedOutput << "       \\\n";

    assert(output.str() == expectedOutput.str());
}

int main()
{   
    // Set up Journal object
    Date date = Date();
    Journal journal = Journal(date);

    journal.setDayRating(5);
    journal.setSleepRating(3);
    journal.setMood("Sad");
    journal.addActivity("Activity 1");
    journal.addActivity("Activity 2");
    journal.setTextEntry("This is a test entry.");

    // Run tests
    //testPrintReport(journal);
    testPrintHammy();

    // Tear down - Delete the journal object
    journal.~Journal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}