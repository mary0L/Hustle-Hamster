#include "testing.h"
#include "../Hustle-Hamster/includes/all_includes.h"
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

void testPrintHammyHappy()
{

    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    // Call function being tested
    printHammyHappy();

    // Reset cout buffer
    std::cout.rdbuf(coutbuf);

    // Check the output
    std::stringstream expectedOutput;
    expectedOutput << "   o _ o\n";
    expectedOutput << "  ( ^.^)\n";
    expectedOutput << "o_(\")(\")\n";
    expectedOutput << "       \\\n";

    assert(output.str() == expectedOutput.str());
}

void testPrintHammySad()
{

    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    // Call function being tested
    printHammySad();

    // Reset cout buffer
    std::cout.rdbuf(coutbuf);

    // Check the output
    std::stringstream expectedOutput;
    expectedOutput << "   o _ o\n";
    expectedOutput << "  ( >.<)\n";
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

void testReadInt()
{
    stringstream input("p\n10\n"); // 2 invalid inputs, should prompt again
    cin.rdbuf(input.rdbuf());
    int check = readInt(1, 10);
    assert(check == 10); // After 0, it should take the second input

    cin.clear();
    cin.rdbuf(cin.rdbuf());
}

void testReadString()
{
    stringstream input("\ntesting\n"); // First input is empty, followed by valid input
    cin.rdbuf(input.rdbuf());
    string check = readString();
    assert(check == "testing");

    cin.clear();
    cin.rdbuf(cin.rdbuf());
}

void testReadWord()
{
    stringstream input("two words\ntesting\n"); // First input is two words, followed by valid input
    cin.rdbuf(input.rdbuf());
    string check = readWord();
    assert(check == "testing");

    cin.clear();
    cin.rdbuf(cin.rdbuf());
}

void testReadYN()
{

    {
        stringstream input("p\nyes\n"); // First input is invalid, followed by valid input
        cin.rdbuf(input.rdbuf());
        char check = readYN();
        assert(check == 'y');

        cin.clear();
        cin.rdbuf(cin.rdbuf());
    }

    {
        stringstream input("n\n");
        cin.rdbuf(input.rdbuf());
        char check = readYN();
        assert(check == 'n');

        cin.clear();
        cin.rdbuf(cin.rdbuf());
    }
}

void testStringToLower()
{
    string check = stringToLower("LOWER");
    assert(check == "lower");
}

void testGetFileName()
{
    string expectedOutput = "journal-2024-9-30.txt";
    string filename = getFileName();
    assert(filename == expectedOutput);
}

void testRandomNumber()
{
    int rNum = randomNumber(5);
    assert(rNum <= 5);
}

void testGetDesktopPath()
{
    string desktopPath = getDesktopPath();
    string expectedOutcome = "C:\\MockUser/Desktop/";
    cout << desktopPath << endl;
    assert(desktopPath == expectedOutcome);
}

void testGetHamsterHangoutPath()
{
    string hammyPath = getHamsterHangoutPath();
    string expectedOutcome = "C:\\MockUser/Desktop/HamsterHangout/";
    cout << hammyPath << endl;
    assert(hammyPath == expectedOutcome);
}

void testExportJournal(Journal &journal)
{

    exportJournal(journal);
    
}

void testMenu()
{
    std::istringstream input("1\n"
                            "n\n"
                            "1\n"
                            "y\n"
                            "2\n"
                            "3\n"
                            "4\n");    // Simulating correct user input "n"
    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    menu();
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
    //testPrintReport(dailyEntry);
    testTYPE();
    testPrintHammy();
    testPrintHammyHappy();
    testPrintHammySad();
    testReadInt();
    testGetFileName();
    testReadString();
    testReadWord();
    testReadYN();
    testStringToLower();
    testRandomNumber();
    testGetDesktopPath();
    testGetHamsterHangoutPath();
    testExportJournal(dailyEntry);
    testMenu();

    // Tear down - Delete the journal object
    dailyEntry.~Journal();

    return 0;
}