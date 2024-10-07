#include "includes/all_includes.h"

/* Defines namespace*/
using namespace std;


/**
 * Main -> calls menu
 * Inital Hammy welcome.
 * 
 * @see utils.h main()
 */
int main(){
    /**
     *  Development Process only so that developers
     *  can use MACOS and Windows
     */
    #if defined(_WIN32) || defined(_WINDOWS)
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
    #endif

    TYPE("WELCOME TO HAMSTER HANGOUT");
    delay(stdDelay);
    printHammy();
    TYPE("Hi there!! It's so good to see you <3");
    TYPE("This is your personal space for daily journaling, where you can reflect, jot down thoughts, and track your journey each day.");
    TYPE("Ready to dive in and start writing? Let's do this!");
    cout << separator << "\n";

    if (isFirstOpen()) {
        howToUse();
        cout << separator << "\n";
    }

    menu();
}