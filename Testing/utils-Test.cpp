#include "../Hustle-Hamster/utils.h"
#include "../Hustle-Hamster/Journal.h"
#include "../Hustle-Hamster/Date.h"
#include <iostream>
#include <cassert>

void testPrintReport(Journal &journal)
{
    std::stringstream output;
    std::streambuf *coutbuf = std::cout.rdbuf(); // Save original buffer
    std::cout.rdbuf(output.rdbuf());             // Redirect std::cout to output

    printReport(journal);

    std::cout.rdbuf(coutbuf); // Restore cout buffer.

    std::string expected = "        You rated your day a 5/5\n "
                        "       You rated your sleep a 3/5\n"
                        "       You said your mood today was: Sad\n"
                        "       ----------------------------------------------------------\n"
                        "       Here are the activities you completed today:\n"
                        "       Activity 1\n"
                        "       Activity 2\n"
                        "       ----------------------------------------------------------\n"
                        "       Your thoughts on the day:\n"
                        "       This is a test entry.\n"
                        "       ----------------------------------------------------------\n";
    
    assert(output.str() == expected);
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