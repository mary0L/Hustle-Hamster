#include "testing.h"
#include "../Hustle-Hamster/includes/all_includes.h"
#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

// Tests howToUse method by checking the terminal output
void testHowToUseExit()
{

    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    // Call the function to test
    howToUseExit();

    string expectedOutput =
        "       This will exit out of the app!\n";

    // Reset cout buffer
    std::cout.rdbuf(coutbuf);
    assert(output.str() == expectedOutput);
}

void testHowToUseToUse()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    // Call function to test
    howToUseHowToUse();

    string expectedOutput =
        "       This is where you can get help for anything you don’t understand or anything you forget how to do!\n"
        "       You can have a look at what our where our data is from, refresh yourself on where your data is saved or run through this walk through again!\n\n\n";

    std::cout.rdbuf(coutbuf);
    assert(output.str() == expectedOutput);
}

void testHowToUseAnimationToggle()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    howToUseAnimationToggle();

    string expectedOutput =
        "       Choosing this option will toggle the typing animation on and off! Please note that the typing animation will always be on when you first open the app!\n\n\n";
    
    std::cout.rdbuf(coutbuf);
    assert(output.str() == expectedOutput);
}

void testHowToUseDailyLog()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    howToUseDailyLog();

    string expectedOutput =
        "       The daily log is your daily diary entry!\n"
        "       Here I will ask you simple questions about your day, and you will give me simple answers!\n"
        "       I will start with some daily ratings! I will ask you to rate your day and sleep on a scale of 1-5!\n"
        "       Then I will ask you to rate your average mood today! This doesn't have to be tricky, just 1 word will work!\n"
        "       Then we will see what sort of activities you spent your day doing!\n"
        "       These activities might give me some insight into your mood, so I will also let you know what I think!\n"
        "       Finally, I will ask you a simple question and you can write whatever you want! This can be long or short, and will just be a little blurb about your day!\n"
        "       Once you complete your log I will show you a daily summary!\n"
        "       I will then ask if you need to change anything, and if you want to save your journal to a .txt file on your desktop!\n\n"
        "       If you choose to save your entry it will be saved to your Desktop.\n"
        "       (for more detail about journal export, select \"Where are my diaries saved\" in the help menu)\n\n\n";

    std::cout.rdbuf(coutbuf);
    assert(output.str() == expectedOutput);
}

void testWhereIsOurDataFrom()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    whereIsOurDataFrom();

    string expectedOutput =
        "  Social\n"
        "      A Social Support System Is Imperative for Health and Well-Being. (2024).\n"
        "      Verywell Mind. Retrieved September 25, 2024, from\n"
        "      https://www.verywellmind.com/social-support-for-psychological-health-4119970 \n\n"

        "      Williams, V. (2019, April 19). Mayo Clinic Minute: The benefits of being socially connected.\n"
        "      Mayo Clinic News Network. https://newsnetwork.mayoclinic.org/discussion/\n"
        "      mayo-clinic-minute-the-benefits-of-being-socially-connected/ \n\n"

        "  Going Outside\n"
        "      Bratman, G. N., Anderson, C. B., Berman, M. G., Cochran, B., De Vries, S.,\n"
        "      Flanders, J., Folke, C., Frumkin, H., Gross, J. J., Hartig, T., Kahn, P. H.,\n"
        "      Kuo, M., Lawler, J. J., Levin, P. S., Lindahl, T., Meyer-Lindenberg, A.,\n"
        "      Mitchell, R., Ouyang, Z., Roe, J., … Daily, G. C. (2019).\n"
        "      Nature and mental health: An ecosystem service perspective.\n"
        "      Science Advances, 5(7), eaax0903. https://doi.org/10.1126/sciadv.aax0903 \n\n"

        "  Exercise\n"
        "      CDC. (2024, July 19). Adult Activity: An Overview.\n"
        "      Physical Activity Basics. https://www.cdc.gov/physical-activity-basics/guidelines/adults.html \n\n"

        "      Physical activity. (n.d.). Retrieved September 25, 2024,\n"
        "      from https://www.who.int/news-room/fact-sheets/detail/physical-activity \n\n"

        "  Sleep\n"
        "      Consensus Conference Panel, Watson, N. F., Badr, M. S., Belenky, G.,\n"
        "      Bliwise, D. L., Buxton, O. M., Buysse, D., Dinges, D. F., Gangwisch, J.,\n"
        "      Grandner, M. A., Kushida, C., Malhotra, R. K., Martin, J. L., Patel, S. R.,\n"
        "      Quan, S. F., & Tasali, E. (2015). Recommended Amount of Sleep for a Healthy Adult:\n"
        "      A Joint Consensus Statement of the American Academy of Sleep Medicine\n"
        "      and Sleep Research Society. Journal of Clinical Sleep Medicine, 11(06), 591–592.\n"
        "      https://doi.org/10.5664/jcsm.4758 \n\n"

        "      thensf. (2021, May 12). Sleep by the Numbers. National Sleep Foundation.\n"
        "      https://www.thensf.org/sleep-facts-and-statistics/ \n\n"
        "      Good Sleep for Good Health. (2024). NIH News in Health. Retrieved September 25, 2024,\n"
        "      from https://newsinhealth.nih.gov/2021/04/good-sleep-good-health \n\n"

        "  Hydration\n"
        "      How Hydration & Nutrition Affect Your Mental Health. (2023, October 10).\n"
        "      JUST WATER. https://justwater.com/blogs/news/how-hydration-nutrition-affect-your-mental-health \n\n\n";

    std::cout.rdbuf(coutbuf);
    assert(output.str() == expectedOutput);
}

