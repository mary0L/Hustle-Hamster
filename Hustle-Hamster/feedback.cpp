#include "feedback.h"


void sleepFeedback() {

}

void checkAdvice(Journal& dailyEntry) {
	vector<string> defActivities = defaultActivities;
	vector<string> incompleteActivities;

	if (dailyEntry.getSleepRating() < 3) {
		incompleteActivities.push_back("bad sleep");
		TYPE(incompleteActivities.back());
	}

	for (string activity : defActivities)
	{
		if (!dailyEntry.didActivity(activity)) {
			incompleteActivities.push_back(activity);
		}

	}

	TYPE("You didn't complete these activities");
	for (string a : incompleteActivities) {
		TYPE(a);
	}



}

void hammyEvaluation(Journal& dailyEntry) {
	printHammy();
	//check what the mood rating is, if less than three do a comprehensive feedback, if greater than three be encouraging
	if (dailyEntry.getDayRating() <= 3) {
		TYPE("Seems like you weren't feeling great today...lets have a look at some things that might help!");
		checkAdvice(dailyEntry);
	}
	else {
		TYPE("I see you're feeling positive today, this is great!");
		//you rated high in your day yay
		//maybe say keep up the good work
		//give some advice for maintaining a healthy schedule but not pushing yourself idk
	}
}