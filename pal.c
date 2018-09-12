#include "useful.h"
//#include "pal.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
displayState(int* pListOfNumbers, int*  positionOfCursor, int number_of_digits, int numberOfGoes)
{
	printf("\n\nGame State:\n");
	// Add code to display all the numbers in the array later
	int i = 0;
	//printf("%d", number_of_digits);
	while (i < number_of_digits)
    {
        printf("%d ", pListOfNumbers[i]);
        i++;
    }
    printf("  Cursor:  %d", *positionOfCursor);
    printf("  Number Of Goes %d\n", numberOfGoes);
    i = 0;
    while (i < *positionOfCursor)
    {
        printf("  ");
        i++;
    }
    printf("^");
	// Use  *pListOfNumbers or pListOfNumbers[0] to access the first item
     // in the array

}
void moveCursorRight( int* pPosOfCursor, int max)
{

	int cur = *pPosOfCursor;
	if (cur < max - 1)
    {
        cur++;
    }
    *pPosOfCursor = cur;
}
void moveCursorLeft( int* pPosOfCursor , int max)
{

    int cur = *pPosOfCursor;
    if (cur > 0)
    {

        cur--;
    }
    *pPosOfCursor = cur;
}
void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor)
{
    if (pListOfNumbers[positionOfCursor] < 9)
    {
        pListOfNumbers[positionOfCursor]++;
    }
    else if (pListOfNumbers[positionOfCursor] == 9)
    {
        pListOfNumbers[positionOfCursor] = 0;
    }

}
void decrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor)
{
    if (positionOfCursor != 0)
    {
        if (pListOfNumbers[positionOfCursor] > 0)
        {
            pListOfNumbers[positionOfCursor]--;
        }
        else if (pListOfNumbers[positionOfCursor] == 0)
        {
            pListOfNumbers[positionOfCursor] = 9;
        }
    }
    else
    {
        if (pListOfNumbers[positionOfCursor] > 1)
        {
            pListOfNumbers[positionOfCursor]--;
        }
    }
}
boolean is_palindrome(int* pList_of_numbers , int size)
{
    int i = 0;
    int j = 1;
    int indenum = 0;
    int num = 0;
    while (i < size)
    {
        indenum = pList_of_numbers[size - 1];
        indenum = indenum * j;
        num = num + indenum;
        j = j * 10;
        size--;
    }
    printf("\n\n%d \n" ,num);

    int reversed = 0;
    int actual = num;
    int remainder = 0;

    while (num != 0)
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }

    boolean a = False;

    if (actual == reversed)
    {
        a = True;
        printf("True");
    }
    else
    {
        a = False;
        printf("False");
    }
    return a;
}

char getCommand()
{
    char validCharacters[4] = { 'a', 'd', 'w', 's'};
    char* result;
    int i = 0;
    boolean check = False;
    printf("\nEnter a command:\nValid commands are a(Move cursor Left) d(Move cursor Right) w(Increase digit at cursor) s(Decrease digit at cursor):");
    //scanf("%c", &result);
    while (check == False)
    {
        result = my_get_char();
        while (i < 4)
        {
            if (result == validCharacters[i])
            {
                check = True;
            }
            i++;
        }
    }

    return result;
}

void processCommand(int* pList,  int* pPositionOfCursor, int size, char command)
{
    if (command == 'a')
    {
        moveCursorLeft(pPositionOfCursor, size);
    }
    else if (command == 'd')
    {
        moveCursorRight(pPositionOfCursor, size);
    }
    else if (command == 'w')
    {
        incrementDigitInListAtPos(pList, *pPositionOfCursor);
    }
    else if (command == 's')
    {
        decrementDigitInListAtPos(pList, *pPositionOfCursor);
    }
}



int getNumberOfDigits(int numberOfDigits)
{
    int result;
    printf("\nEnter number of digits: ");
    scanf("%d", &result);
    fflush(stdin);
    return result;
}
void getListOfNum(int* listOfNumbers, int numberOfDigits)
{
    int i = 0;
    while (i < numberOfDigits)
    {
        printf("Enter digit %d ", i);
        scanf("%d", &listOfNumbers[i]);
        //printf("%d", &listOfNumbers[i]);
        fflush(stdin);
        i++;
    }
}
int getPosOfCursor(int posOfCursor, int numberOfDigits)
{
    int result;
    srand(time(0));
    printf("%d", numberOfDigits);
    result = rand() % numberOfDigits;
    return result;
}

