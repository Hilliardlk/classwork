/*                                            CPSC 146 Team Project                                           */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* Samantha Duffy - (Student Prompts, Validating ID)                                                          */
/* Siya Patel- (Picking Random Questions, Displaying One at a Time, Point System)                             */
/* Laura Hilliard - (Fixing Bugs with Random Questions, Timer, Accepted Answers, Print Report, Exit Prompt)   */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdio.h>       /* printf, scanf, puts, NULL */
#include <stdlib.h>      /* srand, rand */
#include <chrono>        /* time */
#include <conio.h>       /* direct console input */
#include <windows.h>    /* threading for timer */
using namespace std;

/*Hardcoded questions and answers*/
string Q[100] = { "In computing, keyboards are used as input devices.",
"Operating systems are software systems that help make it more convenient to use computers and to manage the transitions between multiple jobs.",
"C++ is a superset of C; it \"spruces up\" the C language and provides capabilities for object oriented programming.",
"A computer is a device capable of performing computations and making logical decisions.",
"Most programs in C++ input data from stdin and output data from stdout.",
"The language understood by the microprocessor is called assembly language.",
"A machine cycle is the time it take the microprocessor to fetch and execute a complete instruction.",
"C, C++, and java are among the most powerful and most widely used assembly languages",
"Machine language is the \"natural language\" of a particular computer.",
"C++ has become widely used for writing software for computer networking and for distribution client/server applications.",
"Nintendo was founded after the year 1900.",
"Atomic bombs work by atomic fission.",
"CPU stands for central processing unit.",
"GPU stands for game processing unit.",
"The hubble telescope was named for Edwin Hubble.",
"Apple released the first iPhone in 2003.",
"Firefox and Chrome are examples of operating systems.",
"RAM stands for random-access memory.",
"Bill Gates was the only founder of microsoft.",
"Apple was the first company to produce a computer of any capacity.",
"It takes two memory locations (16 bits each) to store an address in the 8085 system",
"A compiler is a translation program that converts high-level instructions into a set of binary instructions (machine code) for execution.",
"The control bus and memories share a bidirectional bus in a typical microprocessor system.",
"The language understood by the microprocessor is called assembly language.",
"A machine cycle is the time it takes a microprocessor to fetch and execute a complete instruction.",
"An address bus is also called a unidirectional bus.",
"A coprocessor is a microprocessor designed with a limited instruction set optimized to perform arithmetic operations very quickly.",
"To keep the number of IC pins to a minimum, the 8085 uses a multiplexed bus.",
"Machine language is independent of the type of microprocessor in a computer system.",
"A mnemonic is an English-like instruction that is converted by an assembler into a machine code for use by a processor.",
"Social media actually goes back to some of the earliest Internet technologies and even predates the Internet.",
"E-mail is still the most popular online communication technology.",
"Pervasive computing refers to the fact that computer and communication devices allow one to access information anytime, anywhere.",
"The World Wide Web has been around for more than 30 years.",
"A client/server network consists of one client and several server computers.",
"Information is data that has been summarized or otherwise processed for use in decision-making.",
"Expansion slots provide a computer with additional secondary storage.",
"The focus of IT is to incorporate new, cutting-edge technologies into existing business processes.",
"Computers require programs, which are lists of specific instructions, in order to carry out their work.",
"People are a key ingredient in ensuring the success of information systems in a business environment.",
"A monitor displays information?",
"A SD card is an output device?",
"Microsoft office is a piece of software?",
"A firewall is a type of hardware?",
"A terabyte is equal to 1 million gigabytes?",
"Bluetooth allows your device to connect with another device",
"A processor accepts your commands for the computer?",
"Software that is free for trial is called shareware.?",
"CD stands for collective disk?",
"A pen drive is a storage device?",
"a microphone is used as an output device?",
"the CPU is referred as the stomache of the computer ?",
"a computer is a piece of hardware?",
"a processor accepts commands from your computer ?",
"the DVORAK keyboard is 20 times faster than your average QWERTY keyboard?",
"E-Mail was around before the world wide web?",
"8 bits = 1 byte?",
"HP, Microsoft, and Apple were all started in a garage?",
"the Firefox logo is actually a red panda?",
"a macbook battery is bulletproof?",
"4 bits = 1 nibble?",
"Microsoft office is a free software that comes pre-installed on every computer?",
"You can plug a USB 3.0 in both ways",
"Holding in the power button to turn off your computer corrupts data.",
"Electrostatic Discharge is when a computer component is electrocuted by static electricity from the handler.",
"A keyboard is the only input device that a computer can use",
"The \"home\" key takes you to your desktop",
"Each computer has a NIC or Network Interface Card",
"Each computer has a MAC Address that is used to locate it, like an IP Address",
"You're supposed to safely eject your flash drive before removing it to prevent data corruption",
"Mac and Windows are two different processing systems",
"Mac in made by Apple",
"Windows is made Microsoft",
"David Filo & Jeffry Yang developed google",
"Ray Tomlinson sent the first email",
"Google is the only internet search engine",
"Compact discs hold 1,000 minutes of music",
"The average power (in watts) used by a 20 to 25 inch color tv is 70 - 100 watts",
"the headquarters of intel is located in japan",
"Spam email is a myth",
"Hoverboards have been burtsing into flames because of faulty lithium batteries",
"Stereolithography is a type of 3D printing technoology",
"There are only 1 million mobile subscribers within the United States",
"Approximently 350 million snapchats are sent world wide every day",
"The first mouse was invented by Douglas Engelbart",
"Approximately 3 million cell phones are sold everyday",
"150 out of every 1000 computers are infected with spam",
"since 2008, DVD has out sold video games",
"HTC's dream was the first Android phone",
"the first ever cell phone weighed about 2 lbs",
"The first electronic computer ENIAC weighed more than 27 tons and took up 1800 square feet",
"90\% of the world’s currency is physical money.  The other 10% is on computers",
"\"Typewriter\" is the longest word that you can write using the letters only on one row of a keyboard",
"The first computer mouse was made of wood",
"There are less than 5000 new computer viruses released every month",
"50\% of Wikipedia vandalism is caught by a group of computer programs with more than 90% accuracy",
"If a computer was as powerful as a human brain, it would be able to execute 38,000-trillion operations a second",
"The password for nuclear missiles of the US was 00000000 for 8 years",
"70\% of virus writers are said to work under contract for the CIA",
"ASCII values are a series of 8 numbers between 1-3" };

