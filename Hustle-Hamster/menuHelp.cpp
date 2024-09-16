#include "menuHelp.h"

void testMethod(){
    TYPE("Test 1");
    TYPE("Test 2");
}

void helpMenu(){
    TYPE("Welcome to the Help Menu!");
    TYPE("I can give you a hand with lots of stuff! Such as...\n");
    TYPE("[1] How To Use");
    TYPE("[2] What does the data mean?");
    TYPE("[3] Return to Main Menu");
    bool validResponse = false;
    int temp; 

    while(!validResponse){
        cin >> temp;
        if(!cin.fail() && (temp>0 && temp<4)){
                if(temp == 1){
                    howToUse();
                }
                if(temp == 2){
                    TYPE("This option is not yet implemented yet! Check back soon!");
                    helpMenu();
                }
                if(temp == 3){
                    menu(); 
                }
                validResponse = true;
                break;
        }else{
            TYPE("Please enter a valid number");
            cin.clear();
            std::cin.ignore(10000, '\n');
            }
    }

}

void howToUse(){

    TYPE("I’m glad you are here to hang out!\n");
    TYPE("Let's go on a quick tour so you can get familiar with things!\n");
    TYPE("This walkthrough will be available to you whenever you need so don’t worry about figuring it all out now!\n");
    TYPE("When you first join the hangout you’ll be presented with a menu that will let you do a couple of things!\n");
    TYPE("[1] Daily Log");
    TYPE("[2] Get Report Data");
    TYPE("[3] Settings");
    TYPE("[4] Help\n");
    TYPE("Let's start at 1 and work our way down!\n\n");
    TYPE("[1] DAILY LOG");
    TYPE("The daily log is your daily diary entry!");
    TYPE("Here I will ask you simple questions about your day, and you will give me simple answers!");
    TYPE("I will start with some daily ratings! I will ask you to rate your day and sleep on a scale of 1-5!");
    TYPE("Then I will ask you to rate your average mood today! This doesn’t have to be tricky, just 1 word will work!");
    TYPE("Finally, I will ask you a simple question and you can write whatever you want! This can be long or short, and will just be a little blurb about your day!");
    TYPE("Once you complete your log I will show you a daily summary and might include some useful information about how today compares to yesterday or the last week!");
    TYPE("This log will then be saved to a .txt file for you to look back whenever you please!\n\n");
    TYPE("[2] GET REPORT DATA");
    TYPE("TBD\n\n");
    TYPE("[3] SETTINGS");
    TYPE("Here you will find a couple of options of things you can change!\n\n");
    TYPE("[4] HELP:");
    TYPE("This is where you can get help for anything you don’t understand or anything you forget how to do!");
    TYPE("You can have a look at what our data means, refresh yourself on how to use a certain menu option or run through this walk through again!\n\n");
    TYPE("I'll now return you to the help menu and you can let me know what you wanna do next!\n");

    helpMenu();
}