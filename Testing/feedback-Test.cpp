#include "testing.h"
#include "../Hustle-Hamster/includes/all_includes.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>
#include <vector>

// Test hammyEvaluation method by check terminal output
void testHammyEval(Journal &journal, int rating)
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    hammyEvaluation(journal);

    string expectedOutput;
    if (rating < 3){
        expectedOutput = 
            "   o _ o\n"
            "  ( >.<)\n"
            "o_(\")(\")\n"
            "       \\\n"
            "       It looks like you rated your day a 2 out of 5\n"
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
            "  ( ^.^)\n"
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

    cout.rdbuf(coutbuf); // Set buffer back to original
    assert(output.str() == expectedOutput);
}

// Testing all feedback methods by calling each individually and checking against terminal output
void testOutside()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    outsideFeedback();

    string expectedOutput =
        "       It looks like you didn't get a chance to go outside today. Fresh air can do wonders for your mood and energy.\n"
        "       Going outdoors can improve your mental well-being and provide a nice break from daily routines.\n"
        "       Try to step outside whenever you can!\n";

    cout.rdbuf(coutbuf); // Set buffer back to original

    assert(output.str() == expectedOutput);

}

void testHydration()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    hydrationFeedback();

    string expectedOutput =
        "       It looks like you might not have had enough water today. Aim for 8 cups to stay hydrated and energized!\n"
        "       Drinking enough water helps with energy and focus. Even mild dehydration can affect your mood and energy.\n"
        "       Try to keep sipping throughout the day!\n";

    cout.rdbuf(coutbuf); // Set buffer back to original

    assert(output.str() == expectedOutput);

}

void testExercise()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    exerciseFeedback();

    string expectedOutput =
        "       It looks like you haven't done exercise today, but that's okay! Any movement is better than none.\n"
        "       Regular exercise helps boost your mood, improves sleep, and keeps your body strong.\n"
        "       Even short bursts of physical activity, like a quick walk or some stretches, can have great benefits.\n"
        "       Remember, consistency is more important than intensity. Your body will thank you!\n";
    
    cout.rdbuf(coutbuf); // Set buffer back to original

    assert(output.str() == expectedOutput);
}

void testSocialise()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    socialiseFeedback();

    string expectedOutput =
        "       It's easy to forget, but socializing is a great way to boost your mood and reduce stress.\n"
        "       Connecting with friends or family, can make a big difference in how you feel.\n"
        "       Whether it's a call, a message, or in-person, socialising has a big impact on well-being.\n"
        "       Remember, meaningful connections can help you recharge, so don't hesitate to reach out!\n";

    cout.rdbuf(coutbuf); // Set buffer back to original

    assert(output.str() == expectedOutput);
}

void testSleep()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    sleepFeedback();

    string expectedOutput =
        "       It looks like your sleep wasn't the best today, but don't worry! You can always make improvements to your sleep habits.\n"
        "       Did you know that adults generally need 7-9 hours of sleep each night for optimal health?\n"
        "       Sleep is essential for boosting mood, improving concentration, and even supporting your immune system.\n"
        "       Lack of sleep can impact your focus and energy levels.\n"
        "       Making small changes like maintaining a consistent sleep schedule or avoiding screens before bed can really help.\n";

    cout.rdbuf(coutbuf); // Set buffer back to original

    assert(output.str() == expectedOutput);
}

void testActivityAdvice(){
    vector<string> vect;
    
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf(); // Store original cout buffer
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    activityAdvice(vect);

    string expectedOutput =
        "       Looks like you completed all of your activities today, great work!\n"
        "       But always remember, rest and reflection are just as important as pushing forward.\n"
        "       You're stronger than you think, even on the hard days. This is just part of the journey.\n";

    cout.rdbuf(coutbuf); // Set buffer back to original

    assert(output.str() == expectedOutput);
}

void testUncompleted(Journal &journal)
{
    checkCompletion(journal);
}

int main()
{
    // Set up Journal object
    Journal dailyEntry = Journal();

    dailyEntry.setDayRating(5); //Setup: set day rating to check condition response in hammyEvaluation
    testHammyEval(dailyEntry, 5); // Run test

    dailyEntry.setDayRating(2); // Setup: change day rating to check conditional response in hammyEvaluation
    testHammyEval(dailyEntry, 2); // Run test with modifications

    dailyEntry.setSleepRating(2); //Setup: set sleep rating to envoke pushback to uncompleted activities
    dailyEntry.addActivity("Socialise"); //Setup: Add activities
    dailyEntry.addActivity("Exercise");
    testUncompleted(dailyEntry);


    // Tear down - Delete the journal object
    dailyEntry.~Journal();



    //Test dialogue only methods
    testActivityAdvice();
    testOutside();
    testHydration();
    testExercise();
    testSocialise();
    testSleep();
    
    return 0;
}