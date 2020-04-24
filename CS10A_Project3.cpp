/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                      Project 3 : 1 - D array processing : Score Analysis program                        //
// This program gives the user a menu with various options. It allows for score inputs into an array       //
// with the ability to input scores, read scores from file, sort the list and search for a specific score. //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function prototypes
void getScores(int[], int);               // Function that allows user to input scores.
void readScores(int[], int);              // Function that reads scores from file.
void printScores(const int[], int);       // Function that prints all scores.
void printHighestScore(const int[], int); // Function that prints the highest score.
void printLowestScore(const int[], int);  // Function that prints the lowest score.
void printAverageScore(const int[], int); // Function that prints the average score.
void sortDescending(int[], int);          // Function that sorts the scores in descending order.
void searchForValue(int[], int);          // Function that allows user to search for specific score.
int binarySearch(int[], int, int);        // Function that uses a binary search to search for user-specified score.
void printOneScore(const int[], int);     // Function that allows user to print a specific score and number of scores higher.
void swap(int &, int &);                  // Function to swap values during sorting.

#include <iostream>
#include <fstream> // Needed for file stream
#include <iomanip> // Need for output processing
using namespace std;

int main()
{
    // Declare variables
    const int ARRAY_SIZE = 10;    // The size of the array
    int scores[ARRAY_SIZE] = {0}; // The array, initialized with 0
    unsigned choice = 0;          // User choice for option
    bool running = true,          // Boolean to keep program running while true
        isValid;                  // Used for input verification

    /* Begin program loop. Bool is returned once function is complete */
    while (running)
    {

        // Display menu and get input
        cout << "---------------------------------------------------\n"
             << "1-D ARRAY PROCESSING MENU OPTIONS\n"
             << "---------------------------------------------------\n"
             << "1. Read in 10 scores from user.\n"
             << "2. Read in 10 scores from the file, scores.txt.\n"
             << "3. Print all scores.\n"
             << "4. Print the highest score.\n"
             << "5. Print the lowest score.\n"
             << "6. Print the average score.\n"
             << "7. Print one score (give its entry number)\n"
             << "8. Quit program\n"
             << "9. Sort scores in descending order.\n"
             << "10. Search for score.\n\n";
        do
        {
            isValid = true;

            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(100, '\n');
            cout << "\n";

            // Switch statement for control, also verifies input
            if (choice > 0 && choice < 11)
                switch (choice)
                {
                case 1: /* Read 10 scores from user */
                    getScores(scores, ARRAY_SIZE);
                    break;
                case 2: /* Read 10 scores from file */
                    readScores(scores, ARRAY_SIZE);
                    break;
                case 3: /* Print all scores */
                    printScores(scores, ARRAY_SIZE);
                    break;
                case 4: /* Print the highest score */
                    printHighestScore(scores, ARRAY_SIZE);
                    break;
                case 5: /* Print the lowest score */
                    printLowestScore(scores, ARRAY_SIZE);
                    break;
                case 6: /* Print the average score */
                    printAverageScore(scores, ARRAY_SIZE);
                    break;
                case 7: /* Print one score (give its entry number) ((Call specific subscript)) */
                    printOneScore(scores, ARRAY_SIZE);
                    break;
                case 8: /* Quit the program */
                    cout << "Array processing test now concluded. Exiting program .....\n";
                    running = false; // Program terminates
                    break;
                case 9: /* Sort scores in descending order */
                    sortDescending(scores, ARRAY_SIZE);
                    cout << "Sort completed.\n"
                         << "Please select the print all scores menu option to view the scores.\n"
                         << "\nPress enter to continue ";
                    cin.get();
                    break;
                case 10: /* Allow user to search for score */
                    searchForValue(scores, ARRAY_SIZE);
                    break;
                }
            else // Invalid choice-restart loop
            {
                if (!cin)
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                cout << "Invalid choice. Please choose options 1 - 10.\n\n";
                isValid = false;
            }
        } while (!isValid); // while choice is invalid
    }
}

