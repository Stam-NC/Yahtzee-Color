#include "function.h"
void Title_Print() {
	printf("\t\tYahtzee\n");
	printf("     \t     \033[0;31m %c\033[0;32m %c\033[0;34m %c\033[0;37m COLOR\n\n\t",219, 219, 219);
	system("pause");
	system("cls");
}


void Menu_Print() {	
	printf("Yahtzee| Enter the index number\n"
		"1 -- Play Game\n"
		"2 -- Instructions\n"
		"3 -- Options\n"
		"4 -- Exit\n");

	LongLineDraw(205);
	printf("%c", 178);
	return 0;
}
void Rule_Print() {
	system("cls");
	printf("2. | Instructions\n");
	
	LongLineDraw(205);
	printf("\n|Name          |Combination                   |Score\n");
	LongLineDraw(205);
	printf("Three of a kind| Three dice with same face    | Sum of all face values on 5 dice\n");
	LongLineDraw(205);
	printf("Four of a kind | Four dice with same face     | Sum of all face values on 5 dice\n");
	LongLineDraw(205);
	printf("Full house     | One pair and a 3 of a kind   | 25\n");
	LongLineDraw(205);
	printf("Small straight | A sequence of four dice      | 30\n");
	LongLineDraw(205);
	printf("Large straight | A sequence of five dice      | 50\n");
	LongLineDraw(205);
	printf("Yahtzee        | Five of a kind               | 50\n");
	LongLineDraw(205);
	printf("Chance         | May be used for any sequence | Sume of all face values on 5 dice\n");
	LongLineDraw(205);
	system("pause");
}

void Option_Print() { // Typical options page
	system("cls");
	printf("3. | Options\tEnter index number to change option\t");
	Color_det(1);
	printf("ON");
	Color_det(2);
	printf("/");
	Color_det(0);
	printf("OFF\n");
	LongLineDraw(205);

	Color_det(option1); // Enabled (1) by default
	printf("1 -- Clean terminals: when enabled this clears the terminal after every roll\n"); // Keeps previous turns for checking functionality
	Color_det(option2); // Enabled (1) by default
	printf("2 -- Write Protection Redo: write protection that resets every roll\n"); // A game mode based off of a mis-interpretation of the rules of the game
	Color_det(option3); // Disabled (0) by default
	printf("3 -- Test Mode: allows the user to choose dice vals after every roll\n"); // For testing ability to score and test combos
	Color_det(2); // Sets color back to white
	printf("4 -- Back to main menu\n");
}

void LongLineDraw(ingersoll) { // ingersoll is a number corresponding to ascii value
	int HighStandard = -1; // TDK
	printf("\033[0;37m");
	do {
		printf("%c", ingersoll);
		HighStandard++;
	} while (HighStandard < 90);
	printf("\n");
}

