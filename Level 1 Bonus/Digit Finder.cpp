/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 REVIEW ACTIVITY 4

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Digit Finder
Purpose: Finds a 4 digit number with the following properties: all 4 digits are diff, digit in the thousands place is three times the digit in the tens place, number is odd, sum of digits is 27
Due Date: Monday, October 5, 2020
*************************************************************
*/

//Start script and set std for use with cout and cin along with variable/constant declaration
#include <iostream>
using namespace std;
const int MAX_VAL = 9999;
int thousands, hundreds, tens, ones, sum;

//digit finder
void Digit_Finder() {
	//for loop to loop through all 4 digit numbers
	for (int num = 1000; num <= MAX_VAL; num++) {
		//check if the remainder of number being checked divided by 2 is 1 (odd number) 
		if (num % 2 == 1) {
			//find the digit in each number place to be used for comparison later on
			//modulo will give the number in each place
			//ex: num=12, 12%10 is 2 (ones place), 12/10=1 (due to variable type being int) then 1%10 is 1 (tens place)
			ones = num % 10;
			tens = num/10 % 10;
			hundreds = num/100 % 10;
			thousands = num/1000 % 10000;

			//calculate sum of all digits to use later on
			sum = ones + tens + hundreds + thousands;

			//check if each digit is different and also ensure that sum is 27 and the thousands place is 3x tens place
			if (ones != tens && ones != hundreds && ones != thousands && tens != hundreds && tens != thousands && hundreds != thousands && sum == 27 && thousands == 3 * tens) {
				//print solution if all parameters are met then break loop
				std::cout << "A number that fits all 4 parameters is: " << num;
				break;
			}
			//if it has looped through all 4 digit numbers, output that there is no number that follows these properties
			else if (num == MAX_VAL) {
				std::cout << "There is no number that fits the following properites";
			}
		}
	}
}

//redirect to digit finder
int main() {
	Digit_Finder();
}
