/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 REVIEW ACTIVITY 5

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: 23 Game
Purpose: CPU vs User to try and not pick up the last stick
Due Date: Monday, October 5, 2020
*************************************************************

HOW TO TEST:

1) Test invalid values (ex: -1, 5, 10)
2) Test inputting any amount of values (1,2, or 3) until just before sticks < 4
3) At just before sticks < 4, place a number that would allow computer to win
4) After placing number, try putting number greater than how many sticks are left, do so repeatedly to check error outcome
5) Place valid number to check loss message
6) Repeat code and place numbers that would allow you to select sticks while sticks < 4
7) Select stick number that would allow you to win to check win message
*/

//setup and variable declaration
#include <iostream>
using namespace std;
int sticks = 23;
int x,computer;

//game function
void game() {
	//User turn
	//ask for number between 1 and 3 (sticks user takes), if invalid input is given, reprompt
	while (sticks > 0) {
		std::cout << sticks << " sticks are left, how many would you like to take out?: ";
		std::cin >> x;
		while (x > 3 || x < 1) {
			std::cout << "\n" << sticks << " sticks are left, how many would you like to take out?: ";
			std::cin >> x;
		}

		//subtract the sticks user is taking away to find remaining
		sticks -= x;

		//if sticks is negative after subtracting user amount, backtrack to right before
		if (sticks < 0) {
			sticks += x;

			//ask for new stick total between the amount of sticks left and 1, reprompt if invalid response
			std::cout << "\nThere are only " << sticks << " sticks left, please choose a number between 1 and " << sticks << ": ";
			std::cin >> x;
			while (x > sticks || x < 1) {
				std::cout << "\nThere are only " << sticks << " sticks left, please choose a number between 1 and " << sticks << ": ";
				std::cin >> x;
			}

			//subtract new user value from sticks
			sticks -= x;
		}

		//CPU turn
		//if remaining sticks is greater than or equal to 4, select 4-x sticks
		if (sticks >= 4) {
			computer = 4 - x;
			sticks -= computer;
			std::cout << "\n\nComputer took " << computer << " sticks.\n";
		}
		//if remaining sticks is between 4 and 1, select enough sticks for computer to win next turn
		else if (sticks < 4 && sticks > 1) {
			computer = sticks - 1;
			sticks -= computer;
			std::cout << "\n\nComputer took " << computer << " sticks.\n";
		}
		//if stick total is 1, it means CPU lost, so user one
		else if (sticks == 1) {
			sticks = 0;
			std::cout << "\n\nCongratulations, you win! Computer took the last stick!\n";
		}
		//only remaining case is sticks=0 so user lost in this case
		else {
			std::cout << "\n\nOh no, you lose... you took the last stick\n";
		}
	}
}

//redirect to game function
int main() {
	game();
}