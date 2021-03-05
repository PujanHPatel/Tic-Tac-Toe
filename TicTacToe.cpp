/* This program initiates a TIC-TAC-TOE Game that is playable by two players taking the role of X, and O. Inputting
 * coordinates go as (Interger, Letter) ex. (1,a) for the top left square
 * Author: Pujan Patel
 */
#include <iostream>
using namespace std;
//declase functions
bool gameState(char gameBoard[3][3]);
void printBoard(char gameBoard[3][3]);
void clearBoard(char gameBoard[3][3]);

int main() {//main method
    //declare variables
    char gameBoard[3][3];
    char userInput[3];
    int turn = 0;
    char move = 'X';
    bool running = true;
    bool gameOver = false;
    int xWin = 0;
    int oWin = 0;
    int turnCount = 0;
    //setup game
    clearBoard(gameBoard);
    printBoard(gameBoard);

    while(running == true && turnCount < 9) {//loop to run game while running
        if(turn == 0) {//switch turns
            turn = 1;
            move = 'X';
        }
        else {
            turn = 0;
            move = 'O';
        }
        
        cin.getline(userInput,3);//take input
        //place marker in proper spot
	if(userInput[1] == 'a' && gameBoard[(int)(userInput[0])-49][0] == ' ') {
            gameBoard[(int)(userInput[0])-49][0] = move;
        }
        else if(userInput[1] == 'b' && gameBoard[(int)(userInput[0])-49][1] == ' ') {
            gameBoard[(int)(userInput[0])-49][1] = move;
        }
        else if(userInput[1] == 'c' && gameBoard[(int)(userInput[0])-49][2] == ' ') {
            gameBoard[(int)(userInput[0])-49][2] = move;
        }
        else {//try again
            cout << "Please Try Again" << endl;
            if(turn == 0) {
                turn = 1;
                move = 'X';
            }
            else {
                turn = 0;
                move = 'O';
            }
            turnCount-=1;
        }
        turnCount++;
        printBoard(gameBoard);//print game
        gameOver = gameState(gameBoard);//check gamestate
        //if over, who won? play again?
        if(gameOver == true && turn == 1) {
            xWin++;
            cout << "X has won: " << xWin << endl;
            cout << "O has won: " << oWin << endl;
            cout << "again? (y/n)" << endl;
            cin.getline(userInput,2);
        }
        else if(gameOver == true && turn == 0) {
            oWin++;
            cout << "X has won: " << xWin << endl;
            cout << "O has won: " << oWin << endl;
            cout << "again? (y/n)" << endl;
            cin.getline(userInput,2);
        }
        else if(turnCount == 9) {
            cout << "Tie" << endl;
            cout << "X has won: " << xWin << endl;
            cout << "O has won: " << oWin << endl;
            cout << "again? (y/n)" << endl;
            cin.getline(userInput,2);
        }
        if(userInput[0] == 'y') {
            running = true;
            turn = 0;
            turnCount = 0;
            gameOver = false;
            clearBoard(gameBoard);
            printBoard(gameBoard);
        }
        else if(userInput[0] == 'n') {
            running = false;
        }
    }
    return 0;
}

void printBoard(char gameBoard[3][3]) {//print board function
    cout << " 1 2 3" << endl; 
    cout << "a" << gameBoard[0][0] << " " << gameBoard[1][0] << " " << gameBoard[2][0] << endl;
    cout << "b" << gameBoard[0][1] << " " << gameBoard[1][1] << " " << gameBoard[2][1] << endl;
    cout << "c" << gameBoard[0][2] << " " << gameBoard[1][2] << " " << gameBoard[2][2] << endl;
}
void clearBoard(char gameBoard[3][3]) {//clear board function
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            gameBoard[i][j] = ' ';
        }
    }
}
bool gameState(char gameBoard[3][3]) {//assess game state function
    if((gameBoard[0][0] == 'X' && gameBoard[1][0] == 'X' && gameBoard[2][0] == 'X') || (gameBoard[0][1] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][1] == 'X' )
            || (gameBoard[0][2] == 'X' && gameBoard[1][2] == 'X' && gameBoard[2][2] == 'X') || (gameBoard[0][0] == 'X' && gameBoard[0][1] == 'X' && gameBoard[0][2] == 'X') 
            || (gameBoard[1][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[1][2] == 'X') || (gameBoard[2][0] == 'X' && gameBoard[2][1] == 'X' && gameBoard[2][2] == 'X')
            || (gameBoard[0][0] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][2] == 'X') || (gameBoard[0][2] == 'X' && gameBoard[1][1] == 'X' && gameBoard[2][0] == 'X')) {
        return true;
    }
    else if((gameBoard[0][0] == 'O' && gameBoard[1][0] == 'O' && gameBoard[2][0] == 'O') || (gameBoard[0][1] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][1] == 'O' )
            || (gameBoard[0][2] == 'O' && gameBoard[1][2] == 'O' && gameBoard[2][2] == 'O') || (gameBoard[0][0] == 'O' && gameBoard[0][1] == 'O' && gameBoard[0][2] == 'O') 
            || (gameBoard[1][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[1][2] == 'O') || (gameBoard[2][0] == 'O' && gameBoard[2][1] == 'O' && gameBoard[2][2] == 'O')
            || (gameBoard[0][0] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][2] == 'O') || (gameBoard[0][2] == 'O' && gameBoard[1][1] == 'O' && gameBoard[2][0] == 'O')) {
        return true;
    }
    else {
        return false;
    }
}           
