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

int main()
{
    Date date = Date();
    Journal journal = Journal(date);

    testDailyRating(journal);

    // Delete the journal object
    journal.~Journal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
