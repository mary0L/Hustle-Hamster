#include "../Hustle-Hamster/Journal.h"
#include "../Hustle-Hamster/Date.h"
#include <iostream>
#include <unity.h>

 /*  Development Process only so that developers
 *  can use MACOS or Windows
 * 
*/
#ifdef _WINDOWS
#define WIN32_LEAN_AND_MEAN // Necessary to remove ambiguity errors caused in windows.h library
#include <windows.h>
#else
#include <unistd.h>
#endif

void testJournal() {

    Date date = Date();
    Journal journal = Journal(date);
     
        TEST_ASSERT_TRUE(journal.getDate().getDay() == date.getDay());
        TEST_ASSERT_TRUE(journal.getDate().getMonth() == date.getMonth());
        TEST_ASSERT_TRUE(journal.getDate().getYear() == date.getYear());
    
    Journal journal;

        journal.setDayRating(5);
        TEST_ASSERT_TRUE(journal.getDayRating() == 5);
    
    Journal journal;

        journal.setSleepRating(5);

        TEST_ASSERT_TRUE(journal.getSleepRating() == 5);


    journal.setMood("Happy");
    TEST_ASSERT_TRUE(journal.getMood() == "Happy");


        journal.addActivity("Activity 1");
        journal.addActivity("Activity 2");
        journal.addActivity("Activity 3");

        TEST_ASSERT_TRUE(journal.getActivities().size() == 3);
        TEST_ASSERT_TRUE(journal.getActivities()[0] == "Activity 1");
        TEST_ASSERT_TRUE(journal.getActivities()[1] == "Activity 2");
        TEST_ASSERT_TRUE(journal.getActivities()[2] == "Activity 3");

        journal.setTextEntry("This is a test entry");
        TEST_ASSERT_TRUE(journal.getTextEntry() == "This is a test entry");
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(testJournal);
    return UNITY_END();

}