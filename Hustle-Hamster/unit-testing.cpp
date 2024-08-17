#include "Journal.h"
#include "cassert"


// Testing the Journal class
void testJournal() {
    
    Journal journal;

    // Test variables get and set methods
    journal.setDayRating(5);
    journal.setSleepRating(5);
    journal.setMood("Happy");
    journal.setTextEntry("This is a test entry");

    assert(journal.getDayRating() == 5);
    assert(journal.getSleepRating() == 5);
    assert(journal.getMood() == "Happy");
    assert(journal.getTextEntry() == "This is a test entry");

    // Test vectors add and get methods
    journal.addActivity("Activity 1");
    journal.addActivity("Activity 2");
    journal.addHammyThoughts("This is a test thought");

    journal.addHammyThoughts("This is a test thought");
    journal.addHammyThoughts("This is another test thought");

    assert(journal.getActivities().size() == 3);
    assert(journal.getActivities()[0] == "Activity 1");
    assert(journal.getActivities()[1] == "Activity 2");
    assert(journal.getActivities()[2] == "Activity 3");

    assert(journal.getHammyThoughts().size() == 3);
    assert(journal.getHammyThoughts()[0] == "This is a test thought");
    assert(journal.getHammyThoughts()[1] == "This is another test thought");

}

int main() {
    testJournal();
    return 0;
}