/////////////////////////////
// Function definitions
/////////////////////////////

/////////////////////////////////////////////////////////////////////
// Function that allows user to input scores.
// User is prompted for scores input. Each iteration of the loop
// will assign the input to an array subscript. The input is
// verified. If verification fails, user will be prompted to input
// data again. Once completed function will return to
// main().
/////////////////////////////////////////////////////////////////////
void getScores(int someArray[], int limit)
{
    // Pre:     User is prompted to input scores one at a time.
    // Post:    Once all scores have been input, function returns to main().
    // Declare variables
    bool isValid;
    unsigned userInput = 0;

    // Begin function loop
    do
    {
        // Starts at arr[0] until limit is reached.
        for (unsigned index = 0; index < limit; index++)
        {
            cout << "Enter score #" << (index + 1) << ": ";
            cin >> userInput;
            cin.ignore(100, '\n');

            // Input verification
            if (cin)
            {
                if (userInput >= 0 && userInput <= 100)
                {
                    someArray[index] = userInput;
                    isValid = true;
                    continue;
                }
                else
                {
                    cout << "Invalid input. Try again.\n";
                    isValid = false;
                    index--;
                }
            }
            else
            {
                cout << "Invalid input. Try again.\n";
                cin.clear();
                cin.ignore(100, '\n');
                isValid = false;
                index--;
            }
        }
    } while (!isValid);

    cout << "\nPress enter to continue";
    cin.get();
}

/////////////////////////////////////////////////////////////////////
// Function that reads scores from file.
// User is prompted to provide filename of file to open and read
// from. If file is correct, the data is read from file and stored
// in array. Else the user is prompted to provide correct filename.
// File is closed, reset to begining and function returns to
// main().
/////////////////////////////////////////////////////////////////////
void readScores(int someArray[], int limit)
{
    // Pre:     Prompt for and get filename.
    // Post:    Verify correct filename and read data and store into array. Return to main().
    // Declare variables
    string filename;
    ifstream inFile;

    // Begin function loop
    do
    {
        // Prompt for and get filename. Verify and read/store data.
        cout << "Enter filename: ";
        cin >> filename;
        cin.ignore(100, '\n');

        inFile.open(filename);

        if (!inFile)
        {
            if (inFile.eof())
            {
                inFile.clear();
                inFile.seekg(0);
                inFile.open(filename);
            }
            else
            {
                cout << "Incorrect filename.\n";
                cin.clear();
            }
        }
        if (inFile)
        {
            while (inFile)
            {
                for (unsigned index = 0; index < limit; index++)
                    inFile >> someArray[index];
            }
            // Reset file.
            inFile.clear();
            inFile.seekg(0);
            // Close file.
            inFile.close();

            cout << "File has successfully opened and 10 scores have been read and stored.\n"
                 << "Please select the print all scores menu option to view the scores.\n"
                 << "\nPress enter to continue ";
            cin.get();
        }
    } while (!inFile);
}

/////////////////////////////////////////////////////////////////////
// Function that prints all scores.
// Function will index through array[] and print scores with every
// iteration. Returns to main().
/////////////////////////////////////////////////////////////////////
void printScores(const int someArray[], int limit)
{
    // Pre:     Starts at array[0] and prints first score.
    // Post:    Once all scores have printed, returns to main().
    // Begin function loop.
    for (unsigned index = 0; index < limit; index++)
    {
        cout << "Score #" << (index + 1) << ": "
             << someArray[index] << "\n";
    }
    cout << "\nPress enter to continue";
    cin.get();
}

