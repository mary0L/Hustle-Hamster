#include "dailyLog.h"

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

void moodRating(Journal &dailyEntry){
    string temp; 
    bool validResponse = false;
    TYPE("How would you describe your mood today? (Enter as a String)");
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

int dailyLog(){
    Journal dailyEntry = Journal(); 

    TYPE("We will start by doing some ratings! Everything is Rated out of 5, with 5 being the best!");
    delay(stdDelay);
    dailyRating(dailyEntry); 
    sleepRating(dailyEntry);
    moodRating(dailyEntry);

    for (const string& activity : defaultActivities) {
        didActivity(activity, dailyEntry);
    }

    printHammy();
    printReport(dailyEntry);
    TYPE("");
    TYPE("I'll return you to the main menu now and you can decide to keep hanging out, or leave whenever you want!\n");
    menu();
    return 0;
}