void testWhereAreMyFilesSaved()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    whereAreMyFilesSaved();

    string expectedOutput =
        "       Your files are saved to your Desktop;\n"
        "       test_path\n";

    std::cout.rdbuf(coutbuf);
    assert(output.str() == expectedOutput);
}

void testHowToUse()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    howToUse();

    string expectedOutput =
        "       I’m glad you are here to hang out!\n\n"
        "       Let's go on a quick tour so you can get familiar with things!\n\n"
        "       This walkthrough will be available to you whenever you need so don’t worry about figuring it all out now!\n\n"
        "       When you first join the hangout you’ll be presented with a menu that will let you do a couple of things!\n\n"
        "       [1] Daily Log\n"
        "       [2] How to Use\n"
        "       [3] Skip Typing Animation\n"
        "       [4] Exit\n"
        "       Let's start at 1 and work our way down!\n\n\n"
        "       [1] DAILY LOG\n"
        "       The daily log is your daily diary entry!\n"
        "       Here I will ask you simple questions about your day, and you will give me simple answers!\n"
        "       I will start with some daily ratings! I will ask you to rate your day and sleep on a scale of 1-5!\n"
        "       Then I will ask you to rate your average mood today! This doesn't have to be tricky, just 1 word will work!\n"
        "       Then we will see what sort of activities you spent your day doing!\n"
        "       These activities might give me some insight into your mood, so I will also let you know what I think!\n"
        "       Finally, I will ask you a simple question and you can write whatever you want! This can be long or short, and will just be a little blurb about your day!\n"
        "       Once you complete your log I will show you a daily summary!\n"
        "       I will then ask if you need to change anything, and if you want to save your journal to a .txt file on your desktop!\n\n"
        "       If you choose to save your entry it will be saved to your Desktop.\n"
        "       (for more detail about journal export, select \"Where are my diaries saved\" in the help menu)\n\n\n"
        "       [2] How to Use:\n"
        "       This is where you can get help for anything you don’t understand or anything you forget how to do!\n"
        "       You can have a look at what our where our data is from, refresh yourself on where your data is saved or run through this walk through again!\n\n\n"
        "       [3] Skip Typing Animation\n"
        "       Choosing this option will toggle the typing animation on and off! Please note that the typing animation will always be on when you first open the app!\n\n\n"
        "       [4] Exit\n"
        "       This will exit out of the app!\n"
        "       I'll now take you to the menu and you can let me know what you wanna do next!\n\n";

    std::cout.rdbuf(coutbuf);
    assert(output.str() == expectedOutput);
}

void testPrintHelpMenu()
{
    std::istringstream input("1\n"  // Simulating incorrect user input
                             "2\n"   // Simulating incorrect user input
                             "3\n"
                             "4\n"
                             "5\n"); // Simulating correct user input "3"

    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    printHelpMenu();
    
    string menu =
        "       [1] App Walkthrough\n"
        "       [2] Where are my Diaries Saved?\n"
        "       [3] How to use Daily Log\n"
        "       [4] Where is our data from?\n"
        "       [5] Return to Main Menu\n";

    string expectedOutput =
        menu +
        "Mock How To Use Called\n" + menu +
        "Mock Where Are My Files Saved Called\n" + menu +
        "Mock How To Use Daily Log Called\n" + menu +
        "Mock Where Is Our Data From Called\n" + menu +
        "Mock Menu Called\n";

    std::cout.rdbuf(coutbuf);
    std::cin.rdbuf(cinbuf);
    
    assert(output.str() == expectedOutput);
}

void testHelpMenu()
{
    std::stringstream output; // Capture cout output
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf()); // Redirect cout to output

    helpMenu();

    string expectedOutput =
        "       Welcome to the Help Menu!\n"
        "       I can give you a hand with lots of stuff! Such as...\n\n";
    
    std::cout.rdbuf(coutbuf);
    assert(output.str() == expectedOutput);
}

int main()
{

    testHowToUseExit();
    testHowToUseToUse();
    testHowToUseDailyLog();
    testWhereIsOurDataFrom();
    testWhereAreMyFilesSaved();
    testHowToUse();
    testPrintHelpMenu();
    testHelpMenu();
    return 0;
}
