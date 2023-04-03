// Made by Calvin Thornberg on 03/02/22 finished on 03/23/22
// PA5-B-MkI
// Desc: Yahtzee 

#include "function.h"
int option1 = 1; // Clear terminals
int option2 = 1; // Write protect redo- when disabled (0) write protection cant be removed once a dice is put under it. Initially this was the only game mode until I...
// ...read that Yahtzee allowed you to roll dice previously saved. I added this option to allow players to roll dice that were previously under WP, but the original game mode can be played if desired
int option3 = 0; // Test mode- dice can be entered in manually 

void main() {
	int iii = 4;
	Title_Print();
	// Settings Options Variables
	//scanf("%d", &SystemCLSoption);

	// Enabled SystemCLSoption to keep past rolls from dissapearing after each roll
	// WriteprotectionRedo when disabled (0) allows you to change dice even if you put it under write protection previously
	// testmode when disabled lets user set their own dice values for testing purposes
	
	{
		int Uselec = -1, Uselec2 = -1; // User selection 2 is for navigating sub menus
		int Gameprogressioncounter = 1, Playerturn = 1, Subroundcounter = 1, Writeprotects = 5;
		// Gameprogression counter counts total rounds played
		// Player turn alternates between 1 and 2
		// Subroundcounter counts number of rolls in a round
		// Writeprotects indicates how many dice aren't under write protection

		int finalscorep1 = 0, finalscorep2 = 0;

		srand((unsigned int)time(NULL));
		int Howmanydievals[7] = { 0,0,0,0,0,0,0 }; // keeps track of the number of dice per number
		int Dieroll[5]; // what each dice is
		int DieRollCancel[5] = { 1,1,1,1,1 }; // Write protection, the absence (ie 0) indicates
		// that something is under write protection and cant be recorded over


		// Color key [score][color 1 is green and unused color 0 is red has write protection
		int playerOnestatus[14][2] = { {0,1}, //1
			{0,1}, // twos
			{0,1}, // threes
			{0,1}, // fours
			{0,1}, // fives
			{0,1}, // sixes
			{0,1}, // three of a kind
			{0,1}, // four of a kind
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,0} }; // The first 0 is the score of the item, the second 0 is the write protect status
		int playerTwostatus[14][2] = { {0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,1},
			{0,0} }; // The first 0 is the score of the item, the second 0 is the write protect status

		while (1 > 0) {
			Menu_Print();
			scanf("%d", &Uselec);
			switch (Uselec) {
			case PLAY: // Uselec == 1 ///////////////////////////// start of game
				while (Gameprogressioncounter != 27) {

					while (Subroundcounter < 4) {

						arrayreset(&Howmanydievals, 7, 0);
						//printf("Player %d\tRoll: %d", Playerturn, Subroundcounter);
						if (Playerturn == 1) {
							gettotalscore(&playerOnestatus);

							printscorestatus(playerOnestatus, 1, Subroundcounter, Gameprogressioncounter);
						}
						else {
							gettotalscore(&playerTwostatus);

							printscorestatus(playerTwostatus, 2, Subroundcounter, Gameprogressioncounter);
						}

						RollDie(DieRollCancel, &Dieroll);
						/*if (option2 == 1) {
							arrayreset(&DieRollCancel, 5, 1);
							Writeprotects = 5;
						}*/

						
						arrayreset(&Howmanydievals, 7, 0);
						if(option3 == 1)
							Test_Mode(&Dieroll); // Uncomment to individually manipulate dice
						printDiceval(Dieroll, &Howmanydievals, DieRollCancel);
						for (int z = 0; z < 6; z++) {
							printf("\nDie value %d : %d", z + 1, Howmanydievals[z]);

						}
						if (Subroundcounter < 3) {
							if (option2 == 0) { // Option 2 when enabled (1) it allows players to remove write protection from dice, if its off then write protection isn't removable
								setWriteprotect(&DieRollCancel, Writeprotects); // Sending writeprotects into the function means that if 2 dice are under write protection and 3 is entered, then the program automatically goes straight to asking for combos
							}
							else {
								setWriteprotect(&DieRollCancel, 6); // This is six because it is possible that a player has 4 dice under WP and wants to remove WP from all 4 dice while putting the last dice under WP
							}

						}
						
						Writeprotects = 5;
						for (int i = 0; i < 5; i++) {
							
							if (DieRollCancel[i] == 0) {
								Writeprotects--;
							}
							if (option2 == 1) {
								if (DieRollCancel[i] == 1)
									Writeprotects++;
							}
							
						}
						if ((Writeprotects == 0) || (Subroundcounter + 1 >= 4)) {
							if (Playerturn == 1) {
								Uselec = getcombochoice(&playerOnestatus, Howmanydievals);
								Score_the_Selection(&playerOnestatus, Howmanydievals, Dieroll, Uselec);
							}
							else {
								Uselec = getcombochoice(&playerTwostatus, Howmanydievals);
								Score_the_Selection(&playerTwostatus, Howmanydievals, Dieroll, Uselec);

							}
							Subroundcounter = 7;
						}

						Subroundcounter++;
					}

					Subroundcounter = 1;
					Writeprotects = 5;
					arrayreset(&DieRollCancel, 5, 1);
					if (Playerturn == 1) {
						Playerturn = 2;
					}
					else {
						Playerturn = 1;
					}

				
					Gameprogressioncounter++;
				}

				gettotalscore(&playerOnestatus);
				gettotalscore(&playerTwostatus);
				system("cls");
				if (playerOnestatus[13][0] > playerTwostatus[13][0]) {
					printf("\033[0;31m");
					printf("\tPlayer one wins!");
				}else if (playerOnestatus[13][0]< playerTwostatus[13][0]){
					printf("\033[0;34m");
					printf("\t\tPlayer two wins!");
				}
				else {
					Color_det(4);
					printf("It's a tie!");
				}
				Color_det(4);
				printf("\n \t \tFinal score\n\033[0;31mPlayer one: %d\t\t\033[0;34mPlayer two: %d \n \t \t", playerOnestatus[13][0], playerTwostatus[13][0]);
				printf("\033[0;37m");
				system("pause");

				Gameprogressioncounter = 1, Playerturn = 1, Subroundcounter = 1, Writeprotects = 5;
				TwoDiArrayReset(&playerOnestatus);
				TwoDiArrayReset(&playerTwostatus);
				
				break;
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case INSTRUCTION: // Uselec == 2 // DONE
				Rule_Print();
				system("cls");
				break;
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case OPTION: // Uselec == 3
				//printf("This is not used returned to menu");
				Uselec2 = -1; // Initially Uselec2 is set to -1 OUTSIDE the while loop, so if you open options and exit Uselec2 is permanently set to 4 and you'll be unable to open options again
				while (Uselec2 != 4) {
					Option_Print();
					scanf("%d", &Uselec2);

					if (Uselec2 == 1) {
						
						if (option1 == 1) {
							option1 = 0;
						}
						else {
							option1 = 1;
						}
					}
					
					if (Uselec2 == 2) {

						if (option2 == 1) {
							option2 = 0;
						}
						else {
							option2 = 1;
						}
					
					
				    if (Uselec2 == 3) {
							if (option3 == 1) {
								option3 = 0;
							}
							else {
								option3 = 1;
							}
						}
					}
					if (Uselec2 == 3) {
						if (option3 == 1) {
							option3 = 0;
						}
						else {
							option3 = 1;
						}
					}
				}
				system("cls");
				break;
			case EXIT: // Uselec == 4 // DONE
				iii = -1;
				return 0;
				break;
			default:
				printf("Invalid input in main switch");
			}

		} while (iii > 0);
	}while (iii > 0);
}