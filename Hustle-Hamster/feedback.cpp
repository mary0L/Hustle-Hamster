#include "feedback.h"

void outsideFeedback() {
	TYPE("Seems like you didn't get outside today");
	//add studies and advice here
}

void hydrationFeedback() {
	TYPE("Seems like you didn't drink any water today");
	//add studies and advice here
}

void exerciseFeedback() {
	TYPE("Seems like you didn't complete any exercising today");
	//add studies and advice here
}

void socialiseFeedback() {
	TYPE("Seems like you didn't complete any socialising today");
	//add studies and advice here
}

void sleepFeedback() {
	TYPE("Seems like you didn't have a great sleep today");
	//add studies and advice here
}

void activityAdvice(vector<string>& uncompletedActivities) {
	if (uncompletedActivities.size() > 0) {
		int randActivity = 0; //need to add the randomiser in here
		TYPE(uncompletedActivities[randActivity]);
		if (uncompletedActivities[randActivity] == "Socialise") {
			socialiseFeedback();
		}
		else if (uncompletedActivities[randActivity] == "Exercise") {
			exerciseFeedback();
		}
		else if (uncompletedActivities[randActivity] == "Drink Water") {
			hydrationFeedback();
		}
		else if (uncompletedActivities[randActivity] == "Go Outside") {
			outsideFeedback();
		}
		else {
			sleepFeedback();
		}
	} 
	else {
		//if they completed all activities then give some motivation message - this needs serious work dear god
		TYPE("You've completed all the activities assigned for the day great work!");
		TYPE("Sometimes taking a step back and giving yourself time to rest is the best medicine");
		TYPE("I also don't feel great sometimes, when that happens I often take some time by myself to recuperate");
	}
}

void checkCompletion(Journal& dailyEntry) {
	vector<string> uncompletedActivities;

	//check the sleep rating
	if (dailyEntry.getSleepRating() < 3) {
		uncompletedActivities.push_back("bad sleep");
	}

	//check what activities haven't been completed
	for (string activity : defaultActivities)
	{
		if (!dailyEntry.didActivity(activity)) {
			if (activity !=  "Work" && activity != "Study") {
				uncompletedActivities.push_back(activity);
			}
		}
	}
	activityAdvice(uncompletedActivities);

}

void hammyEvaluation(Journal& dailyEntry) {
	printHammy();
	//check what the mood rating is, if less than three do a comprehensive feedback, if greater than three be encouraging
	if (dailyEntry.getDayRating() <= 3) {
		TYPE("Seems like you weren't feeling great today...lets have a look at some things that might help!");
		checkCompletion(dailyEntry);
	}
	else {
		TYPE("I see you're feeling positive today, this is great!");
		//you rated high in your day yay
		//maybe say keep up the good work
		//give some advice for maintaining a healthy schedule but not pushing yourself idk
	}
}