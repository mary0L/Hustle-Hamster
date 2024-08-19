#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype> 
#include <sstream>
#include <vector>

/**
 *  Development Process only so that developers
 *  can use MACOS and Windows
 * 
*/
#ifdef _WINDOWS
#define WIN32_LEAN_AND_MEAN // Necessary to remove ambiguity errors caused in windows.h library
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

using namespace std;

int dayRating = 0; 
char newLine[] = "\n\n";
unsigned int stdDelay = 10;
vector<string> completedActivities; 
char separater[] = "----------------------------------------------------------"; 

int printHammy(){

    cout << "   o _ o\n";
    cout << "  ( -.-)\n";
    cout << "o_(\")(\")\n";
    cout << "       \\\n";
    

    return 0; 
}

void TYPE(const string &p);
int dialoge();
void printReport();
void delay(int time);
void didActivity(string activity);


int main(){
    TYPE("WELCOME TO HAMSTER HANGOUT");
    delay(stdDelay);
    printHammy();
    TYPE("Hi there!! It's so good to see you <3");
    TYPE("Lets see how your day went!");
    cout << separater << "\n"; 
    delay(stdDelay);
    dialoge();
    cout << separater << "\n";
    printReport();

}

int dialoge(){
    TYPE("We will start by doing some ratings! Everything is Rated out of 5, with 5 being the best!");
    delay(stdDelay);
    TYPE("How was your day? [1] Terrible [2] Bad [3] Fine [4] Good [5] AMAZING!");
    cin >> dayRating;

    printHammy();
    didActivity("Exercise");
    didActivity("Reading");
    didActivity("Meditation");


    return 0;
}

void printReport(){
    stringstream message;
    message << "You rated your day a " << dayRating << "/5";
    TYPE(message.str());

    if(!completedActivities.empty()){
        TYPE("Here are the activities you completed today:");
        for (const string& activity : completedActivities) {
            TYPE("- " + activity);
        }
    }else{
        TYPE("You didn't complete any activities today!");
        TYPE("Tomorrow is a new day and you can start fresh!");
    }


}

void delay(int time){
    Sleep(time);
}

void didActivity(string activity){
    char response;
    stringstream message;
    message << "Did you complete " << activity << " today? (y/n)";
    TYPE(message.str());
    cin >> response; 
    char lower = tolower(response); 
    if(response == 'y'){
        completedActivities.push_back(activity);
        TYPE("Awesome Job!\n"); 
    } else {
        TYPE("Try to complete it tomorrow!\n");
    }

}

void TYPE(const string &p){
    cout << "       "; 
    for (char c : p) {
        cout << c << flush;
        delay(30);
    }
    cout << endl;

}
