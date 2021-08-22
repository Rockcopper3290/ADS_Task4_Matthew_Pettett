#include <iostream>
#include <string>
#include <fstream> // Read/Write .txt files
#include <cstdlib> // rand function
#include <ctime> // time to seed the RNG

#include "TTT.h" //TTT stands for Tic Tac Toe and not "Trouble in Terrorist Town"

using namespace std;

int main()
{
	TTT tttGame;

	// overall declaration of if the game/program is still runing
	bool gameIsRunning = true;

	int playerTurn;
	srand(time(0));
	do
	{
		// the 0 element in the array is just a null value
		char TTT_markerLocation[10] = { 'N', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

		// If a game is in the middle of being played, will be set to true
		bool isGameInProgress = false;

		// Is used to display correct message if the game ends in a draw
		bool endedAsDraw = false;


		// what gamemode does the player want to pay
		// Gamemodes:
		// 1: PvP
		// 2: PvC
		// 3: CvC
		// 4: Exit


		// Data Valadation
			// If the player inputs anything other then a location on the board or exit
			// the below code will stop any unforeseen issues
		int gamemode = 0;
		bool invaldInput = false;
		while (cin.fail() || (gamemode < 1 || gamemode > 4))
		{
			system("CLS");

			if (invaldInput)
			{
				cout << "\n\t!!That was an invalid input!!";
				cout << "\n\t !Please make a valid input!" << endl;
			}

			cout << "\n\t Gamemode Selection:";
			cout << "\n\t1 -> Player Vs Player";
			cout << "\n\t2 -> Player Vs Computer";
			cout << "\n\t3 -> Computer Vs Computer";
			cout << "\n\t4 -> Quit Game";
			cout << "\n";
			cout << "\n\tWhat game mode would you like to play?\n" << endl;
			cin >> gamemode;

			// Data Valadation
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
			invaldInput = true;
		}

		if (gamemode == 1)
		{
			do
			{
			// 1: PvP
			// Random Number Generator that randomly assigns who is going to make the first move
				playerTurn = 1 + (rand() % 2);
			isGameInProgress = true;
			tttGame.PvP_Gamemode(TTT_markerLocation, playerTurn, gameIsRunning, isGameInProgress, endedAsDraw);
			} while (gameIsRunning);
		}
		if (gamemode == 2)
		{
			do
			{
			// 2: PvC
			// Random Number Generator that randomly assigns who is going to make the first move
			playerTurn = 1 + (rand() % 2);
			isGameInProgress = true;
			tttGame.PvC_Gamemode(TTT_markerLocation, playerTurn, gameIsRunning, isGameInProgress, endedAsDraw);
			} while (gameIsRunning);
		}
		if (gamemode == 3)
		{
			// 3: CvC
			do
			{
				// 2: PvC
				// Random Number Generator that randomly assigns who is going to make the first move
				playerTurn = 1 + (rand() % 2);
				isGameInProgress = true;
				tttGame.CvC_Gamemode(TTT_markerLocation, playerTurn, gameIsRunning, isGameInProgress, endedAsDraw);
			} while (gameIsRunning);
		}
		if (gamemode == 4)
		{
			// 4: Exit
			// Game exits with nothing to be done.
			gameIsRunning = false;
		}

		if (!gameIsRunning)
		{
			// Checks if the player wants to keep playing or change the game mode
			tttGame.quitGameConfirmation(gameIsRunning);
		}

	} while (gameIsRunning);

    system("Pause");
};
