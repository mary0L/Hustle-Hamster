#include "feedback.h"

void outsideFeedback() {
	TYPE("It looks like you didn't get a chance to go outside today. Fresh air can do wonders for your mood and energy.");
	TYPE("Going outdoors can improve your mental well-being and provide a nice break from daily routines.");
	TYPE("Try to step outside whenever you can!");
}

void hydrationFeedback() {
	TYPE("It looks like you might not have had enough water today. Aim for 8 cups to stay hydrated and energized!");
	TYPE("Drinking enough water helps with energy and focus. Even mild dehydration can affect your mood and energy.");
	TYPE("Try to keep sipping throughout the day!");
}

void exerciseFeedback() {
	TYPE("It looks like you haven’t done exercise today, but that's okay! Any movement is better than none.");
	TYPE("Regular exercise helps boost your mood, improves sleep, and keeps your body strong.");
	TYPE("Even short bursts of physical activity, like a quick walk or some stretches, can have great benefits.");
	TYPE("Remember, consistency is more important than intensity. Your body will thank you!");
}

void socialiseFeedback() {
	TYPE("It's easy to forget, but socializing is a great way to boost your mood and reduce stress.");
	TYPE("Connecting with friends or family, can make a big difference in how you feel.");
	TYPE("Whether it's a call, a message, or in-person, socialising has a big impact on well-being.");
	TYPE("Remember, meaningful connections can help you recharge, so don't hesitate to reach out!");
}

void sleepFeedback() {
	TYPE("It looks like your sleep wasn't the best today, but don't worry! You can always make improvements to your sleep habits.");
	TYPE("Did you know that adults generally need 7-9 hours of sleep each night for optimal health?");
	TYPE("Sleep is essential for boosting mood, improving concentration, and even supporting your immune system.");
	TYPE("Lack of sleep can impact your focus and energy levels.");
	TYPE("Making small changes like maintaining a consistent sleep schedule or avoiding screens before bed can really help.");

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
		//If they've completed everything, just give general supportive messages
		TYPE("Looks like you completed all of your activities today, great work!");
		TYPE("But always remember, rest and reflection are just as important as pushing forward.");
		TYPE("You're stronger than you think, even on the hard days. This is just part of the journey.");
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
		TYPE("It looks like today wasn't your best day, and that's okay.");
		TYPE("Let's see if we can reflect on your day to delve deeper.");
		checkCompletion(dailyEntry);
	}
	else {
		TYPE("I see you're feeling positive today-amazing! It's great to see you having a good day.");
		TYPE("Keep up the momentum, but remember to pace yourself. Staying balanced is key!");
		TYPE("Celebrate your wins and keep doing what feels right for you.");
	}
	printHammy();
	TYPE("Now that you've had a moment to reflect on today, it's a great time to write out what's been on your mind.");
	TYPE("This could be thoughts, feelings or just something you need to get off your chest");
	TYPE("this is your space to express yourself freely! (Enter as a String) :");
}