/////////////////////////////////////////////////////////////////////
// Function that prints the highest score.
// The function will iterate through array and assign the highest
// score to variable and display the highest score to user.
/////////////////////////////////////////////////////////////////////
void printHighestScore(const int someArray[], int limit)
{
    // Pre:     Iterate through array and compare score to highest variable.
    // Post:    Once all scores have been compared and the highest score has been assigned,
    //          score is displayed to user. Returns to main().
    // Declare variable
    unsigned highest = 0;

    // Begin loop, assign highest score to variable
    for (unsigned index = 0; index < limit; index++)
    {
        if (someArray[index] > highest)
            highest = someArray[index];
    }
    // Display highest score
    cout << "The highest score is " << highest
         << "\nPress enter to continue ";
    cin.get();
}

/////////////////////////////////////////////////////////////////////
// Function that prints the lowest score.
// The function will iterate through array and assign the lowest
// score to variable and display the lowest score to user.
/////////////////////////////////////////////////////////////////////
void printLowestScore(const int someArray[], int limit)
{
    // Pre:     Iterate through array and compare score to lowest variable.
    // Post:    Once all scores have been compared and the lowest score has been assigned,
    //          score is displayed to user. Returns to main().
    // Declare variable
    unsigned lowest = 1000;

    // Begin loop, assign lowest score to variable
    for (unsigned index = 0; index < limit; index++)
    {
        if (someArray[index] < lowest)
            lowest = someArray[index];
    }
    // Display lowest score
    cout << "The lowest score is " << lowest
         << "\nPress enter to continue ";
    cin.get();
}

/////////////////////////////////////////////////////////////////////
// Function that prints the average score.
// The function will iterate through the array and accumulate the
// scores. Once competed the mean is calculated and displayed to the
// user. Returns to main().
/////////////////////////////////////////////////////////////////////
void printAverageScore(const int someArray[], int limit)
{
    // Pre:     Iterate through scores and accumulate each score.
    // Post:    cast the score and assign the average to variable. Display average and return to main().
    // Declare variables
    unsigned sum = 0;
    float average;

    // Begin function loop and accumulate scores
    for (unsigned index = 0; index < limit; index++)
        sum += someArray[index];

    // Cast the sum to float and calculate the average and assign to variable.
    average = static_cast<float>(sum) / limit;

    // Format output and display average to user.
    cout << fixed << setprecision(2)
         << "The average score is " << average
         << "\nPress enter to continue ";
    cin.get();
}

/////////////////////////////////////////////////////////////////////
// Function that allows user to print a specific score and displays
// the number of scores that are higher.
// User is prompted for entry number of score they want to view.
// Input is verified before continuing. Entry number and entry score
// is displayed then the array is iterated to find the numbers
// that are higher than that score. Any higher scores are counted
// then displayed. Returns to main().
/////////////////////////////////////////////////////////////////////
void printOneScore(const int someArray[], int limit)
{
    // Pre:     Get entry number from user and verify.
    // Post:    Display entry number and score display. Iterate thru array and count number of higher scores.
    //          Display higher counter and return to main().
    // Declare variables
    unsigned entryNum,
        higherCounter = 0;
    bool isValid = false;

    do
    {
        isValid = true;
        // Prompt for, get and verify entry number.
        cout << "Please enter entry or row # of score you want: ";
        cin >> entryNum;
        cin.ignore(100, '\n');

        // Input verification
        if (cin)
        {
            if (entryNum > 0 && entryNum <= limit)
                isValid = true;
            else
            {
                cout << "Invalid input. Try again.\n";
                isValid = false;
            }
        }
        else
        {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(100, '\n');
            isValid = false;
        }
    } while (!isValid);

    cout << "\nEntry #" << entryNum << " score: " << someArray[(entryNum - 1)];

    for (unsigned index = 0; index < limit; index++)
    {
        if (someArray[index] > someArray[(entryNum - 1)])
            higherCounter++;
    }
    cout << "\nScore statistics: " << higherCounter << " higher.\n"
         << "\nPress enter to continue ";
    cin.get();
}

