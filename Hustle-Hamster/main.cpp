#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype> 
#include <sstream>
#include <vector>

#include "Journal.h"
#include "Date.h"
#include "utils.h"
#include "dailyLog.h"
#include "menuHelp.h"

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
    #ifdef _WINDOWS
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