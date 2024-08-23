#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype> 
#include <sstream>
#include <vector>

#include "utils.h"

using namespace std;


unsigned int stdDelay = 100;

vector<string> defaultActivities = {"Study", "Work", "Socialise", "Exercise", "Drink Water", "Go outside"}; 

char separator[] = "----------------------------------------------------------"; 

void delay(int time) {
    Sleep(time);
}

void TYPE(const string& p) {
    cout << "       ";
    for (char c : p) {
        cout << c << flush;
        Sleep(30);
    }
    cout << endl;
}

void printHammy() {
    cout << "   o _ o\n";
    cout << "  ( -.-)\n";
    cout << "o_(\")(\")\n";
    cout << "       \\\n";
}

void printReport(Journal& dailyEntry) {
    stringstream dayRate;
    stringstream sleepRate;
    stringstream moodRate;

    dayRate << "You rated your day a " << dailyEntry.getDayRating() << "/5";
    TYPE(dayRate.str());
    sleepRate << "You rated your sleep a " << dailyEntry.getSleepRating() << "/5";
    TYPE(sleepRate.str());
    moodRate << "You said your mood today was: " << dailyEntry.getMood();
    TYPE(moodRate.str());

    if (!dailyEntry.getActivities().empty()) {
        TYPE("Here are the activities you completed today:");
        for (const string& activity : dailyEntry.getActivities()) {
            TYPE(activity);
        }
    }
    else {
        TYPE("You didn't complete any activities today!");
        TYPE("Tomorrow is a new day and you can start fresh!");
    }
}

void menu(){
    int temp;
    bool validResponse = false;
    TYPE("What can I help you with?");
    TYPE("[1] Daily Log"); //if daily log has already been completed do not let them complete again!
    TYPE("[2] Get Data Report");
    TYPE("[3] Settings");
    TYPE("[4] How to Use");
    TYPE("[5] Quit");

    while(!validResponse){
        cin >> temp;
        if(!cin.fail() && (temp>0 && temp<6)){
            if (temp == 1){
                TYPE("Lets see how your day went!");
                cout << separator << "\n"; 
                delay(stdDelay);
                dailyLog();
            }
            if(temp == 2){
                TYPE("Data Reports are not yet implemented! Check back soon!\n");
                menu();
            }
            if(temp == 3){
                TYPE("Settings are not yet implemented! Check back soon!\n");
                menu();
            }
            if (temp == 4){
                cout << separator << "\n"; 
                delay(stdDelay);
                helpMenu();
            }
            if(temp == 5){
                TYPE("It was fun hanging out! See you tomorrow!");
                exit(0);
            }
            break;
        }else{
            TYPE("Please enter a valid number between 1 and 5");
            cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }


}