#define TESTING  // Define TESTING for conditional compilation

#include "../Hustle-Hamster/utils.h"
#include "../Hustle-Hamster/Journal.h"
#include "../Hustle-Hamster/Date.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

void testTYPE(){
    std::stringstream output;
    std::streambuf *coutbuf = std::cout.rdbuf(); 
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    string input = "This is a test";
    string expectedOutput = "       This is a test\n";

    TYPE(input);

    // Reset cout buffer
    std::cout.rdbuf(coutbuf);

    assert(output.str() == expectedOutput);
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

void testMenu(){
    std::istringstream input("1\n");    // Simulating correct user input "1"
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    std::stringstream output;
    std::streambuf *coutbuf = std::cout.rdbuf(); // Save original buffer
    std::cout.rdbuf(output.rdbuf());             // Redirect std::cout to read from output

    // Test menu function with mock input
    menu();

    // Restore cin and cout buffer.
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);

    std::stringstream expectedOutput;
    expectedOutput << "Lets see how your day went!";

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
    testTYPE();
    testPrintHammy();
    testMenu();

    // Tear down - Delete the journal object
    journal.~Journal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}