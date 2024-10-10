#ifdef TESTING
#define SLEEP_DURATION 0
#define STD_DELAY 0
#else
#define SLEEP_DURATION 30
#define STD_DELAY 100
#endif

#include "includes/all_includes.h"

using namespace std;

unsigned int stdDelay = STD_DELAY;

vector<string> defaultActivities = {"do something productive (e.g. work, study, etc.)", "do something for yourself (e.g. hobby or self care)", "Socialise", "Exercise", "Drink Water", "Go Outside"}; 

char separator[] = "----------------------------------------------------------"; 

bool typingAnimationOn = true;

void delay(int time) {
    Sleep(time);
}

//#########  Following code from stackoverflow: bgoldst  ############################################################

HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
DWORD g_consoleMode;

void setConsoleMode(DWORD bit, bool onElseOff) {
    GetConsoleMode(hStdin, &g_consoleMode);
    
    if (onElseOff) {
        g_consoleMode |= bit;
    } else {
        g_consoleMode &= ~bit;
    }
    
    SetConsoleMode(hStdin, g_consoleMode);
}

void turnEchoOff(void) { setConsoleMode(ENABLE_ECHO_INPUT, false); }

void turnEchoOn(void) { setConsoleMode(ENABLE_ECHO_INPUT, true); }

void turnCanonOff(void) { setConsoleMode(ENABLE_LINE_INPUT, false); }

void turnCanonOn(void) { setConsoleMode(ENABLE_LINE_INPUT, true); }

void discardInputBuffer() {
    FlushConsoleInputBuffer(hStdin);
}

void disableInput(void) {
    turnEchoOff();
    turnCanonOff();
}

void enableInput(void) {
    discardInputBuffer(); 
    turnCanonOn();
    turnEchoOn();
}

//#########################################################################################################

void TYPE(const string& p) {
    disableInput();
    cout << "       ";
    if(!typingAnimationOn){
        cout << p; 
    }
    else{
        for (char c : p) {
            cout << c << flush;
            Sleep(SLEEP_DURATION);
        }
    }
    cout << endl;
    enableInput(); 
}

void printHammy() {
    cout << "   o _ o\n";
    cout << "  ( -.-)\n";
    cout << "o_(\")(\")\n";
    cout << "       \\\n";
}

void printHammyHappy() {
    cout << "   o _ o\n";
    cout << "  ( ^.^)\n";
    cout << "o_(\")(\")\n";
    cout << "       \\\n";
}

void printHammySad() {
    cout << "   o _ o\n";
    cout << "  ( >.<)\n";
    cout << "o_(\")(\")\n";
    cout << "       \\\n";
}


void printReport(Journal& dailyEntry) {
    stringstream dayRate;
    stringstream sleepRate;
    stringstream moodRate;
    stringstream dailyThoughts;

    dayRate << "You rated your day a " << dailyEntry.getDayRating() << "/5";
    TYPE(dayRate.str());
    sleepRate << "You rated your sleep a " << dailyEntry.getSleepRating() << "/5";
    TYPE(sleepRate.str());
    moodRate << "You said your mood today was: " << dailyEntry.getMood();
    TYPE(moodRate.str());
   
    cout << separator << "\n";

    if (!dailyEntry.getActivities().empty()) {
        TYPE("Here are the activities you completed today:");
        for (const string& activity : dailyEntry.getActivities()) {
            TYPE(activity);
        }
    }
    else {
        TYPE("You didn't complete any activities today!");
        TYPE("Tomorrow is a new day and you can start fresh!");
    }
    cout << separator << "\n";
    

    TYPE("Your thoughts on the day:");
    dailyThoughts << "" << dailyEntry.getTextEntry();
    TYPE(dailyThoughts.str());
    cout << separator << "\n";
}

void mockDailyLog() { cout << "Mock daily log" << endl; }
void mockHelpMenu() { cout << "Mock help menu" << endl; }

