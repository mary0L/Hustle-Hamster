#include "includes/all_includes.h"

void dailyRating(Journal &dailyEntry){
    #ifndef TEST_RUNNING
        discardInputLine(); 
    #endif

    string line = dailyRatingQ[randomNumber(3)];
    TYPE(line);
    TYPE(ratingSystem);

    int response = readInt(1, 5);
    dailyEntry.setDayRating(response);
}

void sleepRating(Journal &dailyEntry){
    int temp; 
    bool validResponse = false; 

    #ifndef TEST_RUNNING
        discardInputLine(); 
    #endif

    string line = sleepRatingQ[randomNumber(2)];
    TYPE(line);
    TYPE(ratingSystem);

    int response = readInt(1, 5);
    dailyEntry.setSleepRating(response);
}

void moodRating(Journal &dailyEntry){
    string temp; 
    bool validResponse = false;

    #ifndef TEST_RUNNING
        discardInputLine(); 
    #endif
    
    string line = moodQ[randomNumber(3)];
    TYPE(line);

    string response = readWord();
    dailyEntry.setMood(response);
}

void longAnswer(Journal &dailyEntry) {
    string response = readString();
    dailyEntry.setTextEntry(response);
}


void didActivity(const string &activity, Journal &dailyEntry){
    stringstream message;

    #ifndef TEST_RUNNING
        discardInputLine(); 
    #endif
    
    message << "Did you " << activity << " today? (y/n)";
    TYPE(message.str());
    
    char response = readYN();

    if (response == 'y') {
        dailyEntry.addActivity(activity);
    }
}

void exportEntry(Journal &dailyEntry){
    stringstream message;
    message << "Do you want to export today's entry? (y/n)";

    TYPE(message.str());
    
    char response = readYN();

    if (response == 'y') {
        exportJournal(dailyEntry);
    }

    TYPE("");
    TYPE("I'll return you to the main menu now and you can decide to keep hanging out, or leave whenever you want!\n");
    
    #ifndef TEST_RUNNING
        menu();
    #endif
}

int dailyLog(){
    string line = dailyLogR[randomNumber(3)];
    TYPE(line);
    delay(stdDelay);

    Journal dailyEntry = Journal(); 

    delay(stdDelay);
    dailyRating(dailyEntry); 
    sleepRating(dailyEntry);
    moodRating(dailyEntry);

    for (const string& activity : defaultActivities) {
        didActivity(activity, dailyEntry);
    }

    hammyEvaluation(dailyEntry);

    /*put in the Hammy derivations from the activity and mood ratings*/


    std::cin.ignore(10000000, '\n');
    longAnswer(dailyEntry);

    printHammy();
    printReport(dailyEntry);
    confirm(dailyEntry);

    return 0;
}

void confirm(Journal &dailyEntry){
    TYPE("Did you want to go back and change any inputs?");
    TYPE("[1] Daily Rating");
    TYPE("[2] Sleep Rating");
    TYPE("[3] Mood Input");
    TYPE("[4] Activities");
    TYPE("[5] Daily Reflection");
    TYPE("[6] Save and Continue");

    int resonse = readInt(1, 6);

    if (resonse == 1){
        dailyRating(dailyEntry);
        confirm(dailyEntry);
    }
    if (resonse == 2){
        sleepRating(dailyEntry);
        confirm(dailyEntry);
    }
    if (resonse == 3){
        moodRating(dailyEntry);
        confirm(dailyEntry);
    }
    if (resonse == 4){
        dailyEntry.removeAllActivities(); 
        for (const string& activity : defaultActivities) {
            didActivity(activity, dailyEntry);
        }
        confirm(dailyEntry);
    }
    if (resonse == 5){
        std::cin.ignore(10000000, '\n');
        TYPE("New Reflection of the day:");
        longAnswer(dailyEntry);
        confirm(dailyEntry);
    }
    if(resonse == 6){
        exportEntry(dailyEntry);
    }
}