void printscorestatus(int scoringstatus[14][2], int maxell, int rolls, int progression) { // score writeprotect
	int i = 3;
	if(option1 ==1)
		system("cls");
	printf("Name          \t   |Score \t|Name\t    \t   |Score\n");
	LongLineDraw(196);
	Color_det(scoringstatus[0][1]);
	printf("1.  Ones           |%d\t\t",scoringstatus[0][0]);
	//LongLineDraw(196);
	Color_det(scoringstatus[1][1]);
	printf("|2.  Twos          |%d\n", scoringstatus[1][0]);
	LongLineDraw(196);

	Color_det(scoringstatus[2][1]);
	printf("3.  Threes         |%d\t\t", scoringstatus[2][0]);
	//LongLineDraw(196);
	Color_det(scoringstatus[3][1]);
	printf("|4.  Fours         |%d\n", scoringstatus[3][0]);
	LongLineDraw(196);

	Color_det(scoringstatus[4][1]);
	printf("5.  Fives          |%d\t\t", scoringstatus[4][0]);
	//LongLineDraw(196);
	Color_det(scoringstatus[5][1]);
	printf("|6.  Sixes         |%d\n", scoringstatus[5][0]);
	LongLineDraw(196);

	Color_det(scoringstatus[6][1]);
	printf("7.  Three of a kind|%d\t\t", scoringstatus[6][0]);
	//LongLineDraw(196);
	Color_det(scoringstatus[7][1]);
	printf("|8.  Four of a kind|%d\n", scoringstatus[7][0]);
	LongLineDraw(196);

	Color_det(scoringstatus[8][1]);
	printf("9.  Full House     |%d\t\t", scoringstatus[8][0]);
	//LongLineDraw(196);
	Color_det(scoringstatus[9][1]);
	printf("|10. Small straight|%d\n", scoringstatus[9][0]);
	LongLineDraw(196);

	Color_det(scoringstatus[10][1]);
	printf("11. Large straight |%d\t\t", scoringstatus[10][0]);
	//LongLineDraw(196);
	Color_det(scoringstatus[11][1]);
	printf("|12. Yahtzee       |%d\n", scoringstatus[11][0]);
	LongLineDraw(196);

	Color_det(scoringstatus[12][1]);
	printf("13. Chance         |%d\t\t", scoringstatus[12][0]);
	Color_det(2);
	printf("|Total    \t   |%d\n", scoringstatus[13][0]);
	LongLineDraw(205);
	printf("Player: %d\tRolls Left: %d\tRound: %d\n", maxell, 3-rolls, progression);
	LongLineDraw(205);

	// colors red = \033[0;31m  green \033[0;32m blue \033[0;34m 
	// white  \033[0;37m
}

void Color_det(int writeprotect) {
	switch (writeprotect) {
	case 0: // red
		printf("\033[0;31m");
		break;
	case 1: // green
		printf("\033[0;32m");
		break;
	case 2: // White reserved only for the total value
		printf("\033[0;37m");
		break;
	default:
		printf("\033[0;33m"); // You see yellow, you went wrong fella
	}
}




int* RollDie(int dieRollCancel[], int dieroll[]) { // This will roll the dice, but only if the corresponding write protect value is equal to 1

	int v = 0;
	if (dieRollCancel[0] == 1) { // wp1
		v = rand() % 6 + 1;
		dieroll[0] = v;
	}

	if (dieRollCancel[1] == 1) {
		v = rand() % 6 + 1;
		dieroll[1] = v;
	}

	if (dieRollCancel[2] == 1) {
		v = rand() % 6 + 1;
		dieroll[2] = v;
	}

	if (dieRollCancel[3] == 1) {
		v = rand() % 6 + 1;
		dieroll[3] = v;
	}

	if (dieRollCancel[4] == 1) {
		v = rand() % 6 + 1;
		dieroll[4] = v;
		v = rand() % 6 + 1;
	}


	return 0;
}

void* printDiceval(int dieroll[], int howmanydievals[], int diecancel[]){ // This displays the latest dice roll and uses the write protect to show whether it is changable
	int ingersoll = -1;
	for (int i = 0; i < 5; i++) {
		Color_det(diecancel[i]);
		printf(" die %d: %d\t", i + 1, dieroll[i]);
		switch (dieroll[i]) {
		
		case 1: // for 1
			howmanydievals[0]++;
			break;
		case 2: // for 2
			howmanydievals[1]++;
			break;
		case 3: // for 3
			howmanydievals[2]++;
			break;
		case 4: // for 4
			howmanydievals[3]++;
			break;
		case 5: // for 5
			howmanydievals[4]++;
			break;
		case 6: // for 6
			howmanydievals[5]++;
			break;
		}

	}
	Color_det(2);
}

