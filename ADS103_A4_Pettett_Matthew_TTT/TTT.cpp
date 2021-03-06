#include "TTT.h"

void TTT::displayScreen(char TTT_markerLocation[10], int playerTurn, bool isPlaying_PvC)
{
    system("cls");

    cout << "\n\tTic Tac Toe\n\n";


    //if the current game mode is PvC
    if (isPlaying_PvC == true)
    {
        vector<int> scoreCardStorage;
        getScoreCardValues(scoreCardStorage);

        cout << "\n\t            Score Board:" << endl;
        cout << "\t  Player 1 (X) --> " << scoreCardStorage[0] << " Points" << endl;
        cout << "\tComputer 2 (O) --> " << scoreCardStorage[1] << " Points" << endl;
        cout << "\t     Draws     --> " << scoreCardStorage[2] << " Points" << endl;
        cout << endl;
    }

    // Current player
    // The boxes surround the active player so that players can quickly
    // tell who's turn it is.
    if (playerTurn == 1)
    {
        cout << " |--------------|                    " << endl;
        cout << " | Player 1 (X) |  -   Player 2 (O) " << endl;
        cout << " |--------------|                    " << endl;
        cout << endl;
    }
    else if (playerTurn == 2)
    {
        cout << "                     |--------------|" << endl;
        cout << "   Player 1 (X)   -  | Player 2 (O) |" << endl;
        cout << "                     |--------------|" << endl;
        cout << endl;
    }
    

    cout << "\t     |     |     " << endl;
    // 1 | 2 | 3
    cout << "\t  " << TTT_markerLocation[1] << "  |  " << TTT_markerLocation[2] << "  |  " << TTT_markerLocation[3] << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;

    // 4 | 5 | 6
    cout << "\t  " << TTT_markerLocation[4] << "  |  " << TTT_markerLocation[5] << "  |  " << TTT_markerLocation[6] << endl;
    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;

    // 7 | 8 | 9
    cout << "\t  " << TTT_markerLocation[7] << "  |  " << TTT_markerLocation[8] << "  |  " << TTT_markerLocation[9] << endl;
    cout << "\t     |     |     " << endl << endl;

    
}

void TTT::playerMoveCheck(char TTT_markerLocation[10], int playerTurn, bool &gameIsRunning, bool isGameInProgress, bool& endedAsDraw, bool isPlaying_PvC)
{
    char originalBoardLayout[10] = { 'N', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    int playerInput;

    bool validMoveMade = false;

    // the Turn symbols are X & O (for p1 and p1) 
    // element 0 ('n') is a null value that is used to make reading and writing the code
    // a bit easier.
    char turnSymbol[3] = { 'n', 'X', 'O' };

    cout << "If you wish to end the game enter '0'" << endl;
    cout << "Please enter where you would like to put a marker (1 - 9): ";
        cin >> playerInput;
    do
    {

        // Data Valadation
        // If the player inputs anything other then a location on the board or exit
        // the below code will stop any unforeseen issues
        while (cin.fail() || (playerInput < 0 || playerInput > 9) || (originalBoardLayout[playerInput] != TTT_markerLocation[playerInput]))
        {
            // Data Valadation
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(1000, '\n');
            }
            requestValidInput(TTT_markerLocation, playerTurn, playerInput, isGameInProgress, isPlaying_PvC);
        }

        // If player enters 0 exit game
        
        if (playerInput == 0) {
        gameIsRunning = false;
        endedAsDraw = true;
        }
        // Replaces the board number with players marker (X/O)
        else if (TTT_markerLocation[playerInput] == originalBoardLayout[playerInput])
        {
            TTT_markerLocation[playerInput] = turnSymbol[playerTurn];
            validMoveMade = true;
        }
        
        

        // End loop if the player gives a valid input location or exits the game
    } while (!validMoveMade && gameIsRunning);

    
}

