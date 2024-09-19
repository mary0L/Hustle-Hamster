#include "testing.h"
#include "../Hustle-Hamster/utils.h"
#include "../Hustle-Hamster/Journal.h"
#include "../Hustle-Hamster/Date.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

// Test TYPE method by checking the terminal output
void testTYPE(){
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    string input = "This is a test";
    string expectedOutput = "       This is a test\n";

    TYPE(input);

    // Reset cout buffer
    std::cout.rdbuf(coutbuf);

    assert(output.str() == expectedOutput);
}

// Test printHammy method by checking terminal output
void testPrintHammy()
{

    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
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

// Test printReport method by checking the terminal output
void testPrintReport(Journal &journal)
{

    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    // Call function being tested
    printReport(journal);

    // Reset cout buffer
    std::cout.rdbuf(coutbuf);

    // Check the output
    string expectedOutput =
    "       You rated your day a 5/5\n"
    "       You rated your sleep a 3/5\n"
    "       You said your mood today was: Sad\n"
    "----------------------------------------------------------\n"
    "       Here are the activities you completed today:\n"
    "       Activity 1\n"
    "       Activity 2\n"
    "----------------------------------------------------------\n"
    "       Your thoughts on the day:\n"
    "       This is a test entry.\n"
    "----------------------------------------------------------\n";

    assert(output.str() == expectedOutput);
}

// Test menu method by check ther terminal output
void testMenu(){
    std::istringstream input("5\n"   // Simulating incorrect input
                             "3\n"); // Input 3 to quit after menu is called
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original cin buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    std::stringstream output;
    std::streambuf *coutbuf = std::cout.rdbuf(); // Save original cout buffer
    std::cout.rdbuf(output.rdbuf());             // Redirect std::cout to read from output

    // Test menu function with mock input
    menu();

    // Restore cout buffer.
    std::cout.rdbuf(coutbuf);
    std::cin.rdbuf(cinbuf);

    string expectedOutput = 
        "       What can I help you with?\n"
        "       [1] Daily Log\n"
        "       [2] How to Use\n"
        "       [3] Quit\n";

    assert(output.str() == expectedOutput);
}

void testDelay()
{
    int expectedDelay = 5000;  // 5000 milliseconds = 5 second
    
    std::chrono::time_point<std::chrono::system_clock> start, end;

    // Get start time
    start = std::chrono::system_clock::now();
    
    // Call delay function
    delay(expectedDelay);
    
    // Get end time
    end = std::chrono::system_clock::now();
    
    // Calculate the elapsed time in milliseconds
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    assert(elapsedTime == expectedDelay);

}

int main()
{   
        // Set up Journal object
    Journal dailyEntry = Journal();

    dailyEntry.setDayRating(5);
    dailyEntry.setSleepRating(3);
    dailyEntry.setMood("Sad");
    dailyEntry.addActivity("Activity 1");
    dailyEntry.addActivity("Activity 2");
    dailyEntry.setTextEntry("This is a test entry.");

    // Run tests
    testPrintReport(dailyEntry);
    testTYPE();
    testPrintHammy();
    testMenu();
    testDelay();
    
    // Tear down - Delete the journal object
    dailyEntry.~Journal();

    return 0;
}