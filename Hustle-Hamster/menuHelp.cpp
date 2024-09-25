#include "includes/all_includes.h"

void helpMenu(){
    TYPE("Welcome to the Help Menu!");
    TYPE("I can give you a hand with lots of stuff! Such as...\n");
    printHelpMenu();
}

void howToUse(){

    TYPE("I’m glad you are here to hang out!\n");
    TYPE("Let's go on a quick tour so you can get familiar with things!\n");
    TYPE("This walkthrough will be available to you whenever you need so don’t worry about figuring it all out now!\n");
    TYPE("When you first join the hangout you’ll be presented with a menu that will let you do a couple of things!\n");
    TYPE("[1] Daily Log");
    TYPE("[2] How to Use");
    TYPE("[3] Exit");

    TYPE("Let's start at 1 and work our way down!\n\n");

    TYPE("[1] DAILY LOG");
    howToUseDailyLog();

    TYPE("[2] How to Use:");
    howToUseHowToUse();

    TYPE("[3] Exit");
    howToUseExit();
    
    TYPE("I'll now return you to the help menu and you can let me know what you wanna do next!\n");
    printHelpMenu();
}

void howToUseExit(){
    TYPE("This will exit out of the app!");
}

void howToUseHowToUse(){
    TYPE("This is where you can get help for anything you don’t understand or anything you forget how to do!");
    TYPE("You can have a look at what our where our data is from, refresh yourself on where your data is saved or run through this walk through again!\n\n");
}

void howToUseDailyLog(){

    
    TYPE("The daily log is your daily diary entry!");
    TYPE("Here I will ask you simple questions about your day, and you will give me simple answers!");
    TYPE("I will start with some daily ratings! I will ask you to rate your day and sleep on a scale of 1-5!");
    TYPE("Then I will ask you to rate your average mood today! This doesn't have to be tricky, just 1 word will work!");
    TYPE("Then we will see what sort of activities you spent your day doing!");
    TYPE("These activities might give me some insight into your mood, so I will also let you know what I think!");
    TYPE("Finally, I will ask you a simple question and you can write whatever you want! This can be long or short, and will just be a little blurb about your day!");
    TYPE("Once you complete your log I will show you a daily summary!");
    TYPE("I will then ask if you need to change anything, and if you want to save your journal to a .txt file on your desktop!\n");
    TYPE("If you choose to save your entry it will be saved to this location:");
    string temporary = "" + getDesktopPath() + "\n\n"; 
    TYPE(temporary); 

}

void whereIsOurDataFrom(){
    std::cout << "  Social" << std::endl;
    std::cout << "      A Social Support System Is Imperative for Health and Well-Being. (2024)." << std::endl;
    std::cout << "      Verywell Mind. Retrieved September 25, 2024, from" << std::endl;
    std::cout << "      https://www.verywellmind.com/social-support-for-psychological-health-4119970 \n" << std::endl;

    std::cout << "      Williams, V. (2019, April 19). Mayo Clinic Minute: The benefits of being socially connected." << std::endl;
    std::cout << "      Mayo Clinic News Network. https://newsnetwork.mayoclinic.org/discussion/" << std::endl;
    std::cout << "      mayo-clinic-minute-the-benefits-of-being-socially-connected/ \n" << std::endl;

    std::cout << "  Going Outside" << std::endl;
    std::cout << "      Bratman, G. N., Anderson, C. B., Berman, M. G., Cochran, B., De Vries, S.," << std::endl;
    std::cout << "      Flanders, J., Folke, C., Frumkin, H., Gross, J. J., Hartig, T., Kahn, P. H.," << std::endl;
    std::cout << "      Kuo, M., Lawler, J. J., Levin, P. S., Lindahl, T., Meyer-Lindenberg, A.," << std::endl;
    std::cout << "      Mitchell, R., Ouyang, Z., Roe, J., … Daily, G. C. (2019)." << std::endl;
    std::cout << "      Nature and mental health: An ecosystem service perspective." << std::endl;
    std::cout << "      Science Advances, 5(7), eaax0903. https://doi.org/10.1126/sciadv.aax0903 \n" << std::endl;

    std::cout << "  Exercise" << std::endl;
    std::cout << "      CDC. (2024, July 19). Adult Activity: An Overview." << std::endl;
    std::cout << "      Physical Activity Basics. https://www.cdc.gov/physical-activity-basics/guidelines/adults.html \n" << std::endl;

    std::cout << "      Physical activity. (n.d.). Retrieved September 25, 2024," << std::endl;
    std::cout << "      from https://www.who.int/news-room/fact-sheets/detail/physical-activity \n" << std::endl;

    std::cout << "  Sleep" << std::endl;
    std::cout << "      Consensus Conference Panel, Watson, N. F., Badr, M. S., Belenky, G.," << std::endl;
    std::cout << "      Bliwise, D. L., Buxton, O. M., Buysse, D., Dinges, D. F., Gangwisch, J.," << std::endl;
    std::cout << "      Grandner, M. A., Kushida, C., Malhotra, R. K., Martin, J. L., Patel, S. R.," << std::endl;
    std::cout << "      Quan, S. F., & Tasali, E. (2015). Recommended Amount of Sleep for a Healthy Adult:" << std::endl;
    std::cout << "      A Joint Consensus Statement of the American Academy of Sleep Medicine" << std::endl;
    std::cout << "      and Sleep Research Society. Journal of Clinical Sleep Medicine, 11(06), 591–592." << std::endl;
    std::cout << "      https://doi.org/10.5664/jcsm.4758 \n" << std::endl;

    std::cout << "      thensf. (2021, May 12). Sleep by the Numbers. National Sleep Foundation." << std::endl;
    std::cout << "      https://www.thensf.org/sleep-facts-and-statistics/ \n" << std::endl;

    std::cout << "      Good Sleep for Good Health. (2024). NIH News in Health. Retrieved September 25, 2024," << std::endl;
    std::cout << "      from https://newsinhealth.nih.gov/2021/04/good-sleep-good-health \n" << std::endl;

    std::cout << "  Hydration" << std::endl;
    std::cout << "      How Hydration & Nutrition Affect Your Mental Health. (2023, October 10)." << std::endl;
    std::cout << "      JUST WATER. https://justwater.com/blogs/news/how-hydration-nutrition-affect-your-mental-health \n\n" << std::endl;

}

void whereAreMyFilesSaved(){
    TYPE("Your files are saved to: ");
    string temporary = "" + getDesktopPath() + "\n\n"; 
    TYPE(temporary); 
}

void printHelpMenu(){
    TYPE("[1] App Walkthrough");
    TYPE("[2] Where are my Diaries Saved?");
    TYPE("[3] How to use Daily Log");
    TYPE("[4] Where is our data from?");
    TYPE("[5] Return to Main Menu");

    #ifdef TEST_RUNNING
        exit(0);
    #endif

    bool validResponse = false;
    int temp; 
    discardInputLine();

    while(!validResponse){
        cin >> temp;
        if(!cin.fail() && (temp>0 && temp<6)){
                if(temp == 1){
                    howToUse();
                }
                if(temp == 2){
                    whereAreMyFilesSaved();
                    printHelpMenu();
                }
                if(temp == 3){
                    howToUseDailyLog();
                    printHelpMenu();
                }
                if(temp == 4){
                    whereIsOurDataFrom();
                    printHelpMenu();
                }
                if(temp == 5){
                    menu(); 
                }
                validResponse = true;
                break;
        }else{
            TYPE("Please enter a valid number between 1 and 5");
            cin.clear();
            std::cin.ignore(10000, '\n');
            }
    }
}