string A[100] = { "TRUE",
"TRUE",
"TRUE",
"TRUE",
"FALSE",
"FALSE",
"FALSE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"TRUE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"FALSE",
"TRUE",
"FALSE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"TRUE",
"TRUE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"TRUE",
"TRUE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"TRUE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"TRUE",
"FALSE",
"TRUE",
"TRUE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"TRUE",
"TRUE",
"FALSE",
"TRUE",
"TRUE",
"FALSE",
"FALSE",
"TRUE",
"TRUE",
"FALSE",
"FALSE" };

//Everything we need in "global" scope.
string sLastName;           //Student last name.
string sFirstName;          //Student first name.
string sID;                 //Student id.
string sAnswers[10];        //Array to sture user answers.
int iLoginAttempts = 3;     //How many login attempts do we have before we force terminate.
int iRolledQuestions[10];   //We're holding indexes of rolled questions here to check for their uniquess later.
int iCurrentQuestion = 0;   //Index of our current question.
int iScore = 0;             //How many correct answers did we score?
HANDLE hTimer = NULL;       //Handle for our test timer.
chrono::steady_clock::time_point StartTime; //Test Start time


unsigned long _stdcall Timer(void*) //We need to run this on a separate thread to not stall the main program.
{
    Sleep(600000);
    cout << "Time out! Terminating...";
    exit(0);
}


bool Unique_Question(int Index) //Check whether the question hasn't been already asked.
{
    for (int i = 0; i < iCurrentQuestion;  i++) {
        if (iRolledQuestions[i] == Index) {
            return false;
        }
    }
    return true;
}

int Roll_Question() //Roll a question here and check if it's unique, if not - reroll.
{
Roll:
    srand(time(0));
    int iRolledNumber = rand() % 100;

    if (!Unique_Question(iRolledNumber))
        goto Roll;
    else
    {
        iRolledQuestions[iCurrentQuestion] = iRolledNumber;
        return iRolledNumber;
    }
}

bool Is_Valid_Answer(string input) //Check if provided answer should be even evaluated for correctness.
{
    string lower = input;
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) { return std::tolower(c); });

    return ( 0 == strcmp(lower.c_str(), "true") || 0 == strcmp(lower.c_str(), "false") || 0 == strcmp(lower.c_str(), "t") || 0 == strcmp(lower.c_str(), "f") );
}

bool Is_Correct_answer(string input) //Check whether the answer is matching with the correct one.
{
    string lower = input;
    string lowerans = A[iRolledQuestions[iCurrentQuestion]];
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) { return std::tolower(c); });
    std::transform(lowerans.begin(), lowerans.end(), lowerans.begin(), [](unsigned char c) { return std::tolower(c); });

    if (lower == "t")
        lower = "true";

    if (lower == "f")
        lower = "false";

    return 0 == strcmp(lower.c_str(), lowerans.c_str());
}