int* setWriteprotect(int dieRollCancel[], int writeprotectsleft) { // This gets the write protects and will automatically end the round if a number
	//greater than the number of un-writeprotected dice is entered
	int numberofholds = 0; //number of holds means how many dice do they want to keep
	int iteration = 0; // keeps track of loop
	int dicenumber = 0;

	if (writeprotectsleft == 0) {
		printf("\nAll dice are under write protection\n");
		system("pause");
		return 0;
	}
	if (option2 == 0) {
		printf("\nTip: If you want to choose a combo enter any number greater than or equal to 5");
	}
	else {
		printf("\nTip: If you want to choose a combo enter any number greater than or equal to 6");
	}
	printf("\n(enter 0 if you dont want to hold any) How many dice would you like to hold? ");
	scanf("%d", &numberofholds);

	if (numberofholds <= 0)
		return 0;
	if (numberofholds > writeprotectsleft)
		numberofholds = writeprotectsleft;
	
	if (numberofholds == writeprotectsleft) {
		arrayreset(dieRollCancel, 5, 0);
	}
	else {
		while (iteration != numberofholds) {
			printf("\nEnter the dice number you wish to protect (enter 0 if you dont want to write protect any)\n");
			scanf("%d", &dicenumber);
			if (option2 == 1) {
				if (dieRollCancel[dicenumber - 1] == 0) {
					dieRollCancel[dicenumber - 1] = 1;
				}
				else {
					dieRollCancel[dicenumber - 1] = 0;
				}
			}
			else {
				dieRollCancel[dicenumber - 1] = 0;
			}
			iteration++;
		}
	}


}

int* arrayreset(int* ATR[], int length, int num) { // lenght is how many values are in array not the final index num
	int ingersoll = 0;
	while (ingersoll != length) {
		ATR[ingersoll] = num;
		ingersoll++;
	}
	// ATR is Array to be reset, the num arguement is what we are setting it to
}

void* gettotalscore(int playerOnestatus[14][2]) { // This gets the total score by adding everything together
	playerOnestatus[13][0] = playerOnestatus[12][0] + playerOnestatus[11][0]
		+ playerOnestatus[10][0] + playerOnestatus[9][0] + playerOnestatus[8][0]
		+ playerOnestatus[7][0] + playerOnestatus[6][0] + playerOnestatus[5][0]
		+ playerOnestatus[4][0] + playerOnestatus[3][0] + playerOnestatus[2][0]
		+ playerOnestatus[1][0] + playerOnestatus[0][0];
}

int* getcombochoice(int playerstatus[14][2], int howmanydievals[]) { //player status is mod-able 
	int isvalidselec = 1, userselec = 0, holderselection = 0;
	printf("\nChoose the number of a combo you wish to use: ");

	do {
		isvalidselec--;
		if (isvalidselec < 0)
			printf("Invalid selection try again:\n");
		scanf("%d", &userselec);
		if ((userselec <= 13) && (userselec >= 1)) {
			holderselection = playerstatus[userselec - 1][1];
			if (holderselection == 1) {
				isvalidselec = 1;
				playerstatus[userselec - 1][1] = 0; // This updates the player status array so that the combo will no longer be usable 
			}
		}


	} while (isvalidselec != 1);
	userselec--; // user selec will give the exact index of playerscore to modify, no worries about being 1 above the actual index
	return userselec;
	
}

