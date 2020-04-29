////////////////////////////////////////////////////////////////////////////////////////////////////////
// Project 4a: Simple array manipulations                                                             //
// This program is used to sort and display arrays in different way. An array is copied from another  //
// array and is displayed in rotated order, and then in reverse order of the original array.          //
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

void showArray(/* in */ int[], /* in */ int);                             // Function to print array elements
void shiftArray(/* in */ const int[], /* iOut */ int[], /* in */ int);    // Function that shifts each element in the array by one to the right
void reverseArray(/* in */ const int[], /* inOut */ int[], /* in */ int); // Function to reverse order of array ** size of array must be odd **

int main()
{
    // Declare and initialize variables
    const int ARRAY_SIZE = 7;                       // Size of array
    int array1[ARRAY_SIZE] = {4, 7, 2, 8, 1, 3, 0}; // Array with initialize size and elements
    int array2[ARRAY_SIZE];                         // Array to be used for function assignments

    // Display message and call functions
    cout << "Output of array1 with numbers\n";
    showArray(array1, ARRAY_SIZE);

    cout << "Output of array2 with elements shifted by one to the right\n";
    shiftArray(array1, array2, ARRAY_SIZE);

    cout << "Output of array2 in reverse order\n";
    reverseArray(array1, array2, ARRAY_SIZE);
}

//***********************
// Function definitions *
//***********************

//***********************************************
// Function to print elements in array.         *
// Simply iterates through the array and prints *
// each element.                                *
//***********************************************
void showArray(/* in */ int someArray[], /* in */ int size)
{
    // Pre:     Creates a for loop to iterate through array
    // Post:    Prints each element in array and an endl after loop is complete
    for (unsigned index = 0; index < size; index++)
    {
        cout << someArray[index] << " ";
    }
    cout << "\n";
}

//***********************************************
// Function that shifts each element in an      *
// array one unit to the right.                 *
// This function takes to array arguments and   *
// Take the refArray and someArray and assign   *
// someArray with the refArray[n - 1].          *
// someArray[0] is assigned with the last value *
// of refArray depicting the array has looped   *
// to the first subscript. Loop is repeated     *
// until array is completed and all values have *
// been assigned, "rotating" array one to the   *
// right.                                       *
//***********************************************
void shiftArray(/* in */ const int refArray[], /* inOut */ int someArray[], /* in */ int size)
{
    // Pre:     Take the refArray and someArray and assign someArray with the refArray[n-1]
    // Post:    someArray[0] is assigned with the last value of refArray depicting the array has looped to the first subscript.
    //          Loop is repeated until array is completed and all values have been assigned, "rotating" array one to the right.
    // Declare variables

    // Being loop
    for (unsigned index = 0; index < size; index++)
    {
        if (index == 0)
            someArray[index] = refArray[size - 1];
        else
            someArray[index] = refArray[index - 1];
    }
    // Print array
    showArray(someArray, size);
}

//************************************************
// Function to reverse the order of the array.   *
// This function finds the middle subscript and  *
// assigns the elements next the middle with the *
// refArray element. Each iteration increases,   *
// and decreases the respective positions from   *
// the middle and assigns the elements from the  *
// refArray to the second.                       *
//************************************************
void reverseArray(/* in */ const int refArray[], /* inOut */ int someArray[], /* in */ int size)
{
    // Pre:    Variable is created and initialize with the middle subscript and is used for the for loop
    // Post:   The for loop swaps the elements on both sides of the middle position. After each iteration
    //         each position is incremented and decremented further from the middle until the loop completes.
    // Declare variables
    int middle = size / 2;

    // Begin loop
    for (unsigned index = 0; index <= middle; index++)
    {
        someArray[middle - index] = refArray[middle + index];
        someArray[middle + index] = refArray[middle - index];
    }
    // Print array
    showArray(someArray, size);
}