/////////////////////////////////////////////////////////////////////
// Function that sorts the scores in descending order.
// Function uses selection sort algorithm to sort the scores in the
// array in descending order in conjuction with swap() function.
// Returns to main().
/////////////////////////////////////////////////////////////////////
void sortDescending(int someArray[], int limit)
{
    // Pre:     Declare variables and begin selection sort loop.
    // Post:    Array is sorted in descending order and returns to main().
    // Declare variable.
    int maxIndex,
        maxValue;

    // Begin function loop
    for (int start = 0; start < (limit - 1); start++)
    {
        // Assign start and array[index] values
        maxIndex = start,
        maxValue = someArray[start];

        // Sort function starting at array[1]
        for (unsigned index = start + 1; index < limit; index++)
        {
            if (someArray[index] > maxValue)
            {
                maxValue = someArray[index];
                maxIndex = index;
            }
        }
        // Swaps index of maxValue with start index
        swap(someArray[maxIndex], someArray[start]);
    }
}

/////////////////////////////////////////////////////////////////////
// Function allows user to search for specific score.
// User is prompted to input score. User-score is verified and sent to
// binarySearch() to find score. binarySearch() returns with either
// the index of the score or -1 if score was not found. Data is
// displayed to user and returns to main().
/////////////////////////////////////////////////////////////////////h
void searchForValue(int someArray[], int limit)
{
    // Pre:     Prompt for, get, and verify input. Send input to binarySearch().
    // Post:    binarySearch() returns value, either the index of the score or -1 if not found.
    //          Data is displayed to user and returns to main().
    // Declare variables.
    unsigned userScore = 0;
    bool isValid = false;

    do
    {
        // Prompt for, get, and verify input.
        cout << "Enter score: ";
        cin >> userScore;
        cin.ignore(100, '\n');

        // Input verification
        if (cin)
        {
            if (userScore >= 0 && userScore <= 100)
            {
                isValid = true;
                continue;
            }
            else
            {
                cout << "Invalid input. Try again.\n";
                isValid = false;
            }
        }
        else
        {
            cout << "Invalid input. Try again.\n";
            cin.clear();
            cin.ignore(100, '\n');
            isValid = false;
        }
    } while (!isValid);

    // Score is sent to binarySearch() for sort and search. Function returns index or -1.
    int index = binarySearch(someArray, limit, userScore);

    // Data is displayed to user.
    if (index != -1)
    {
        cout << "Score of " << userScore << " was found at"
             << " entry #" << (index + 1) << "\n";
    }
    else
        cout << "Score of " << userScore << " was not found.\n";

    cout << "\nPress enter to continue";
    cin.get();
}

/////////////////////////////////////////////////////////////////////
// Function that uses a binary search to search for user-specified
// score. The array is first sent to sortDescending to be sorted
// so the binary search can be performed. Once sorted, the array is
// the searched for the user-score. If found, the index is returned,
// else -1 is returned signifying it was not found.
/////////////////////////////////////////////////////////////////////
int binarySearch(int someArray[], int limit, int value)
{
    // Pre:     Array is sent to sortDescending for descending-sort.
    // Post:    Array is searched for user-score and returns either the index of score
    //          or -1 signifying it was not found.
    // Declare variables.
    int first = 0,
        last = limit - 1,
        middle,
        position = -1;
    bool found = false;

    // Selection sort in descending order
    sortDescending(someArray, limit);

    // Begin binary search
    while (!found && first <= last)
    {
        middle = (first + last) / 2;

        if (someArray[middle] == value)
            found = true;

        else if (someArray[middle] < value)
            last = middle - 1;

        else if (someArray[middle] > value)
            first = middle + 1;
    }

    // If found return -1, else return index
    if (!found)
        return position;
    else
        return middle;
}

/////////////////////////////////////////////////////////////////////
// Function to swap values during sorting
/////////////////////////////////////////////////////////////////////
void swap(int &element1, int &element2)
{
    int temp = element1;

    element1 = element2;
    element2 = temp;
}