void* Score_the_Selection(int playerscorestatus[14][2], int howmanydievals[], int dieroll[], int uselec) { // This takes the user combo selection and...
	// ...scores it and updates the player status array to show what they got from a certain combo
	int present = 0;
	switch (uselec) {
	
		case ONES:
			playerscorestatus[0][0] = howmanydievals[0] * 1;
			break;
		case TWOS:
			playerscorestatus[1][0] = howmanydievals[1] * 2;
			break;
		case THREES:
			playerscorestatus[2][0] = howmanydievals[2] * 3;
			break;
		case FOURS:
			playerscorestatus[3][0] = howmanydievals[3] * 4;
			break;
		case FIVES:
			playerscorestatus[4][0] = howmanydievals[4] * 5;
			break;
		case SIXES: 
			playerscorestatus[5][0] = howmanydievals[5] * 6;
			break;
		case THREEOFAKIND:
			for (int i = 0; i < 6; i++) {
				if (howmanydievals[i] >= 3)
					playerscorestatus[6][0] = Get_Total(dieroll, 5);
					
			}
			break;
		case FOUROFAKIND:
			for (int i = 0; i < 6; i++) {
				if (howmanydievals[i] >= 4)
					playerscorestatus[7][0] = Get_Total(dieroll, 5);
			}
			break;
		case FULLHOUSE:
			for (int j = 0; j < 6; j++) {
				if ((howmanydievals[j] == 2) || (howmanydievals[j] == 3))
					present++;
				if (present == 2)
					playerscorestatus[8][0] = 25;
			}
			break;
		case SMALLSTRAIGHT:

			for (int j = 0; j < 6; j++) {
				if (howmanydievals[j] >= 1) {
					present++;
				}
				else {
					present = 0;
				}
				if (present == 4)
					playerscorestatus[9][0] = 30;

			}
			break;
		case LARGESTRAIGHT:
			for (int j = 0; j < 6; j++) {
				if (howmanydievals[j] == 1) {
					present++;
				}
				else {
					present = 0;
				}
				if (present == 5)
					playerscorestatus[10][0] = 40;

			}
			break;
		case YAHTZEE:
			for (int j = 0; j < 6; j++) {
				if (howmanydievals[j] == 5)
					playerscorestatus[11][0] = 50;
				
			}
			break;
		case CHANCE:
			for (int j = 0; j < 6; j++) {
				present += howmanydievals[j] * (j + 1);
			}
			playerscorestatus[12][0] = present;
			break;
		default:
			printf("INVALID INPUT IN SCORE THE SELECTION FUNCTION SWITCH");
			break;



	}
}

int Get_Total(int arrayadded[], int length) { // gets sum of array
	int total = 0;
	for (int reddog = 0; reddog < length; reddog++ ) {
		total += arrayadded[reddog];
	}
	return total;
}

void* Test_Mode(int dieroll[]) { // Only used for testing, and be enabled by un-commenting a line somewhere
	printf("testmode- IP\n");
	scanf("%d", &dieroll[0]);
	if ((dieroll[0] < 1) || (dieroll[0] > 6)) // Idiot Protected
		dieroll[0] = 3;


	scanf("%d", &dieroll[1]);
	if ((dieroll[1] < 1) || (dieroll[1] > 6))
		dieroll[1] = 3;

	scanf("%d", &dieroll[2]);
	if ((dieroll[2] < 1) || (dieroll[2] > 6))
		dieroll[2] = 3;


	scanf("%d", &dieroll[3]);
	if ((dieroll[3] < 1) || (dieroll[3] > 6))
		dieroll[3] = 3;
	


	scanf("%d", &dieroll[4]);
	if ((dieroll[4] < 1) || (dieroll[4] > 6))
		dieroll[4] = 3;
}

void* TwoDiArrayReset(int a[14][2]) {
	a[0][0] = 0; // Nested loops would of been better 
	a[1][0] = 0;
	a[2][0] = 0;
	a[3][0] = 0;
	a[4][0] = 0;
	a[5][0] = 0;
	a[6][0] = 0;
	a[7][0] = 0;
	a[8][0] = 0;
	a[9][0] = 0;
	a[10][0] = 0;
	a[11][0] = 0;
	a[12][0] = 0;
	a[13][0] = 0;
	//a[14][0] = 0;
	a[0][1] = 1;
	a[1][1] = 1;
	a[2][1] = 1;
	a[3][1] = 1;
	a[4][1] = 1;
	a[5][1] = 1;
	a[6][1] = 1;
	a[7][1] = 1;
	a[8][1] = 1;
	a[9][1] = 1;
	a[10][1] = 1;
	a[11][1] = 1;
	a[12][1] = 1;
	a[13][1] = 1;
	//a[14][0] = 1;
}