void TTT::requestValidInput(char TTT_markerLocation[10], int playerTurn, int &playerInput, bool isGameInProgress, bool isPlaying_PvC)
{
    system("CLS");
    if (isGameInProgress)
    {
        displayScreen(TTT_markerLocation, playerTurn, isPlaying_PvC);
    }

    cout << "\n\t!!That was an invalid input!!" << endl;
    cout << "\n\t !Please make a valid input!" << endl;

    cout << "If you wish to end the game enter '0'" << endl;
    cout << "Please enter where you would like to put a marker (1 - 9): ";
    cin >> playerInput;
}

void TTT::alternatePlayerTurn(int &playerTurn)
{
    if (playerTurn == 1) {
        playerTurn = 2;
    }
    else {
        playerTurn = 1;
    }
}

void TTT::PvP_Gamemode(char TTT_markerLocation[10], int playerTurn, bool &gameIsRunning, bool isGameInProgress, bool& endedAsDraw)
{
    bool isPlaying_PvC = false;

    do
    {
        displayScreen(TTT_markerLocation, playerTurn, isPlaying_PvC);
        playerMoveCheck(TTT_markerLocation, playerTurn, gameIsRunning, isGameInProgress, endedAsDraw, isPlaying_PvC);
        checkWinCon(TTT_markerLocation, gameIsRunning, endedAsDraw);

        if (gameIsRunning) {
            alternatePlayerTurn(playerTurn);
        }

    } while (gameIsRunning);
    anounceWinner(TTT_markerLocation, gameIsRunning, playerTurn, endedAsDraw, isPlaying_PvC);
    resetBoard(TTT_markerLocation);
    
}

void TTT::PvC_Gamemode(char TTT_markerLocation[10], int playerTurn, bool& gameIsRunning, bool isGameInProgress, bool& endedAsDraw)
{
    bool isPlaying_PvC = true;

    do
    {
        displayScreen(TTT_markerLocation, playerTurn, isPlaying_PvC);

        // playerTurn 1 or 'X' is always the humans
        if (playerTurn == 1)
            playerMoveCheck(TTT_markerLocation, playerTurn, gameIsRunning, isGameInProgress, endedAsDraw, isPlaying_PvC);

        else if (playerTurn == 2)
            COM_winLossCheck(TTT_markerLocation, playerTurn, gameIsRunning);
        

        checkWinCon(TTT_markerLocation, gameIsRunning, endedAsDraw);

        if (gameIsRunning) {
            alternatePlayerTurn(playerTurn);
        }
    } while (gameIsRunning);
   
    anounceWinner(TTT_markerLocation, gameIsRunning, playerTurn, endedAsDraw, isPlaying_PvC);
    resetBoard(TTT_markerLocation);

}

void TTT::CvC_Gamemode(char TTT_markerLocation[10], int playerTurn, bool& gameIsRunning, bool isGameInProgress, bool& endedAsDraw)
{
    bool isPlaying_PvC = false;
    
    do
    {
        displayScreen(TTT_markerLocation, playerTurn, isPlaying_PvC);

        //COM's move/turn
        COM_winLossCheck(TTT_markerLocation, playerTurn, gameIsRunning);

        checkWinCon(TTT_markerLocation, gameIsRunning, endedAsDraw);

        if (gameIsRunning) {
            alternatePlayerTurn(playerTurn);
        }
    } while (gameIsRunning);

    anounceWinner(TTT_markerLocation, gameIsRunning, playerTurn, endedAsDraw, isPlaying_PvC);
    resetBoard(TTT_markerLocation);
}

/*
*   1   2   3
*   4   5   6
*   7   8   9
*/

