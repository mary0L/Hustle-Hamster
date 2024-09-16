#include "feedback.h"


void checkAdvice(Journal& dailyEntry) {
	//first check if the sleep was in the 1 or 2 (bad)
	//assign the activities to an array and cycle through each one to see what they didn't complete
	//depending on activity go to that specific method
}

void hammyEvaluation(Journal& dailyEntry) {
	printHammy();
	//check what the mood rating is, if less than three do a comprehensive feedback, if greater than three be encouraging
	if (dailyEntry.getDayRating() <= 3) {
		TYPE("You have rated your day less than three");
		TYPE("Let's see the activities you have completed today");
		checkAdvice(dailyEntry);
	}
}