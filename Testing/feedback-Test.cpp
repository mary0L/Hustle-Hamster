#include "testing.h"
#include "../Hustle-Hamster/feedback.h"
#include "../Hustle-Hamster/Journal.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

void testHammyEval(Journal &journal, int rating)
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    hammyEvaluation(journal);

    string expectedOutput;
    if (rating == 3){
        expectedOutput = 
            "   o _ o\n"
            "  ( -.-)\n"
            "o_(\")(\")\n"
            "       \\\n"
            "       It looks like today wasn't your best day, and that's okay.\n"
            "       Let's see if we can reflect on your day to delve deeper.\n"
            "   o _ o\n"
            "  ( -.-)\n"
            "o_(\")(\")\n"
            "       \\\n"
            "       Now that you've had a moment to reflect on today, it's a great time to write out what's been on your mind.\n"
            "       This could be thoughts, feelings or just something you need to get off your chest\n"
            "       this is your space to express yourself freely!\n";
    } else if (rating == 5) {
        expectedOutput = 
            "   o _ o\n"
            "  ( -.-)\n"
            "o_(\")(\")\n"
            "       \\\n"
            "       I see you're feeling positive today-amazing! It's great to see you having a good day.\n"
            "       Keep up the momentum, but remember to pace yourself. Staying balanced is key!\n"
            "       Celebrate your wins and keep doing what feels right for you.\n"
            "   o _ o\n"
            "  ( -.-)\n"
            "o_(\")(\")\n"
            "       \\\n"
            "       Now that you've had a moment to reflect on today, it's a great time to write out what's been on your mind.\n"
            "       This could be thoughts, feelings or just something you need to get off your chest\n"
            "       this is your space to express yourself freely!\n";
    }

    cout.rdbuf(coutbuf);

    assert(output.str() == expectedOutput);
}



int main()
{
    // Set up Journal object
    Journal dailyEntry = Journal();

    dailyEntry.setDayRating(5);
    testHammyEval(dailyEntry, 5);

    dailyEntry.setDayRating(3);
    testHammyEval(dailyEntry, 3);

    // Tear down - Delete the journal object
    dailyEntry.~Journal();
    
    return 0;
}