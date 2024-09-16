#include "../Hustle-Hamster/menuHelp.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

void test_helpMenu(int simulatedInput) {
    // Redirect cout to capture output
    stringstream outputBuffer;
    streambuf* oldCout = cout.rdbuf(outputBuffer.rdbuf());

    // Redirect cin to simulate user input
    stringstream inputBuffer;
    inputBuffer << simulatedInput;
    streambuf* oldCin = cin.rdbuf(inputBuffer.rdbuf());

    // Call the function to test
    helpMenu();

    // Restore original cin and cout
    cin.rdbuf(oldCin);
    cout.rdbuf(oldCout);

    // Expected output based on input
    string expectedOutput;

    if (simulatedInput == 1) {
        expectedOutput = 
            "       Welcome to the Help Menu!\n"
            "       I can give you a hand with lots of stuff! Such as...\n"
            "       [1] How To Use\n"
            "       [2] What does the data mean?\n"
            "       [3] Return to Main Menu\n"
            "       You are now in the how-to-use section.\n";
    } else if (simulatedInput == 2) {
        expectedOutput = 
            "       Welcome to the Help Menu!\n"
            "       I can give you a hand with lots of stuff! Such as...\n"
            "       [1] How To Use\n"
            "       [2] What does the data mean?\n"
            "       [3] Return to Main Menu\n"
            "       This option is not yet implemented yet! Check back soon!\n"
            "       Welcome to the Help Menu!\n"
            "       I can give you a hand with lots of stuff! Such as...\n"
            "       [1] How To Use\n"
            "       [2] What does the data mean?\n"
            "       [3] Return to Main Menu\n";
    } else if (simulatedInput == 3) {
        expectedOutput = 
            "       Welcome to the Help Menu!\n"
            "       I can give you a hand with lots of stuff! Such as...\n"
            "       [1] How To Use\n"
            "       [2] What does the data mean?\n"
            "       [3] Return to Main Menu\n"
            "       You are now in the main menu.\n";
    }

    // Compare captured output with expected output
    assert(outputBuffer.str() == expectedOutput);

    cout << "test_helpMenu passed for input: " << simulatedInput << "\n";
}

// Unit test for howToUse
void test_howToUse() {
    // Capture cout output
    std::stringstream output;
    std::streambuf *coutbuf = std::cout.rdbuf(); 
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    // Call the function to test
    howToUse();

    // Restore original cout buffer
    cout.rdbuf(coutbuf);

    // Expected output (based on the actual content in howToUse)
    string expectedOutput = 
        "       I’m glad you are here to hang out!\n"
        "       Let's go on a quick tour so you can get familiar with things!\n"
        "       This walkthrough will be available to you whenever you need so don’t worry about figuring it all out now!\n"
        "       When you first join the hangout you’ll be presented with a menu that will let you do a couple of things!\n"
        "       [1] Daily Log\n"
        "       [2] Get Report Data\n"
        "       [3] Settings\n"
        "       [4] Help\n"
        "       Let's start at 1 and work our way down!\n\n"
        "       [1] DAILY LOG\n"
        "       The daily log is your daily diary entry!\n"
        "       Here I will ask you simple questions about your day, and you will give me simple answers!\n"
        "       I will start with some daily ratings! I will ask you to rate your day and sleep on a scale of 1-5!\n"
        "       Then I will ask you to rate your average mood today! This doesn’t have to be tricky, just 1 word will work!\n"
        "       Finally, I will ask you a simple question and you can write whatever you want! This can be long or short, and will just be a little blurb about your day!\n"
        "       Once you complete your log I will show you a daily summary and might include some useful information about how today compares to yesterday or the last week!\n"
        "       This log will then be saved to a .txt file for you to look back whenever you please!\n\n"
        "       [2] GET REPORT DATA\n"
        "       TBD\n\n"
        "       [3] SETTINGS\n"
        "       Here you will find a couple of options of things you can change!\n\n"
        "       [4] HELP:\n"
        "       This is where you can get help for anything you don’t understand or anything you forget how to do!\n"
        "       You can have a look at what our data means, refresh yourself on how to use a certain menu option or run through this walk through again!\n\n"
        "       I'll now return you to the help menu and you can let me know what you wanna do next!\n"
        "Help menu activated.\n";

    // Compare captured output with expected output
    assert(output.str() == expectedOutput);

}

int main() {
    // Test case 1: User selects "How To Use" (input 1)
    test_helpMenu(1);

    // Test case 2: User selects "What does the data mean?" (input 2)
    test_helpMenu(2);

    // Test case 3: User selects "Return to Main Menu" (input 3)
    test_helpMenu(3);

    test_howToUse();  // Run the unit test

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
