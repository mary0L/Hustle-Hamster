#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype> 
#include <sstream>
#include <vector>

#include "Journal.h"
#include "Date.h"
#include "utils.h"

/* Defines namespace*/
using namespace std;

/* The standard delay used for printing */
unsigned int stdDelay = 100;
/* The Inital default activities */
vector<string> defaultActivities = {"Study", "Work", "Socialise", "Exercise", "Drink Water", "Go outside"}; 
/* Separator for formatting */
char separator[] = "----------------------------------------------------------"; 

/**
 * Method to ask and set the users daily rating
 * 
 * @param dailyEntry the daily Journal entry
*/
void dailyRating(Journal &dailyEntry){
    int temp; 
    bool validResponse = false; 
    TYPE("How was your day? [1] Terrible [2] Bad [3] Fine [4] Good [5] AMAZING!");
    while(!validResponse){
        cin >> temp;
        if(!cin.fail() && (temp>0 && temp<6)){
            dailyEntry.setDayRating(temp);
            validResponse = true;
            break;
        }else{
            TYPE("Please enter a valid number between 1 and 5");
            cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }

}

/**
 * Method to ask and set the users sleep rating
 * 
 * @param dailyEntry the daily Journal entry
*/
void sleepRating(Journal &dailyEntry){
    int temp; 
    bool validResponse = false; 
    TYPE("How was your Sleep? [1] Terrible [2] Bad [3] Fine [4] Good [5] AMAZING!");
    while(!validResponse){
        cin >> temp;
        if(!cin.fail() && (temp>0 && temp<6)){
            dailyEntry.setSleepRating(temp);
            validResponse = true;
            break;
        }else{
            TYPE("Please enter a valid number between 1 and 5");
            cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }


}

/**
 * Method to ask and store users mood rating
 * 
 * @param dailyEntry the daily Journal entry
*/
void moodRating(Journal &dailyEntry){
    string temp; 
    bool validResponse = false;
    TYPE("How would you describe your mood today? (Enter as a String)");
    cin >> temp;
    dailyEntry.setMood(temp);
    while(!validResponse){
        cin >> temp;
        if(!cin.fail()){
                dailyEntry.setMood(temp);
                validResponse = true;
                break;
        }else{
            TYPE("Please enter a string");
            cin.clear();
            std::cin.ignore(10000, '\n');
            }
    }
}

/**
 * Method to ask the user if they performed an activity
 * Then stores if they have done the activity
 * 
 * @param activity the activity hammy asks user if they performed
 * @param dailyEntry the daily Journal entry
*/
void didActivity(const string &activity, Journal &dailyEntry){
    char response;
    stringstream message;
    bool validResponse = false;
    message << "Did you " << activity << " today? (y/n)";
    while(!validResponse){
        TYPE(message.str());
        cin >> response; 
        char lower = tolower(response); 
        if(lower == 'y'){
            dailyEntry.addActivity(activity);
            TYPE("Awesome Job!\n"); 
            validResponse = true;
            break;
        } if(lower == 'n') {
            TYPE("Try to complete it tomorrow!\n");
            validResponse = true;
            break;
        }else{
            TYPE("Please Enter a Valid input");
            TYPE("y or Y for Yes");
            TYPE("n or N for No");
        }
    }

}

/**
 * Runs through methods to complete the daily log
*/
int dailyLog(){
    Journal dailyEntry = Journal(); 

    TYPE("We will start by doing some ratings! Everything is Rated out of 5, with 5 being the best!");
    Sleep(stdDelay);
    dailyRating(dailyEntry); 
    sleepRating(dailyEntry);
    moodRating(dailyEntry);

    for (const string& activity : defaultActivities) {
        didActivity(activity, dailyEntry);
    }

    printHammy();
    printReport(dailyEntry);

    return 0;
}

/**
 * Prints the menu and calls method based on user input
*/
void menu(){
    int temp;
    TYPE("What can I help you with?");
    TYPE("[1] Daily Log"); //if daily log has already been completed do not let them complete again!
    TYPE("[2] Get Data Report");
    TYPE("[3] Settings");
    TYPE("[4] How to Use");
    cin >> temp;
    
    if (temp == 1){
        TYPE("Lets see how your day went!");
        cout << separator << "\n"; 
        Sleep(stdDelay);
        dailyLog();
    }
    else if (temp == 0) {
        Journal dailyEntry = Journal();
        exportJournal(dailyEntry);
    }


}

/**
 * Main -> calls menu
 * Inital Hammy welcome
*/
int main(){
    TYPE("WELCOME TO HAMSTER HANGOUT");
    Sleep(stdDelay);
    printHammy();
    TYPE("Hi there!! It's so good to see you <3");
    cout << separator << "\n";
    menu();
}