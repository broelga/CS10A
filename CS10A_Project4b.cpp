/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Project 4a: Collecting banknotes                                                                    //
// This program takes an amount from the user, calculates the number of banknotes and prints the       //
// banknotes to user                                                                                   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

void numBanknotes(/* in */ const int[], /* in */ int, /* in */ int); // Function to calculate the number of banknotes deducted from user amount and print banknotes to user

int main()
{
    // Declare variables
    const int ARRAY_SIZE = 5;                       // Size of array to use
    int banknotes[ARRAY_SIZE] = {50, 20, 10, 5, 1}; // Array that holds the currency declarations
    int plussarAmount = 0;                          // Variable for user input

    // Prompt for and get amount
    cout << "Welcome to Plusplusland.\n"
         << "Please enter the plussar amount: ";
    cin >> plussarAmount;

    // Call functions
    numBanknotes(banknotes, ARRAY_SIZE, plussarAmount); // Calculate the number of banknotes deducted from user amount and print banknotes to user
}

//***********************
// Function definitions *
//***********************

//*********************************************************************
// Function to print number of banknotes to dispense to user.         *
// This function will take in the const array to use as a reference.  *
// It will assign quotient of the division of the array subscript and *
// amount remaining and print the number of banknotes if quotient is  *
// greater than 0. Once there is no more amount remaining the loop    *
// will end.                                                          *
//*********************************************************************
void numBanknotes(/* in */ const int refArray[], /* in */ int arraySize, /* in */ int amount)
{
    // Pre:     Take the array, size, and user amount and assign the quotient of the remanining amount and array subscript element to a variable.
    // Post:    The number of banknotes calculated by the quotient is printed along with the element in the refArray. Loop is repeated until the remaining amount is 0.
    // Declare variables.
    int amountRemaining = amount,
        numNotes = 0;

    // Begin loop
    for (int index = 0; index < arraySize; index++)
    {
        // If there is remaning amount, continue
        if (amountRemaining != 0)
        {
            // Assign number of divisions to numNotes
            numNotes = amountRemaining / refArray[index];
            // Calculate and assign the remaning amount and continue loop
            amountRemaining = amountRemaining % refArray[index];

            // If numNotes is greater than 0 the number of respective bills are printed
            if (numNotes > 0)
            {
                for (int counter = 0; counter < numNotes; counter++)
                {
                    cout << refArray[index] << " ";
                }
            }
        }
        // If there is no more remaining, end the loop.
        else if (amountRemaining == 0)
        {
            break;
        }
    }
}