void TTT::COM_winLossCheck(char TTT_markerLocation[10], int playerTurn, bool& gameIsRunning)
{
    // used for refrenceing
    char originalBoardLayout[10] = { 'N', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char turnSymbol[3] = { 'n', 'X', 'O' };

    //will check to see if the com has taken its turn
    bool hasTakenTurn = false;

    // checks to see if the random placement was a valid move
    bool validMove = false;

    COM_turn(TTT_markerLocation, playerTurn, gameIsRunning, hasTakenTurn);

    // if no moves were made make a random move
    if (!hasTakenTurn)
    {
    int movePos;
    srand(time(0));

        do
        {

            // Random Number Gen (1 - 9)
            movePos = 1 + (rand() % 9);
            if (TTT_markerLocation[movePos] == originalBoardLayout[movePos])
            {
                validMove = true;
                TTT_markerLocation[movePos] = turnSymbol[playerTurn];
            }
        } while (!validMove);
    }

}

void TTT::COM_turn(char TTT_markerLocation[10], int playerTurn, bool& gameIsRunning, bool& hasTakenTurn)
{
    // the Turn symbols are X & O (for p1 and p1) 
    // element 0 ('n') is a null value that is used to make reading and writing the code
    // a bit easier.
    char turnSymbol[3] = { 'n', 'X', 'O' };
    char originalBoardLayout[10] = { 'N', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    // layout for if statements:
    // 1: connected edges/points
    // 2: connected edges/points
    // 3: opposing edges/points

    int currentMarker;
        currentMarker = playerTurn;

    int loopCount = 0;
    do
    {

        // Top row ( 1 2 3 )
        if (TTT_markerLocation[1] == turnSymbol[currentMarker] && TTT_markerLocation[1] == TTT_markerLocation[2] && TTT_markerLocation[3] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[3] == originalBoardLayout[3]) {
            hasTakenTurn = true;
            TTT_markerLocation[3] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[2] == turnSymbol[currentMarker] && TTT_markerLocation[2] == TTT_markerLocation[3] && TTT_markerLocation[1] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[1] == originalBoardLayout[1]) {
            hasTakenTurn = true;
            TTT_markerLocation[1] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[1] == turnSymbol[currentMarker] && TTT_markerLocation[1] == TTT_markerLocation[3] && TTT_markerLocation[2] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[2] == originalBoardLayout[2]) {
            hasTakenTurn = true;
            TTT_markerLocation[2] = turnSymbol[playerTurn];
        }
        // Middle row ( 4 5 6 )
        else if (TTT_markerLocation[4] == turnSymbol[currentMarker] && TTT_markerLocation[4] == TTT_markerLocation[5] && TTT_markerLocation[6] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[6] == originalBoardLayout[6]) {
            hasTakenTurn = true;
            TTT_markerLocation[6] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[5] == turnSymbol[currentMarker] && TTT_markerLocation[5] == TTT_markerLocation[6] && TTT_markerLocation[4] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[4] == originalBoardLayout[4]) {
            hasTakenTurn = true;
            TTT_markerLocation[4] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[4] == turnSymbol[currentMarker] && TTT_markerLocation[4] == TTT_markerLocation[6] && TTT_markerLocation[5] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[5] == originalBoardLayout[5]) {
            hasTakenTurn = true;
            TTT_markerLocation[5] = turnSymbol[playerTurn];
        }

        // Bottom row ( 7 8 9 )
        else if (TTT_markerLocation[7] == turnSymbol[currentMarker] && TTT_markerLocation[7] == TTT_markerLocation[8] && TTT_markerLocation[9] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[9] == originalBoardLayout[9]) {
            hasTakenTurn = true;
            TTT_markerLocation[9] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[8] == turnSymbol[currentMarker] && TTT_markerLocation[8] == TTT_markerLocation[9] && TTT_markerLocation[7] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[7] == originalBoardLayout[7]) {
            hasTakenTurn = true;
            TTT_markerLocation[7] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[7] == turnSymbol[currentMarker] && TTT_markerLocation[7] == TTT_markerLocation[9] && TTT_markerLocation[8] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[8] == originalBoardLayout[8]) {
            hasTakenTurn = true;
            TTT_markerLocation[8] = turnSymbol[playerTurn];
        }

        // Left row ( 1 4 7 )
        else if (TTT_markerLocation[1] == turnSymbol[currentMarker] && TTT_markerLocation[1] == TTT_markerLocation[4] && TTT_markerLocation[7] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[7] == originalBoardLayout[7]) {
            hasTakenTurn = true;
            TTT_markerLocation[7] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[4] == turnSymbol[currentMarker] && TTT_markerLocation[4] == TTT_markerLocation[7] && TTT_markerLocation[1] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[1] == originalBoardLayout[1]) {
            hasTakenTurn = true;
            TTT_markerLocation[1] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[1] == turnSymbol[currentMarker] && TTT_markerLocation[1] == TTT_markerLocation[7] && TTT_markerLocation[4] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[4] == originalBoardLayout[4]) {
            hasTakenTurn = true;
            TTT_markerLocation[4] = turnSymbol[playerTurn];
        }

        // Center row ( 2 5 8 )
        else if (TTT_markerLocation[2] == turnSymbol[currentMarker] && TTT_markerLocation[2] == TTT_markerLocation[5] && TTT_markerLocation[8] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[8] == originalBoardLayout[8]) {
            hasTakenTurn = true;
            TTT_markerLocation[8] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[5] == turnSymbol[currentMarker] && TTT_markerLocation[5] == TTT_markerLocation[8] && TTT_markerLocation[2] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[2] == originalBoardLayout[2]) {
            hasTakenTurn = true;
            TTT_markerLocation[2] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[2] == turnSymbol[currentMarker] && TTT_markerLocation[2] == TTT_markerLocation[8] && TTT_markerLocation[5] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[5] == originalBoardLayout[5]) {
            hasTakenTurn = true;
            TTT_markerLocation[5] = turnSymbol[playerTurn];
        }

        // Right row ( 3 6 9 )
        else if (TTT_markerLocation[3] == turnSymbol[currentMarker] && TTT_markerLocation[3] == TTT_markerLocation[6] && TTT_markerLocation[9] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[9] == originalBoardLayout[9]) {
            hasTakenTurn = true;
            TTT_markerLocation[9] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[6] == turnSymbol[currentMarker] && TTT_markerLocation[6] == TTT_markerLocation[9] && TTT_markerLocation[3] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[3] == originalBoardLayout[3]) {
            hasTakenTurn = true;
            TTT_markerLocation[3] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[3] == turnSymbol[currentMarker] && TTT_markerLocation[3] == TTT_markerLocation[9] && TTT_markerLocation[6] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[6] == originalBoardLayout[6]) {
            hasTakenTurn = true;
            TTT_markerLocation[6] = turnSymbol[playerTurn];
        }

        // Top Left - Bottom Right diaginal ( 1 5 9 )
        else if (TTT_markerLocation[1] == turnSymbol[currentMarker] && TTT_markerLocation[1] == TTT_markerLocation[5] && TTT_markerLocation[9] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[9] == originalBoardLayout[9]) {
            hasTakenTurn = true;
            TTT_markerLocation[9] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[5] == turnSymbol[currentMarker] && TTT_markerLocation[5] == TTT_markerLocation[9] && TTT_markerLocation[1] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[1] == originalBoardLayout[1]) {
            hasTakenTurn = true;
            TTT_markerLocation[1] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[1] == turnSymbol[currentMarker] && TTT_markerLocation[1] == TTT_markerLocation[9] && TTT_markerLocation[5] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[5] == originalBoardLayout[5]) {
            hasTakenTurn = true;
            TTT_markerLocation[5] = turnSymbol[playerTurn];
        }

        // Top Right - Bottom Left diaginal ( 3 5 7 )
        else if (TTT_markerLocation[3] == turnSymbol[currentMarker] && TTT_markerLocation[3] == TTT_markerLocation[5] && TTT_markerLocation[7] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[7] == originalBoardLayout[7]) {
            hasTakenTurn = true;
            TTT_markerLocation[7] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[5] == turnSymbol[currentMarker] && TTT_markerLocation[5] == TTT_markerLocation[7] && TTT_markerLocation[3] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[3] == originalBoardLayout[3]) {
            TTT_markerLocation[3] = turnSymbol[playerTurn];
        }
        else if (TTT_markerLocation[3] == turnSymbol[currentMarker] && TTT_markerLocation[3] == TTT_markerLocation[7] && TTT_markerLocation[5] != (turnSymbol[1] && turnSymbol[2]) && TTT_markerLocation[5] == originalBoardLayout[5]) {
            hasTakenTurn = true;
            TTT_markerLocation[5] = turnSymbol[playerTurn];
        }


        if (loopCount == 0)
        {


            if (playerTurn == 1)
            {
                currentMarker = 2;
            }
            else
            {
                currentMarker = 1;
            }
        }
        loopCount++;

    } while (!hasTakenTurn && loopCount != 2);
    

    

}

void TTT::checkWinCon(char TTT_markerLocation[10], bool& gameIsRunning, bool& endedAsDraw)
{
    // 1, 2, 3
    if (TTT_markerLocation[1] == TTT_markerLocation[2] && TTT_markerLocation[2] == TTT_markerLocation[3]) {
           
        gameIsRunning = false;
    }

    else if (TTT_markerLocation[4] == TTT_markerLocation[5] && TTT_markerLocation[5] == TTT_markerLocation[6])
        gameIsRunning = false;

    else if (TTT_markerLocation[7] == TTT_markerLocation[8] && TTT_markerLocation[8] == TTT_markerLocation[9])
        gameIsRunning = false;

    else if (TTT_markerLocation[1] == TTT_markerLocation[4] && TTT_markerLocation[4] == TTT_markerLocation[7])
        gameIsRunning = false;

    else if (TTT_markerLocation[2] == TTT_markerLocation[5] && TTT_markerLocation[5] == TTT_markerLocation[8])
        gameIsRunning = false;

    else if (TTT_markerLocation[3] == TTT_markerLocation[6] && TTT_markerLocation[6] == TTT_markerLocation[9])
        gameIsRunning = false;

    else if (TTT_markerLocation[1] == TTT_markerLocation[5] && TTT_markerLocation[5] == TTT_markerLocation[9])
        gameIsRunning = false;

    else if (TTT_markerLocation[3] == TTT_markerLocation[5] && TTT_markerLocation[5] == TTT_markerLocation[7])
        gameIsRunning = false;

    else if (TTT_markerLocation[1] != '1' && TTT_markerLocation[2] != '2' && TTT_markerLocation[3] != '3'
        && TTT_markerLocation[4] != '4' && TTT_markerLocation[5] != '5' && TTT_markerLocation[6] != '6'
        && TTT_markerLocation[7] != '7' && TTT_markerLocation[8] != '8' && TTT_markerLocation[9] != '9')
    {
        //marks that thet game was a draw
        endedAsDraw = true;
        gameIsRunning = false;
    }

}

void TTT::anounceWinner(char TTT_markerLocation[10], bool& gameIsRunning, int playerTurn, bool& endedAsDraw, bool isPlaying_PvC)
{
    bool invaldInput = false;
    char playAgain = 'L';
    


    while (cin.fail() || (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n'))
    {
        system("CLS");
        vector<int> scoreCardStorage;
        getScoreCardValues(scoreCardStorage);
        //if the current game mode is PvC, update and display score board
        if (isPlaying_PvC == true)
        {
            
            updateScoreCardValues(scoreCardStorage, endedAsDraw, playerTurn);
            getScoreCardValues(scoreCardStorage);
            cout << "\n\tScore Board:" << endl;
            cout << "\tPlayer 1 (X) --> " << scoreCardStorage[0] << " Points" << endl;
            cout << "\tPlayer 2 (O) --> " << scoreCardStorage[1] << " Points" << endl;
            cout << "\t   Draws     --> " << scoreCardStorage[2] << " Points" << endl;
            cout << endl;
        }

        displayScreen(TTT_markerLocation, playerTurn, isPlaying_PvC);

        // if game ended as a draw, first message else second message
        if (endedAsDraw)
        {
            cout << "!!! IT'S A DRAW !!!" << endl;

        }
        else if (!endedAsDraw)
        {
            cout << "!!! CONGRATULATIONS PLAYER " << playerTurn << "  ON WINNING !!!" << endl;
        }

        if (invaldInput)
        {
            cout << "\n\t!!That was an invalid input!!";
            cout << "\n\t !Please make a valid input!" << endl << endl;
        }
        
        cout << "Do you wish to play again? Y/N:";
        cin >> playAgain;
        if (playAgain == 'Y' || playAgain == 'y')
        {
            gameIsRunning = true;
        }
        else if (playAgain == 'N' || playAgain == 'n')
        {
            gameIsRunning = false;

        }

        // Data Valadation
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        invaldInput = true;

    }
}

void TTT::quitGameConfirmation(bool& gameIsRunning)
{
    bool invaldInput = false;

    char playAgain = 'L';

    // Data Valadation
    while (cin.fail() || (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n'))
    {
        system("CLS");
        if (invaldInput)
        {
            cout << "\n\t!!That was an invalid input!!";
            cout << "\n\t !Please make a valid input!" << endl << endl;
        }

        cout << "Do you really wish to quit the game?" << endl;
        cout << "Y -> Quit game." << endl;
        cout << "N -> Change gamemode." << endl << endl;
        cout << "Response: ";
        cin >> playAgain;
        if (playAgain == 'Y' || playAgain == 'y')
        {
            gameIsRunning = false;
        }
        else if (playAgain == 'N' || playAgain == 'n')
        {
            gameIsRunning = true;

        }

        // Data Valadation
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }
        invaldInput = true;

    }
}

void TTT::resetBoard(char TTT_markerLocation[10])
{
    char originalBoardLayout[10] = { 'N', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    for (int i = 0; i < 10; i++)
    {
        TTT_markerLocation[i] = originalBoardLayout[i];
    }
}

void TTT::getScoreCardValues(vector<int> &scoreCardStorage)
{        
    //open read file
    ifstream readFile;
    readFile.open("Score-Card.txt");

    // If file could not be opened, program will exit with an error message (AKA: Idiot proofing)
    if (!readFile.is_open())
        fileOpenedCheck_errorMessage("Score-Card.txt");

    // Amount of numbers that needs to be extract from .txt file
    int numberOfNumbers;
    

    //stores the Score Cards values into an easy to use vector
    readFile >> numberOfNumbers;
    for (int i = 1; i <= numberOfNumbers; i++)
    {
        int temp;
        readFile >> temp; //NOTE spaces and endlines are skipped in file reading ;)
        scoreCardStorage.push_back(temp);
    }

    //close read file
    readFile.close();
}

void TTT::updateScoreCardValues(vector<int> scoreCardStorage, bool endedAsDraw, int playerTurn)
{
    //open write file
    ofstream writeFile;
    writeFile.open("Score-Card.txt");

    // If file could not be opened, program will exit with an error message (AKA: Idiot proofing)
    if (!writeFile.is_open())
        fileOpenedCheck_errorMessage("Score-Card.txt");

    // Amount of numbers that needs to be put into the .txt file
    int numberOfNumbers = 3;

    //if the game ended as a draw
    if (endedAsDraw)
    {
        scoreCardStorage[2] += 1;
    }
    else
    {
        // if the game was won by the player
        if (playerTurn == 1)
        {
            scoreCardStorage[0] += 1;
        }
        // if the game was by the computer
        else if (playerTurn == 2)
        {
            scoreCardStorage[1] += 1;
        }
    }

    //stores the Score Cards values into an easy to use vector
    writeFile << numberOfNumbers << endl;
    for (int i = 0; i < numberOfNumbers; i++)
    {
        writeFile << scoreCardStorage[i] << " ";
    }

    //close read file
    writeFile.close();
}



