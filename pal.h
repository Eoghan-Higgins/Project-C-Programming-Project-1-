#ifndef PAL_H_INCLUDED
#define PAL_H_INCLUDED

displayState(int* pListOfNumbers,  int  positionOfCursor, int number_of_digits, int numberOfGoes);
void moveCursorRight ( int* pPosOfCursor, int max);
void incrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor);
void decrementDigitInListAtPos(int* pListOfNumbers, int positionOfCursor);
boolean is_palindrome(int* plist_of_numbers, int size);
void processCommand(int* pList, int size, int* pPositionOfCursor, char command);
char getCommand();

#endif // PAL_H_INCLUDED
