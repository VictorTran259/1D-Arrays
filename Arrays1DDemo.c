/*
Victor Tran, 9/14/22, CIS 2107
Lab 4 1D Arrays
Part1 [90 points]: (1-Dimensional Array Functions)


1. [18 points] Implement a function called fillArray that fills a one-dimensional array with random integers.
Integers are picked in the range rand_min to rand_max (inclusive.).

Here is a demo of filling an array of 40 elements with integers in the range 0 and 100.

      0   56   19   81   59   48   35   90   83   75
     17   86   71   51   30    1    9   36   14   16
     99   45   12    0    0   38   53   57   60   61
     16   66   45   35    5   61   79   81   52   30


2. [18 points] Implement a function called findWithRange that locates the largest element in a range of the
same array. The range consists of the array cells indexed between indices LOW and HIGH, inclusive.

Decide what your function should do for indexes out of bounds, or if
highSelectedRange < lowSelectedRange.

Here is a demo where lowSelectedRange==10 and highSelectedRange ==19.

      0   56   19   81   59   48   35   90   83   75
     17   86   71   51   30    1    9   36   14   16
     99   45   12    0    0   38   53   57   60   61
     16   66   45   35    5   61   79   81   52   30

  Max = 86



3. [18 points] Implement function called reverseArray that reverses the order of the array elements.

Here is a sample run:

 Original:
      0   56   19   81   59   48   35   90   83   75
     17   86   71   51   30    1    9   36   14   16
     99   45   12    0    0   38   53   57   60   61
     16   66   45   35    5   61   79   81   52   30

 Reversed:
     30   52   81   79   61    5   35   45   66   16
     61   60   57   53   38    0    0   12   45   99
     16   14   36    9    1   30   51   71   86   17
     75   83   90   35   48   59   81   19   56   0


4. [18 points] Implement a function reverseSelectedRangeWithinArray that reverses the order of the
array elements in a range between two indexes, startRange and endRange. Decide what your function
should do for indexes out of bounds, or if endRange < startRange.

Here is a demo:

      0   56   19   81   59   48   35   90   83   75
     17   86   71   51   30    1    9   36   14   16
     99   45   12    0    0   38   53   57   60   61
     16   66   45   35    5   61   79   81   52   30

  Reversing between 15 and 24

      0   56   19   81   59   48   35   90   83   75
     17   86   71   51   30    0    0   12   45   99
     16   14   36    9    1   38   53   57   60   61
     16   66   45   35    5   61   79   81   52   30

5. [18 points] Implement a function called findSequence that looks for Tom and Jerry in sequence among the
array. Return the index of the first element Tom, or -1 if the sequence is not found.

Here is a demo.

 Enter two numbers: 56 19
sequence found at index 1

Enter two numbers: 52 30
sequence found at index 38

Enter two numbers: 61 61
sequence not found



Part2 [10 points]: (Testing inside main)


• Call all functions in part 1 in order to demonstrate successful run.
• Use blank lines to separate outputs and make then more readable.
• Be creative when displaying outputs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MIN 0
#define RAND_MAX 100
//Change the value of SIZE to test different sized arrays.
#define SIZE 40

//Function Prototypes.
void fillArray(int array[], int size);
void findWithRange(int lowSelectedRange, int highSelectedRange, int array[]);
void reverseArray(int array[], int size);
void reverseSelectedRangeWithinArray(int startRange, int endRange, int array[]);
int findSequence(int array[], int size, int Tom, int Jerry);
void printArray(int array[], int size);

int main() {
    //Declaration of of an array with the size SIZE.
    int array[SIZE];

    //Test for the fillArray function.
    printf("Filling the array with random numbers. Here is the result\n\n");
    fillArray(array, SIZE);

    printArray(array, SIZE);

    //Test for the findWithRange function.
    //Change the values for these variables to test different indexes.
    int lowSelectedRange = 10;
    int highSelectedRange = 19;

    printf("\nFinding the largest number between two indexes in the array between indexes %d and %d...\n\n", lowSelectedRange, highSelectedRange);

    //If lowSelectedRange is less than 0 or greater than or equal the size of the array, throws an error message and ends the program.
    if(lowSelectedRange < 0 || lowSelectedRange >= SIZE) {
        printf("ERROR: The index %d for lowSelectedRange is out of bounds. Ending program...\n\n", lowSelectedRange);
        exit(0);
    }

    //If lowSelectedRange is less than 0, greater than or equal the size of the array, or less than the value of lowSelectedRange, throws an error message and ends the program.
    if(highSelectedRange < 0 || highSelectedRange >= SIZE || highSelectedRange < lowSelectedRange) {
        printf("ERROR: The index %d for highSelectedRange is out of bounds or it is lower than the index for lowSelectedRange. Ending program...\n\n", highSelectedRange);
        exit(0);
    }

    printArray(array, SIZE);

    findWithRange(lowSelectedRange, highSelectedRange, array);

    //Test for the reverseArray function.
    printf("Reversing the array...\nOriginal:\n");
    printArray(array, SIZE);

    reverseArray(array, SIZE);

    printf("\nReversed:\n");
    printArray(array, SIZE);

    //Test for the reverseSelectedRangeWithinArray function.
    //Change the values for these variables to test different indexes.
    int startRange = 15;
    int endRange = 24;

    printf("\nReversing between selected indexes %d and %d...\n\n", startRange, endRange);

    //If startRange is less than 0 or greater than or equal the size of the array, throws an error message and ends the program.
    if(startRange < 0 || startRange >= SIZE) {
        printf("ERROR: The index %d for startRange is out of bounds. Ending program...\n\n", startRange);
        exit(0);
    }

    //If endRange is less than 0, greater than or equal the size of the array, or less than the value of lowSelectedRange, throws an error message and ends the program.
    if(endRange < 0 || endRange >= SIZE || endRange < startRange) {
        printf("ERROR: The index %d for endRange is out of bounds or it is lower than the index for startRange. Ending program...\n\n", endRange);
        exit(0);
    }

    printArray(array, SIZE);

    printf("\n      Reversing between %d and %d\n\n", startRange, endRange);
    reverseSelectedRangeWithinArray(startRange, endRange, array);

    printArray(array, SIZE);

    //Test for the findSequence function.
    //The array at this point is based on the array after the function reverseSelectedRangeWithinArray has been applied to it.
    printf("\nFinding a sequence of two numbers in the array...");
    printf("\nEnter two numbers: ");
    int Tom;
    int Jerry;
    scanf("%d %d", &Tom, &Jerry);

    findSequence(array, SIZE, Tom, Jerry);
}

//Fills the entire array with random numbers ranging from 0 to 100.
void fillArray(int array[], int size) {
    srand((unsigned)time(NULL));

    for(unsigned int i = 0; i < size; i++) {
        array[i]= rand() % (RAND_MAX+1)+ RAND_MIN;
    }
}

//Takes in a user input for lowSelectedRange and highSelected range, finds the largest integer within the lowSelectedRange and highSelectedRange, and then prints out the result.
void findWithRange(int lowSelectedRange, int highSelectedRange, int array[]) {
    int max = 0;

    for(unsigned int i = lowSelectedRange; i <= highSelectedRange; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }

    printf("\n      Max = %d\n\n", max);
}

//Reverses the order of the integers within the entire array.
void reverseArray(int array[], int size) {
    int i = 0;
    int j = size - 1;
    int temp;

    while(i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}

//Takes in a user input for startRange and endRange and reverses the order of the integers within the startRange and endRange.
void reverseSelectedRangeWithinArray(int startRange, int endRange, int array[]) {
    int i = startRange;
    int j = endRange;
    int temp;

    while(i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}

//Iterates through the array and checks if the sequence of two numbers the user entered is present in the array.
//Returns Tom(the first number) if the sequence of two numbers(Tom and Jerry) is present in the array.
//Returns -1 if the sequence of two numbers is not present in the array.
int findSequence(int array[], int size, int Tom, int Jerry) {
    for(unsigned int i = 0; i < size - 1; i++) {
        if(array[i] == Tom && array[i+1] == Jerry){
            printf("sequence found at index %d\n\n", i);
            return Tom;
        }
    }

    printf("sequence not found\n\n");
    return -1;
}

//Prints out the content of the array.
void printArray(int array[], int size) {
    for(unsigned int i = 0; i < size; i++) {
        printf("%8d", array[i]);
        if(i % 10 == 9) {
            printf("\n");
        }
    }
}
