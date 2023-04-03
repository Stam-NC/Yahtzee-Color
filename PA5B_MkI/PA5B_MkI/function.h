#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define PLAY  1
#define INSTRUCTION  2
#define OPTION  3
#define EXIT 4

#define ONES 0
#define TWOS 1
#define THREES 2
#define FOURS 3
#define FIVES 4
#define SIXES 5
#define THREEOFAKIND 6
#define FOUROFAKIND 7
#define FULLHOUSE 8
#define SMALLSTRAIGHT 9
#define LARGESTRAIGHT 10
#define YAHTZEE 11
#define CHANCE 12
#define PI 3.141592

extern int option1;
extern int option2;
extern int option3;

void Title_Print(); // Prints title screen returns nothing

void Menu_Print(); // Prints menu returns nothing

void Rule_Print(); // Prints rules returns nothing

void Option_Print(); // Prints options, lets user select several options like game modes and test mode

void LongLineDraw(int ingersoll); // Sets line color to white, draws a line

void printscorestatus(int scoringstatus[14][2], int maxell, int rolls, int progression); // 13 columns 2 deep to show if its been used and what it scored if it was

void Color_det(int writeprotect); // This updates the color of the text to show if something is under write protect, red if 0 green if 1

int* RollDie(int dieRollCancel[], int* dieroll[]); // Rolls die, dierrollcancel stops a certain die from being changed if it is under write protection

void* printDiceval(int dieroll[], int* howmanydievals[], int diecancel[]); // This prints dice value

int* setWriteprotect(int* dieRollCancel[], int writeprotectsleft); // Sets write prtection and automatically ends round when all dice are write protected

int* arrayreset(int* ATR[], int length, int num); // ATR array to reset; length is number of values not the final index num

void* gettotalscore(int playerOnestatus[14][2]); // Gets player's total score

int* getcombochoice(int playerstatus[14][2],int howmanydievals[]); // Gets and checks a player combo and whether its been used

void* Score_the_Selection(int playerscorestatus[14][2], int howmanydievals[], int dieroll[], int uselec); // This will score the combo, all checking for validity of user selection is in getcombochoice

int Get_Total(int arrayadded[], int length); // adds and array, this is used for several of the combos

void* Test_Mode(int* dieroll[]); // This is for testing purposes and allows individual dice to be selected

void* TwoDiArrayReset(int a[14][2]); // resets 2d arrays

