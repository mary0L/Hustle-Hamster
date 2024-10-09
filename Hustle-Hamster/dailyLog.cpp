#include "includes/all_includes.h"

void dailyRating(Journal &dailyEntry)
{
    string line = dailyRatingQ[randomNumber(3)];
    TYPE(line);
    TYPE(ratingSystem);

    int response = readInt(1, 5);
    dailyEntry.setDayRating(response);
}

void sleepRating(Journal &dailyEntry)
{
    string line = sleepRatingQ[randomNumber(2)];
    TYPE(line);
    TYPE(ratingSystem);

    int response = readInt(1, 5);
    dailyEntry.setSleepRating(response);
}

void moodRating(Journal &dailyEntry)
{
    string line = moodQ[randomNumber(3)];
    TYPE(line);

    string response = readWord();
    dailyEntry.setMood(response);
}

void longAnswer(Journal &dailyEntry)
{
    string response = readString();
    dailyEntry.setTextEntry(response);
}


void didActivity(const string &activity, Journal &dailyEntry)
{
    stringstream message;

    message << "Did you " << activity << " today? (y/n)";
    TYPE(message.str());

    char response = readYN();

    if (response == 'y')
    {
        dailyEntry.addActivity(activity);
    }
}

void exportEntry(Journal &dailyEntry)
{
    stringstream message;
    message << "Do you want to export today's entry? (y/n)";

    TYPE(message.str());

    char response = readYN();

    if (response == 'y')
    {
        exportJournal(dailyEntry);
    }

    TYPE("");
    TYPE("I'll return you to the main menu now and you can decide to keep hanging out, or leave whenever you want!\n");

#ifndef TEST_RUNNING
    menu();
#endif
}

int dailyLog()
{
    int rNum = randomNumber(3);

#if defined(TEST_RUNNING)
    rNum = 1;
#endif
    string line = dailyLogR[rNum];
    TYPE(line);
    delay(stdDelay);

    Journal dailyEntry = Journal();

    delay(stdDelay);
    dailyRating(dailyEntry);
    sleepRating(dailyEntry);
    moodRating(dailyEntry);

    for (const string &activity : defaultActivities)
    {
        didActivity(activity, dailyEntry);
    }

    hammyEvaluation(dailyEntry);

    /*put in the Hammy derivations from the activity and mood ratings*/

    longAnswer(dailyEntry);

    printHammy();
    printReport(dailyEntry);
    confirm(dailyEntry);

    return 0;
}

void confirm(Journal &dailyEntry)
{
    TYPE("Did you want to go back and change any inputs?");
    TYPE("[1] Daily Rating");
    TYPE("[2] Sleep Rating");
    TYPE("[3] Mood Input");
    TYPE("[4] Activities");
    TYPE("[5] Daily Reflection");
    TYPE("[6] Save and Continue");

    int resonse = readInt(1, 6);

    if (resonse == 1)
    {
#ifndef TEST_RUNNING
        dailyRating(dailyEntry);
#else
        dailyEntry.setDayRating(1);
#endif
        confirm(dailyEntry);
    }
    if (resonse == 2)
    {
#ifndef TEST_RUNNING
        sleepRating(dailyEntry);
#else
        dailyEntry.setSleepRating(1);
#endif
        confirm(dailyEntry);
    }
    if (resonse == 3)
    {
#ifndef TEST_RUNNING
        moodRating(dailyEntry);
#else
        dailyEntry.setMood("Changed");
#endif
        confirm(dailyEntry);
    }
    if (resonse == 4)
    {
        dailyEntry.removeAllActivities();

#ifndef TEST_RUNNING
        for (const string &activity : defaultActivities)
        {
            didActivity(activity, dailyEntry);
        }
#else
        dailyEntry.addActivity("Changed");
#endif
        confirm(dailyEntry);
    }
    if (resonse == 5)
    {
#ifndef TEST_RUNNING
        std::cin.ignore(10000000, '\n');
        TYPE("New Reflection of the day:");
        longAnswer(dailyEntry);
#else
        dailyEntry.setTextEntry("Changed");
#endif
        confirm(dailyEntry);
    }
    if (resonse == 6)
    {
#ifndef TEST_RUNNING
        exportEntry(dailyEntry);
#else
        cout << "Mock export entry" << endl;
#endif
    }
}