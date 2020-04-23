// This program will ask the user to answer a series of arithmetic problems and report on how the user performs.

#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

/* Function prototypes */
int getProbsPerSet(/* in/out */ int);                                        // Prompts and gets values from user
void doOneSet(/* in */ char, /* in */ int, /* out */ int &);                 // Generates problems and displays to user
void printHeader(/* in */ int);                                              // Function to print the header showing the current step
void doOneProblem(/* in */ int, /* in */ int, /* in */ char,                 // Function that performs a problem
                  /* in */ int, /* in */ int, /* in/out */ int &,            //
                  /* in/out */ int &);                                       //
void getMaxNum(/* in/out */ int &);                                          // Gets max number for number generations
void generateOperands(/* in */ int, /* in/out */ int &, /* in/out */ int &); // Generates random numbers
void calcCorrectAnswer(int, int, int, int &);                                // Calculates the answer for the problem
void checkAnswer(/* in*/ int, /*in*/ int, /*out*/ int &);                    // Compares users answer to correct answer
void printReport(/* in */ int, /*in*/ int, /* in */ int, /* in */ int);      // Prints report of users statistics

int main()
{
    // Declare variables needed in main()
    int probsPerSet;                                       /* Number of problems to generate per set */
    int set1Correct = 0, set2Correct = 0, set3Correct = 0; /* Counters for number problem user gets correct */
    srand(time(0));                                        /* Seed for rand() */

    /* Function calls */
    probsPerSet = getProbsPerSet(probsPerSet);
    doOneSet('+', probsPerSet, set1Correct);
    doOneSet('-', probsPerSet, set2Correct);
    doOneSet('*', probsPerSet, set3Correct);
    printReport(set1Correct, set2Correct, set3Correct, probsPerSet);
}

//**********************************************
//  Function definitions
//**********************************************

// ****************************************************************************
// This function will prompt the user for the number of problems the would
// like per problem set. The input will be validated for correct data and
// verify number is within the specified range. The value will then be stored
// as a variable in main().
// ****************************************************************************
int getProbsPerSet(/* in */ int probsPerSet)
{
    // Pre:  Prompt user and get data
    // Post: Validate input and return to main
    do
    {
        // Prompt for and get value
        cout << "Enter problems per set: ";
        cin >> probsPerSet; /* Assigns user number to variable */

        // Input validation
        if (probsPerSet < 3 || probsPerSet > 10)
        {
            cout << "ERROR: please enter a number between 3 and 10.\n"
                 << "––––––––––––––––––––––––––––––––––––––––––––––\n";
            cin.clear();
            cin.ignore(100, '\n');
            probsPerSet = 0; /* Sets variable to false to restart loop */
        }
    } while (!probsPerSet);

    return probsPerSet;

    cout << endl;
}

// ****************************************************************************
// This problem holds the functions that will obtain all necessary data,
// output computed data, generate the problems displayed to user, and return
// the number of correct answers to be stored in main().
// ****************************************************************************
void doOneSet(/* in */ char symbol, /* in */ int probsPerSet, /* in/out */ int &correctCounter)
{
    // Pre:  Assign setCounter, display header for set, generate math equations
    // Post: Return correct counter to main, increment setCounter
    static unsigned setCounter = 1; /* Keeps track of which step the program is in */
    int maxNum,                     /* Stores the minimum and maximum numbers to generate */
        total,                      /* Stores the total, or correct answer of equation */
        num1, num2;                 /* Stores the randomly generated numbers */

    printHeader(setCounter);
    getMaxNum(maxNum);
    doOneProblem(probsPerSet, maxNum, symbol, num1, num2, total, correctCounter);

    // Increment counter and start new line
    setCounter++;
    cout << endl;
}

// ****************************************************************************
// This function will generate and display the set number to user at the
// beginning of each set.
// ****************************************************************************
void printHeader(/* in */ int setCounter)
{
    // Pre:  Uses referenced value from doOneSet() to generate string.
    // Post: Output string to user.
    string headerStr = "Set #"; /* Variable to store set string */
    // Display header
    cout << headerStr << setCounter << endl
         << "----------\n";
}

// ****************************************************************************
// This function will prompt user at the beginning of every step for the
// maximum number of the range (from 0 to maximum number) of the problems to
// be generated. Input is validated to be a integer greater than 2.
// ****************************************************************************
void getMaxNum(/* in/out */ int &maxNum)
{
    // Pre:  Prompts user for their specified maximum number.
    // Post: Return number to doOneProblem().
    do
    {
        cout << "What is the maximum number for this set? ";
        cin >> maxNum;
        cin.ignore(100, '\n');

        if (!cin || maxNum < 2)
        {
            if (!cin)
            {
                cout << "ERROR: invalid input.\n";
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                cout << "ERROR: invalid number. Enter a number greater than 2.\n";
                cin.clear();
            }
        }
    } while (!cin || maxNum < 2);
}

