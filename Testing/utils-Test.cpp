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
    std::istringstream input("3\n"); // Input 3 to quit after menu is called
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

// Test exportJournal method by checking the terminal output
void testExportJournal(Journal &journal){
    string day = to_string(journal.getDate().getDay());
    string month = to_string(journal.getDate().getMonth());
    string year = to_string(journal.getDate().getYear());

    string filename = "journal-" + year + "-" + month + "-" + day;

    // Capture cout output
    stringstream outputBuffer;
    streambuf* oldCout = cout.rdbuf(outputBuffer.rdbuf());

    // Call the function to test
    exportJournal(journal);

    // Restore cout
    cout.rdbuf(oldCout);

    string expectedOutput =
        "       Your journal has been exported successfully! Saved to:\n";
    
    // Compare captured output with expected output
    assert(outputBuffer.str() == expectedOutput);

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
    //testExportJournal(journal);

    // Tear down - Delete the journal object
    dailyEntry.~Journal();

    return 0;
}