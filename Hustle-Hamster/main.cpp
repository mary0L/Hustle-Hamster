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
    cout << separator << "\n";
    menu();


}