// ****************************************************************************
// This function will display each problem to the user and validate the input
// from user. This function uses values referenced from other functions as
// well as passes values, such as to calculate problems and check answers
// before returning to doOneSet().
// ****************************************************************************
void doOneProblem(/* in */ int probsPerSet, /* in*/ int maxNum, /*in */ char symbol,
                  /* in*/ int num1, /*in */ int num2, /* in/out*/ int &total,
                  /* in/out */ int &correctCounter)
{
    // Pre:  Displays problem to user, takes input, passes and validates values.
    // Post: Output information to user, returns to doOneSet().
    int userInput; /* Variable for user input */

    // Starts loop
    for (int counter = 0; counter < probsPerSet; counter++)
    {
        generateOperands(maxNum, num1, num2);
        // Starts loop for input validation
        do
        {
            // Displays equation to user and prompt for input
            cout << num1 << " " << symbol << " " << num2 << " = ";
            cin >> userInput;
            cin.ignore(100, '\n');

            if (!cin)
            {
                cout << "ERROR: invalid input.\n";
                cin.clear();
                cin.ignore(100, '\n');
                userInput = ' '; // Assigns userInput to abitrary value to reprompt equation
            }
        } while (userInput == ' ');

        calcCorrectAnswer(symbol, num1, num2, total);
        checkAnswer(userInput, total, correctCounter);
    }
}

// ****************************************************************************
// This function is used to generate the random numbers to be used in the
// problems presented to the user. The function uses referenced variables
// to assign the values and returns them to doOneProblem().
// ****************************************************************************
void generateOperands(/* in */ int maxNum, /* in/out */ int &num1, /* in/out */ int &num2)
{
    // Pre:  Referenced values from doOneProblem() are used to generate random numbers.
    // Post: Generated numbers are returned to doOneProblem().
    int minNum = 0;

    num1 = (rand() % (maxNum - minNum) + minNum); /* Generates and stores first number */
    num2 = (rand() % (maxNum - minNum) + minNum); /* Generates and stores second number */
}

// ****************************************************************************
// This function will calculate the correct answer from the problem that is
// presented from doOneProblem(). It uses referenced values and returns the
// correct answer to doOneProblem().
// ****************************************************************************
void calcCorrectAnswer(/* in */ int symbol, /* in */ int num1, /* in */ int num2,
                       /* in/out */ int &total)
{
    // Pre:  The symbol used in the equation is used to determine if the numbers
    //       are added, subtracted or mulitplied.
    // Post: The total of the equation is returned to doOneProblem().
    switch (symbol)
    {
    case '+':
        total = num1 + num2;
        break;
    case '-':
        total = num1 - num2;
        break;
    case '*':
        total = num1 * num2;
        break;
    }
}

// ****************************************************************************
// This function will compare the correct answer to the answer given by the
// user and notify the user if their answer was correct or incorrect. If the
// answer is correct, the correct counter is returned.
// ****************************************************************************
void checkAnswer(/* in*/ int userInput, /*in*/ int total, /*out*/ int &correctCounter)
{
    // Pre:  Takes in user's answer and check it with the correct answer.
    // Post: Notifies user whether answer was correct or not. If answer is correct
    //       a counter is returned.
    if (userInput == total)
    {
        cout << "correct\n";
        correctCounter++;
    }
    else
        cout << "incorrect\n";
}

// ****************************************************************************
// This function will display a statistical report to the user after all of
// sets have been completed. The user will be notified of the number of
// problems in each set, the number of correct answers in each set, a
// percentage of correct vs. total problem, and an overall total of all data.
// ****************************************************************************
void printReport(/* in */ int set1Correct, /* in */ int set2Correct, /* in */ int set3Correct,
                 /* in */ int probsPerSet)
{
    // Pre:  Initialize declared variables and calculate needed values
    // Post: Display finalized report
    int totalCorrect = set1Correct + set2Correct + set3Correct,
        totalProbs = probsPerSet * 3;

    // Displays final report
    cout << fixed << setprecision(0); /* Set output formatting */
    cout << "Set #1: You got " << set1Correct << " correct out of " << probsPerSet << " for "
         << (static_cast<float>(set1Correct) / probsPerSet) * 100 << "%\n"
         << "Set #2: You got " << set2Correct << " correct out of " << probsPerSet << " for "
         << (static_cast<float>(set2Correct) / probsPerSet) * 100 << "%\n"
         << "Set #3: You got " << set3Correct << " correct out of " << probsPerSet << " for "
         << (static_cast<float>(set3Correct) / probsPerSet) * 100 << "%\n"
         << "Overall You got " << totalCorrect << " correct out of " << totalProbs << " for "
         << (static_cast<float>(totalCorrect) / totalProbs) * 100 << "%\n";
}