void menu() {
    string message;
    if(typingAnimationOn){
        message = "[3] Skip Typing Animation (OFF)";
    }
    else{
        message = "[3] Skip Typing Animation (ON)";
    }
    TYPE("What can I help you with?");
    TYPE("[1] Daily Log");
    TYPE("[2] How to Use");
    TYPE(message);
    TYPE("[4] Quit");

    int response = readInt(1, 4);

    if (response == 1) {
        try {
            if (!isFirstOfDay()) {
                TYPE("It looks like you have already told me about your day, do you want to continue?");
                TYPE("This will overwrite your previous entry. (y/n)\n");

                char overwriteResponse = readYN();

                if (overwriteResponse == 'y') {
                    dailyLog();
                }
                else {
                    TYPE("I'll take you back to the main menu.\n");
                    cout << separator << "\n";
                    menu();
                }
            }
            else {
#ifndef TEST_RUNNING
                dailyLog();
#else
                mockDailyLog();
                menu();
#endif
            }
        }
        catch (...) {
            TYPE("It looks like there might be an issue with exporting your journals. This won't affect your ability to do your daily log, you just won't be able to save it.");
            TYPE("Continue anyway? (y/n)\n");

            char errorResponse = readYN();

            if (errorResponse == 'y') {
                dailyLog();
            }
            else {
                TYPE("I'll take you back to the main menu.\n");
                cout << separator << "\n";
                menu();
            }
        }
    }
    else if (response == 2) {
#ifndef TEST_RUNNING
        cout << separator << "\n";
        delay(stdDelay);
        helpMenu();
#else
        mockHelpMenu();
        menu();
#endif
    }
    else if (response == 3){
        if(typingAnimationOn){
            typingAnimationOn = false; 
        }
        else{
            typingAnimationOn = true;
        }
        menu();
    }

    else if (response == 4) {
        TYPE("It was fun hanging out! See you tomorrow!");
#ifndef TEST_RUNNING
        exit(0);
#endif
    }
    else if (response == 0) { // Dev mode <3
        string dir = getHamsterHangoutPath();
        string file = dir + getFileName();

        Journal devEntry = Journal();
        devEntry.setDayRating(3);
        devEntry.setMood("Happy");
        devEntry.setSleepRating(5);
        devEntry.setTextEntry("Today was a good day. just hung around tbh.");
        devEntry.addActivity("Nap");
        devEntry.addActivity("Art");
        devEntry.addActivity("Work");


        exportJournal(devEntry);
    }
}

//Mock method for getting desktop path
int mock_dupenv_s(char **path, size_t *len, const char *varname)
{
    // Simulate success: return a mock user profile path
    if (string(varname) == "USERPROFILE")
    {
        string mockPath = "C:\\MockUser";
        *len = mockPath.size();
        *path = (char *)malloc(mockPath.size() + 1);
        strcpy_s(*path, mockPath.size() + 1, mockPath.c_str());

        return 0;
    }

    return -1;
}

string getDesktopPath(){
    try {
        char* path;
        size_t len;
        #ifndef TEST_RUNNING
        int err = _dupenv_s(&path, &len, "USERPROFILE");
        #else
        int err = mock_dupenv_s(&path, &len, "USERPROFILE");
        if (err != 0 || !path) {
            throw exception();
        }

        string pathStr = string(path);

        free(path); // as per _dupenv_s specification
        return pathStr + "/Desktop/";
    }
    catch(...) {
        throw runtime_error("Error occurred trying to obtain the user's Desktop path.\n");
    }
}

void exportJournal(Journal& journalEntry) {
    string filename = getFileName();

    try {
        string dirPath = getHamsterHangoutPath();

        if (!itemExists(dirPath)) {
            createHamsterHangoutDirectory();
        }

        string path = dirPath + filename;

        ofstream txtFile(path);

        if (!txtFile.fail()) {
            txtFile << "============ " << journalEntry.getDate().getMonthName() << " " << journalEntry.getDate().getDay() << " " << journalEntry.getDate().getYear() << " ============\n";
            txtFile << "You rated your day a " << journalEntry.getDayRating() << "/5\n";
            txtFile << "You rated your sleep a " << journalEntry.getSleepRating() << "/5\n";
            txtFile << "You said that today you felt: " << journalEntry.getMood() << "\n";

            txtFile << "\n";

            if (!journalEntry.getActivities().empty()) {
                txtFile << "Here are the activities you completed today:\n";
                for (string activity : journalEntry.getActivities()) {
                    txtFile << " * " << activity << "\n";
                }
            }

            txtFile << "\n";

            txtFile << "And finally, here is your daily journal entry:\n";
            txtFile << journalEntry.getTextEntry();

            txtFile.close();

            TYPE("Your journal has been exported successfully! Saved to:\n");
            TYPE(path + "\n");
        }
        else {
            throw runtime_error("Error occured trying to create text file.\n");
        }
    }
    catch (const exception& e) {
        TYPE("Sorry, there was an error exporting your journal at this time:\n");
        TYPE(e.what());
    }
}

