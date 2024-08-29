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
    expectedOutput << "You rated your day a 4/5\n";
    expectedOutput << "You rated your sleep a 3/5\n";
    expectedOutput << "You said your mood today was: Good\n";
    expectedOutput << "----------------------------------------------------------\n";
    expectedOutput << "Here are the activities you completed today:\n";
    expectedOutput << "Activity 1\n";
    expectedOutput << "Activity 2\n";
    expectedOutput << "----------------------------------------------------------\n";
    expectedOutput << "Your thoughts on the day:\n";
    expectedOutput << "This is a test entry\n";
    expectedOutput << "----------------------------------------------------------\n";

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
    testPrintReport(journal);

    // Delete the journal object
    journal.~Journal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}