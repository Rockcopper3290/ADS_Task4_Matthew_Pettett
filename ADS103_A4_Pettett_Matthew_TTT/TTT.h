#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // rand function
#include <ctime> // time to seed the RNG
#include <vector>

using namespace std;
class TTT
{

public:
	

	// Displays Tic Tac Toe (TTT for short) board
	void displayScreen(char TTT_markerLocation[10], int playerTurn, bool isPlaying_PvC);

	void playerMoveCheck(char TTT_markerLocation[10], int playerTurn, bool &gameIsRunning, bool isGameInProgress, bool& endedAsDraw, bool isPlaying_PvC);
	void requestValidInput(char TTT_markerLocation[10], int playerTurn, int &playerInput, bool isGameInProgress, bool isPlaying_PvC);
	void alternatePlayerTurn(int &playerTurn);

	// Gamemodes
	void PvP_Gamemode(char TTT_markerLocation[10], int playerTurn, bool &gameIsRunning, bool isGameInProgress, bool& endedAsDraw);
	void PvC_Gamemode(char TTT_markerLocation[10], int playerTurn, bool& gameIsRunning, bool isGameInProgress, bool& endedAsDraw);
	void CvC_Gamemode(char TTT_markerLocation[10], int playerTurn, bool& gameIsRunning, bool isGameInProgress, bool& endedAsDraw);

	// Com checks if there are 2 of any markers in a row and places a 
	// computer marker to complete the row
	void COM_winLossCheck(char TTT_markerLocation[10], int playerTurn, bool& gameIsRunning);

	// checks if a move will grant com a win
	// & checks if a move will prevent opponent from winning 
	void COM_turn(char TTT_markerLocation[10], int playerTurn, bool& gameIsRunning, bool& hasTakenTurn);

	// Checks the board for if it matches with win condition
	void checkWinCon(char TTT_markerLocation[10], bool& gameIsRunning, bool& endedAsDraw);

	//anounces the winner ans askes if they want to play again
	void anounceWinner(char TTT_markerLocation[10], bool& gameIsRunning, int playerTurn, bool& endedAsDraw, bool isPlaying_PvC);
	
	// Checks if the player wants to keep playing or change the game mode
	void quitGameConfirmation(bool& gameIsRunning);

	// Resets the playing board so that multiple games can be played back to back
	void resetBoard(char TTT_markerLocation[10]);

	// Error message if .txt file can't be opened
	void fileOpenedCheck_errorMessage(string textFileName)
	{
		cout << "\t!!ERROR!!" << endl;
		cout << "\tText file named '" << textFileName << "' was unable to be opened." << endl;
		exit(1);
	};

	//reads the score card values
	void getScoreCardValues(vector<int>& scoreCardStorage);

	//updates the score card values
	void updateScoreCardValues(vector<int> scoreCardStorage, bool endedAsDraw, int playerTurn);
};

