#include <stdio.h>
#include <stdlib.h>
#include "useful.h"
#include "pal.h"


int main()
{
   //runTest();
   start_game();
}

void start_game()
{
    int numberOfDigits = getNumberOfDigits();
    int listOfNumbers[numberOfDigits];
    //int listOfNumbers = (int*) malloc(numberOfDigits * sizeof(int));
    getListOfNum(listOfNumbers, numberOfDigits);
    int positionOfCursor = getPosOfCursor(positionOfCursor , numberOfDigits);
    int numberOfTries = 0;
    char command;


    boolean result = False;
    result = is_palindrome(listOfNumbers , numberOfDigits);
	while (result == False)
    {
        //printf("\nBefore:");
        displayState(listOfNumbers, &positionOfCursor, numberOfDigits, numberOfTries);
        command = getCommand();
        processCommand(&listOfNumbers, &positionOfCursor, numberOfDigits, command);
        result = is_palindrome(listOfNumbers , numberOfDigits);
        //printf("\nAfter:");
        displayState(listOfNumbers, &positionOfCursor, numberOfDigits, numberOfTries);
        numberOfTries++;
    }
    printf("You made %d number of moves", numberOfTries);
    free(listOfNumbers);
}

void runTest()
{
    int listOfNumbers[] = {1,1,1,1,1,1};
    int number_of_digits = 6;
    int positionOfCursor = 0;
    int numberOfGoes = 0;

    printf("Address:   %p  ", listOfNumbers);
    printf("Cursor:   %d \n", positionOfCursor);

    is_palindrome(listOfNumbers , number_of_digits);
    displayState(listOfNumbers, &positionOfCursor, number_of_digits, numberOfGoes);
    moveCursorRight(&positionOfCursor, number_of_digits);
    displayState(listOfNumbers, &positionOfCursor, number_of_digits, numberOfGoes);
    moveCursorLeft(&positionOfCursor, number_of_digits);
    displayState(listOfNumbers, &positionOfCursor, number_of_digits, numberOfGoes);
    moveCursorLeft(&positionOfCursor, number_of_digits);
    displayState(listOfNumbers, &positionOfCursor, number_of_digits, numberOfGoes);

    incrementDigitInListAtPos(listOfNumbers, positionOfCursor);
    displayState(listOfNumbers, &positionOfCursor, number_of_digits, numberOfGoes);
    //decrementDigitInListAtPos(listOfNumbers, positionOfCursor);
    displayState(listOfNumbers, &positionOfCursor, number_of_digits, numberOfGoes);

    decrementDigitInListAtPos(listOfNumbers, positionOfCursor);
    moveCursorRight(&positionOfCursor, number_of_digits);
    decrementDigitInListAtPos(listOfNumbers, positionOfCursor);
    displayState(listOfNumbers, &positionOfCursor, number_of_digits, numberOfGoes);
    decrementDigitInListAtPos(listOfNumbers, positionOfCursor);
    displayState(listOfNumbers, &positionOfCursor, number_of_digits, numberOfGoes);
    decrementDigitInListAtPos(listOfNumbers, positionOfCursor);
    displayState(listOfNumbers, &positionOfCursor, number_of_digits, numberOfGoes);

    is_palindrome(listOfNumbers , number_of_digits);
}






