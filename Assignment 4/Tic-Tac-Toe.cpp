/*
************************************************************
Student Name: Nirmal Hegde, Brendan Marshall
Student Number: 20894403, 20902866

SYDE 121 Assignment 004 Question 001

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Tic Tac Toe
Purpose: Tic Tac Toe Game.
Due Date: Friday, November 6th, 2020
*************************************************************

STEPS:
1. Configure variables that will not be touched when restart function happens (who starts the game first, x wins, o wins, ties)

2. Set up tic tac toe board by mapping values to 2D array

3. Create while loop that ensures the game is repeated until all parts of the 2D array are filled with xs and os or if someone wins (gets 4 in a row)

4. Create function which will output the updated game board after each while loop

5. Create function which will prompt either player X or player O to choose a cell

6. Replace inputted cell with either X or O, depending on player (set value in cell to -1 for x and -2 for O)

7. Check if X or O has 4 in a row, if not then repeat while loop (go back to step 4, but change turn to other player)

8. While checking for 4 in a row, also check if all cells are filled. If so, game is a tie

9. After outputting win/ message (if either X or O has 4 in a row or tie), save result in a variable and prompt user for another game

10. If yes, reset all variables (except ones that will not be touched in step 1) and repeat from beginning of tic tac toe function (step 2 onwards)

11. If player says no, output x win results, y win results, and tie results.


TESTING:
1. Tested values outside tic tac toe grid range (less than 1, greater than 16) to ensure error checking is correct.

2. Tested when users input an already full value in tic tac toe grid

3. Tested values inside range and ensure that values are being saved onto the board.

4. Tested win function by having x win, then o win (have one test be a win  by a player who takes the final value in the grid)

5. Tested all other permutations of win (diagonal, horizontal, vertical) to ensure all wins are possible

6. Tested restart game yes(1) function to ensure board resets for a new game

7. Tested restart no(0) function to ensure game correctly saves and outputs wins and ties correctly

8. Tested values outside 1 and 0 for restart yes no function for error checking.


LIMITATIONS:
- Error checking only enveloped incorrect and duplicated ints, inputting a float or char will crash program
*/

#include <iostream>
using namespace std;
const int SIZE = 4;

void initialize();
//INPUT: n/a
//PROCESS: Initialize variables that will not change in each iteration
//OUTPUT: Variables that will not change (x_win, o_win, ties, game_turn)

void tictactoe(bool game_turn, int& x_win, int& o_win, int& ties);
//INPUT: # x wins, # o wins, # ties, which player starts first
//PROCESS: Initializes game board and calls all functions necessary for game to play, and handles restart function
//OUTPUT: Restart request, final score, variables for all necessary functions

void output_board(int board[4][4]);
//INPUT: game board
//PROCESS: output game board to terminal
//OUTPUT: game board

void player_move(int board[4][4], bool turn);
//INPUT: The playing board, whose turn it is
//PROCESS: Takes inputs from the current turn's player and saves their move on the board
//OUTPUT: n/a

void check_win(int board[4][4],bool& turn, bool& win, int& x_win, int& o_win, int& ties);
//INPUT: The playing board, whose turn it is, if the game has been won, the number of wins per player, the number of ties
//PROCESS: Checks if a player has won the game or if it has resulted in a tie
//OUTPUT: A message stating a win loss or tie

int main() {
    initialize();
}

//Initialization Step
void initialize() {
    int x_win = 0; //Setting the variables that stick between games
    int o_win = 0;
    int ties = 0;
    tictactoe(true, x_win, o_win, ties);
}

//initialize game board and handle all functions along with restart function
void tictactoe(bool game_turn, int& x_win, int& o_win, int& ties) {
    //Initialize variables and arrays
    int board[4][4] = { 0 };
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 1; j <= SIZE; j++) {
            board[i][j-1] = SIZE * i + j; //Setting each element to its associated number
        }
    }
    bool turn = game_turn;
    bool win = false;
    int play_again;

    while (!win) { //Loops until a player wins
        cout << "\n\n";
        output_board(board);
        player_move(board,turn);
        check_win(board, turn, win, x_win, o_win, ties);
    }

    do {
        cout << "Would you like to play again? Yes(1)/No(0): "; 
        cin >> play_again;
    } while (play_again != 1 && play_again != 0); //Checks if the players would like to play again

    if (play_again == 1) {
        tictactoe(!game_turn, x_win, o_win, ties); //Resetting the game while passing saved values
    } else {
        cout << "\n\n\nPlayer X won " << x_win << " times, player O won " << o_win << " times, and you tied " << ties << " times\n\n" << endl; //Outputting the total win and tie counts
    }
}

//output board to terminal
void output_board(int board[4][4]){
    cout << "\n\n\n";
    for(int i = 0; i < SIZE; i++){ 
        for(int j = 0; j < SIZE; j++){
            if (board[i][j] == -1) { //Outputting an X if it is stored at an index
                cout << "X\t";
            } else if (board[i][j] == -2) { //Outputting an O if it is stored at an index
                cout << "O\t"; 
            } else {
                cout << board[i][j] << "\t"; //Outputting the location if the index is not filled
            }
        }
        cout << "\n\n\n";
    }
}

//places xs and os
void player_move(int board[4][4], bool turn){
    int input = 0;
    do {
        if (turn) {
            cout << "X, where would you like to place your piece? "; //Asking where the mark should be placed
            cin >> input; 
        } else {
            cout << "O, where would you like to place your piece? ";
            cin >> input;
        }
    } while (input < 1 || input > 16 || board[(input - 1) / 4][(input - 1) % 4] < 0); //backtracks from number given to point in the array

    //sets board point to input from user (uses backtracking method stated above)
    if (turn) {
        board[(input - 1) / 4][(input - 1) % 4] = -1;
    } else {
        board[(input - 1) / 4][(input - 1) % 4] = -2;
    }
}

//Checks if there is a win or tie, otherwise changes turn to next player
void check_win(int board[4][4],bool& turn,bool& win, int& x_win, int& o_win, int& ties) {
    bool is_tie = false;

    for (int i = 0; i < SIZE; i++) { //Checking if any collumns were won
        if (board[i][0] == board[i][1] && board[i][2] == board[i][3] && board[i][3] == board[i][0]) {
            win = true;
        }
    }

    for (int j = 0; j < SIZE; j++) { //Checking if any rows were won
        if (board[0][j] == board[1][j] && board[2][j] == board[3][j] && board[3][j] == board[0][j]) {
            win = true;
        }
    }

    if (board[0][0] == board[1][1] && board[2][2] == board[3][3] && board[3][3] == board[0][0]) { //Checking one diagonal
        win = true;
    }

    if (board[0][3] == board[1][2] && board[2][1] == board[3][0] && board[3][0] == board[0][3]) { //Checking the second diagnol
        win = true;
    }

    if (win) {
        cout << "\n\n\n\n\n\n\n";
        if (turn) { //Outputting the winner
            cout << "Player X wins" << endl;
            x_win++;
        }
        else {
            cout << "Player O wins" << endl;
            o_win++;
        }
    }

    for (int i = 0; i < SIZE; i++) { //Checking if all squares are full
        for (int j = 0; j < SIZE; j++) {
            is_tie += board[i][j] > 0;
        }
    }

    if (!is_tie) { //Outputting tie message
        cout << "\n\n\n\n\n\n\n";
        cout << "Tie Game" << endl;
        ties++;
        win = true;
    }

    turn = !turn; //Swapping turns
}