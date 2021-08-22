#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // rand function
#include <ctime> // time to seed the RNG

using namespace std;
class TTT
{

public:
	

	// Displays Tic Tac Toe (TTT for short) board
	void displayScreen(char TTT_markerLocation[10], int playerTurn);

	void playerMoveCheck(char TTT_markerLocation[10], int playerTurn, bool &gameIsRunning, bool isGameInProgress, bool& endedAsDraw);
	void requestValidInput(char TTT_markerLocation[10], int playerTurn, int &playerInput, bool isGameInProgress);
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
	void anounceWinner(char TTT_markerLocation[10], bool& gameIsRunning, int playerTurn, bool& endedAsDraw);
	
	// Checks if the player wants to keep playing or change the game mode
	void quitGameConfirmation(bool& gameIsRunning);

	// Resets the playing board so that multiple games can be played back to back
	void resetBoard(char TTT_markerLocation[10]);
};

