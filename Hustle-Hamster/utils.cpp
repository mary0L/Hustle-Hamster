#ifdef TESTING
#define SLEEP_DURATION 0
#define STD_DELAY 0
#else
#define SLEEP_DURATION 30
#define STD_DELAY 100
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype> 
#include <sstream>
#include <vector>
#include "utils.h"
#include <fstream>
#include <random>

using namespace std;


unsigned int stdDelay = STD_DELAY;

vector<string> defaultActivities = {"Study", "Work", "Socialise", "Exercise", "Drink Water", "Go outside"}; 

char separator[] = "----------------------------------------------------------"; 

void delay(int time) {
    Sleep(time);
}

void TYPE(const string& p) {
    cout << "       ";
    for (char c : p) {
        cout << c << flush;
        Sleep(SLEEP_DURATION);
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
    stringstream dailyThoughts;

    dayRate << "You rated your day a " << dailyEntry.getDayRating() << "/5";
    TYPE(dayRate.str());
    sleepRate << "You rated your sleep a " << dailyEntry.getSleepRating() << "/5";
    TYPE(sleepRate.str());
    moodRate << "You said your mood today was: " << dailyEntry.getMood();
    TYPE(moodRate.str());
   
    cout << separator << "\n";

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
    cout << separator << "\n";
    

    TYPE("Your thoughts on the day:");
    dailyThoughts << "" << dailyEntry.getTextEntry();
    TYPE(dailyThoughts.str());
    cout << separator << "\n";
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
        if(!cin.fail() && (temp>=0 && temp<6)){
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
            // Dev mode
            if (temp == 0) {
                Journal devEntry = Journal();
                devEntry.setDayRating(3);
                devEntry.setMood("Happy");
                devEntry.setSleepRating(5);
                devEntry.setTextEntry("Today was a good day. just hung around tbh.");
                devEntry.addActivity("Nap");
                devEntry.addActivity("Art");
                devEntry.addActivity("Work");

                exportJournal(devEntry);
            }
            break;
        }else{
            TYPE("Please enter a valid number between 1 and 5");
            cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
    }


}

string getDesktopPath(){
    try {
        /* For development purposes only, so that we can develop on both mac and windows */
 #ifdef _WINDOWS
        char* path;
        size_t len;
        int err = _dupenv_s(&path, &len, "USERPROFILE");

        if (err != 0 || !path) {
            throw exception();
        }

        string pathStr = string(path);

        free(path); // as per _dupenv_s specification
 #else
        // Note that this is considered an "unsafe" method, but as this is for development processes 
        // only, if it works on MACOS, I'm happy to leave it here. 
        const char* path = getenv("HOME");

        if (!path) {
            throw exception();
    }

        string pathStr = string(path);
#endif
        

        return pathStr + "/Desktop/";
    }
    catch(...) {
        throw runtime_error("Error occurred trying to obtain the user's Desktop path.\n");
    }
}

void exportJournal(Journal& journalEntry) {
    string day = to_string(journalEntry.getDate().getDay());
    string month = to_string(journalEntry.getDate().getMonth());
    string year = to_string(journalEntry.getDate().getYear());

    string filename = "journal-" + year + "-" + month + "-" + day;

    try {
        string desktopPath = getDesktopPath();


        string path = desktopPath + filename + ".txt";
        ofstream txtFile(path);

        if (!txtFile.fail()) {
            txtFile << "============ " << journalEntry.getDate().getMonthName() << " " << day << " " << year << " ============\n";
            txtFile << "You rated your day a " << journalEntry.getDayRating() << "/5\n";
            txtFile << "You rated your sleep a " << journalEntry.getSleepRating() << "/5\n";
            txtFile << "You said that today you felt: " << journalEntry.getMood() << "\n";

            txtFile << "\n";

            if (!journalEntry.getActivities().empty()) {
                txtFile << "Here are the activities you completed today:\n";
                for (string activity : journalEntry.getActivities()) {
                    txtFile << " * " << activity << "\n";
                }
            }

            txtFile << "\n";

            txtFile << "And finally, here is your daily journal entry:\n";
            txtFile << journalEntry.getTextEntry();

            txtFile.close();

            TYPE("Your journal has been exported successfully! Saved to:\n");
            TYPE(path + "\n");
        }
        else {
            throw runtime_error("Error occured trying to create text file.\n");
        }
    }
    catch (const exception& e) {
        TYPE("Sorry, there was an error writing your journal to a file at this time:\n");
        TYPE(e.what());
    }
}

int randomNumber(int max) {

    using engine = std::mt19937;

    default_random_engine eng;

    random_device os_seed;
    const int seed = os_seed();

    engine generator(seed);
    uniform_int_distribution<int> distribute(0, max);

    return distribute(generator);
}