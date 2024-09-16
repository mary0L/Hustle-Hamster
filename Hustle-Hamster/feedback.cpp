#include "feedback.h"


void checkAdvice(Journal& dailyEntry) {
	vector<string> activities = dailyEntry.getActivities();
	vector<string> incompleteActivities;

	if (dailyEntry.getSleepRating() < 3) {
		incompleteActivities.push_back("bad sleep");
		TYPE("You didn't have a great sleep today");
		TYPE(incompleteActivities.back());
	}

	for (string activity : activities)
	{
		TYPE("activity");
		TYPE(activity);
		if (dailyEntry.didActivity(activity)) {
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
		TYPE("You had a low day rating today...lets have a look at some things that might help!");
		checkAdvice(dailyEntry);
	}
	else {
		TYPE("I see you're feeling positive today, this is great!");
		//other stuff idk what to say
	}
}