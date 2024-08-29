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
 "   o _ o\n";
 "  ( -.-)\n";
 "o_(\")(\")\n";
 "       \\\n";

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
    string expectedOutput =
        "       You rated your day a 5/5"
        "       You rated your sleep a 3/5"
        "       You said your mood today was: Sad"
        "----------------------------------------------------------"
        "       Here are the activities you completed today:"
        "       Activity 1"
        "       Activity 2"
        "----------------------------------------------------------"
        "       Your thoughts on the day:"
        "       This is a test entry"
        "----------------------------------------------------------";

    assert(output.str() == expectedOutput);
}

void testMenu(){
    std::istringstream input("5\n");
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    std::stringstream output;
    std::streambuf *coutbuf = std::cout.rdbuf(); // Save original buffer
    std::cout.rdbuf(output.rdbuf());             // Redirect std::cout to read from output

    // Test menu function with mock input
    menu();

    // Restore cout buffer.
    std::cout.rdbuf(coutbuf);
    std::cin.rdbuf(cinbuf);

    string expectedOutput = 
        "       What can I help you with?\n"
        "       [1] Daily Log\n"
        "       [2] Get Data Report\n"
        "       [3] Settings\n"
        "       [4] How to Use\n"
        "       [5] Quit\n"
        "       Let's see how your day went!\n";

    assert(output.str() == expectedOutput);
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
    testTYPE();
    testPrintHammy();
    //testMenu();

    // Tear down - Delete the journal object
    journal.~Journal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}