void Parse_Answer_For_Storage(string input) //Store answer for review in score sheet.
{
    string lower = input;
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c) { return std::tolower(c); });

    if (lower == "t")
        lower = "true";

    if (lower == "f")
        lower = "false";

    sAnswers[iCurrentQuestion] = lower;
}

void Ask_Question() //Present the question.
{
    string ans;
    cout << Q[Roll_Question()] + "\n";
    
Answer:
    getline(cin, ans);

    if (!Is_Valid_Answer(ans))
    {
        cout << "Invalid answer! Please use 'True', 'False', 't', 'f'\n" + Q[iRolledQuestions[iCurrentQuestion]] + "\n";
        goto Answer;
    }

    if (Is_Correct_answer(ans))
        iScore++;

    Parse_Answer_For_Storage(ans);
    iCurrentQuestion++;
}

string Parse_answers() //Make a compound string of rolled questions, provided and correct answers.
{
    string result;
    for (int i = 0; i < 10; i++)
    {
        result += Q[iRolledQuestions[i]] + " : " + sAnswers[i] + " [" + A[iRolledQuestions[i]] + "]\n";
    }

    return result;
}

void End_Quiz()   //End of quiz logic goes here
{
    std::chrono::steady_clock::time_point endtime = std::chrono::steady_clock::now();
    unsigned int elapsedseconds = std::chrono::duration_cast<std::chrono::seconds>(endtime - StartTime).count();
    TerminateThread(hTimer, 0);
    CloseHandle(hTimer);
    cout << sFirstName + " " + sLastName + "\n" + "Score: " + std::to_string(iScore) + "/10\nElapsed time: " + std::to_string( (elapsedseconds % 3600) / 60) + ":"  + std::to_string(elapsedseconds % 60) + "\nAnswers (Q/Student Answer/Correct answer): \n" + Parse_answers();
}

void Start_Quiz()   //Main quiz logic goes here
{
    DWORD tid;
    hTimer = CreateEvent(NULL, FALSE, FALSE, NULL);
    StartTime = std::chrono::steady_clock::now();
    CreateThread(NULL, 0, Timer, NULL, 0, &tid);

    while (iCurrentQuestion < 10)
        Ask_Question();


    End_Quiz();
}

bool Validate_ID(string input) //Checking whether Student ID is up to spec.
{
    bool bIsSixCharsLong = (input.length() == 6);                                                      //Are we 6 characters long?
    bool bStartsWithCapitalA = (input.at(0) == 'A');                                                       //Do we start with capital A?
    bool bIsRestValid = input.substr(1).find_first_not_of("123456789") == std::string::npos;        //Valid UID should not contain non-numerics or 0 in last 5 chars.

    return bIsSixCharsLong && bStartsWithCapitalA && bIsRestValid;
}

void Setup_Student() //Set name and ID.
{
    string slID; //Just something to hold the output locally.
    cout << "Enter First Name: ";
    getline(cin, sFirstName);

    cout << "Enter Last Name: ";
    getline(cin, sLastName);

StudentID:                                                                                                  //We're looping back here in case of failed attempts.                                                        
    cout << "Enter Student ID: ";
    getline(cin, slID);

    if (!Validate_ID(slID))                                                                                 //We failed the ID validity check.
    {
        iLoginAttempts--;

        if (iLoginAttempts > 0)                                                                            //Allow student to input new ID.
        {
            cout << "Student ID Invalid! ";
            goto StudentID;
        }
        else                                                                                              //We ran out of login attempts, goodbye!
        {
            cout << "Too many failed login attempts!\nTerminating...\n";
            system("pause");
            exit(0);
        }
    }
    sID = slID;
    cout << endl;
 
    cout << "Hello, " + sFirstName + " " + sLastName + " - Student: " + sID + "\nWe're ready to begin the test!\n";
    system("pause");
    Start_Quiz();
}

int main()
{
    char choice;
    Setup_Student();

ExitErrorLoop:
    cout << "Press Q to quit or S to start the quiz again for a new student.\n";
    choice = _getch();

    if (tolower(choice) == 's')                                             //Reinitialize variables and restart,
    {
        system("cls");
        iLoginAttempts = 3;
        fill(std::begin(iRolledQuestions), std::end(iRolledQuestions), 0);
        fill(std::begin(sAnswers), std::end(sAnswers), 0);
        iCurrentQuestion = 0;
        iScore = 0;
        Setup_Student();
    }

    if (tolower(choice) == 'q')
        exit(0);
    else                                                                  //Unrecognized choice was made, we only want Q or S
        cout << "Press Q to quit or S to start the quiz again for a new student.\n";
    goto ExitErrorLoop;

    return 0;
}