int randomNumber(int max) {

    using engine = std::mt19937;

    default_random_engine eng;

    random_device os_seed;
    const int seed = os_seed();

    engine generator(seed);
    uniform_int_distribution<int> distribute(0, max);

    return distribute(generator);
}

void createHamsterHangoutDirectory() {
    string fullPath = getHamsterHangoutPath();

    try {
        // _wmkdir requires wchar_t* argument, so converting to wstring, then converting to wchar
        wstring w_fullPath = wstring(fullPath.begin(), fullPath.end());

        const wchar_t* wc_fullPath = w_fullPath.c_str();

        int err = _wmkdir(wc_fullPath);

        // If directory creation fails for any reason other than the directory already exists, throw and exception
        if (err != 0 && errno != EEXIST) {
            throw exception();
        }
    }
    catch (...) {
        throw runtime_error("Error occurred trying to create the HamsterHangout Folder.\n");
    }
}

string getFileName() {
#ifndef TEST_RUNNING
    Date today = Date();
#else
    Date today = Date(30, 9, 2024, 1);
#endif
    string day = to_string(today.getDay());
    string month = to_string(today.getMonth());
    string year = to_string(today.getYear());

    return "journal-" + year + "-" + month + "-" + day + ".txt";
}

bool itemExists(const string& path) {
    struct stat fileInfo;

    const char* c_path = path.c_str();

    int err = stat(c_path, &fileInfo);
    
#if defined(TEST_RUNNING)
    err = -1;
#endif

    if (err == 0) {
        return true;
    }
    else {
        return false;
    }
}

string getHamsterHangoutPath() {
    return getDesktopPath() + "HamsterHangout/";
}

bool isFirstOpen() {
    return !itemExists(getHamsterHangoutPath());
}

bool isFirstOfDay() {
    return !itemExists(getHamsterHangoutPath() + getFileName());
}

char readYN() {
    string response;
    char c_response = ' ';

    bool validResponse = false;

    while (!validResponse) {
        getline(cin >> ws, response);

        response = trim(response);
        response = stringToLower(response);

        if (response == "yes" || response == "y") {
            c_response = 'y';
            validResponse = true;
            break;
        }
        else if (response == "no" || response == "n") {
            c_response = 'n';
            validResponse = true;
            break;
        }

        TYPE("Please Enter a Valid input");
        TYPE("y or Y for Yes");
        TYPE("n or N for No");
    }

    return c_response;
}

int readInt(int min, int max) {    
    string response;
    int i_response;
    bool validResponse = false;

    while (!validResponse) {
        getline(cin >> ws, response);

        response = trim(response);

        if (!response.empty()){
                try {
                    // attempt conversion
                    i_response = stoi(response);

                    // check within range
                    if (i_response >= min && i_response <= max) {
                        validResponse = true;
                    }

                    // final check: that the user hasn't entered characters following a sequence of integers, which stoi would accept
                    // e.g. for 4.5 or 4sdgdff, stoi would succeed and return 4
                    for (int i = 0; i < response.length() - 1; i++) {
                        if (!(response[i] >= int('0') && response[i] <= int('9'))) {
                            validResponse = false;
                            break;
                        }
                    }
                }
                catch (...) {
                    validResponse = false;
                }
        }
        if (!validResponse) {
            string message = "Please enter a valid number between " + to_string(min) + " and " + to_string(max);
            TYPE(message);
        }
    }

    return i_response;
}

string readString() {
    string response;
    bool validResponse = false;

    while (!validResponse) {
        getline(cin >> ws, response);

        response = trim(response);
        
        if (!response.empty()) {
            validResponse = true;

            break;
        }
        else {
            TYPE("Please enter some text");
        }
    }
    return response;
}

string readWord() {
    string response;
    bool validResponse = false;

    while (!validResponse) {
        getline(cin >> ws, response);

        response = trim(response);

        bool isWord = true;

        for (char ch : response) {
            if (isspace(ch)) {
                isWord = false;
                break;
            }
        }

        if (!response.empty() && isWord) {
            validResponse = true;
            break;
        }
        else {
            TYPE("Please enter a single word");
        }

    }
    return response;
}

string stringToLower(const string &s) {
    string result = "";

    for(char ch : s) {
        result += tolower(ch);
    }

    return result;
}

string trim(string &s) {

    int endpos = s.find_last_not_of(" \t\n\r\f\v");

    if (endpos != string::npos) {
        s.erase(endpos + 1);
    }

    return s;
} 