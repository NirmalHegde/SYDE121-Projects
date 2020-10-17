/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 Assignment 002 Question 001

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project Prime Number Detector
Purpose: Detects palindromic primes less than 10,000 and primes where the sum of the digits are odd for numbers less than 100,000
Due Date: Friday, October 9th, 2020
*************************************************************


STEPS:
1. Ask for user input for an integer above 1, if not above 1, re-ask (input function)

2. Use for loop that will loop through all numbers up to inputted value (find prime function)

3. Use if statement to check if the index number of the for loop modulo 2, 3, 5, and 7 will not equal 0 to find prime number  (find prime function)

4. If prime number, then output it (find prime function)

5. Use if statement to check if index number is less than the max palindromic number (10k) (find palindromic function)

6. If so, convert number to string to iterate through it and check digits (find palindromic function)

7. Use for loop to iterate through digits, check the first and last digit of the number, then check the second and second last number, repeat until checking the same number or checking adjacent numbers (find palindromic function)

8. If any of these combinations are not equal to eachother (ex: first number and last number are not equal), break loop and move on (find palindromic function)

9. If looped through all digits successfully, output beside prime number that it is palindromic (find palindromic function)

10. Go to odd sum function and check if number is less than odd sum cap of 100,000 (find odd sum function)

11. Separate each digit using either modulo or division and add together under a new variable sum (find odd sum function)

12. If sum modulo 2 is equal to 1, output beside prime number that it is odd sum (find odd sum function)

13. Output new line to separate each number


VALUES USED TO CHECK PROGRAM LOGIC:
-1 (to check for while loop re-asking)
50 (to check for initial cap of 10000)
10000 (check for edge cases of palindromic)
30000 (check for cap of 100000)
100000 (check for edge cases of odd sum)
150000 (check after odd sum)


VALID RANGE OF VALUES:
Any integer between 2 and 100,000 would work correctly and efficiently, as anything after this point will take quite a long time to output numbers (over 1 minute)
*/

//Initialize using iostream and std; declare libraries and constants 
#include <iostream>
#include <string>
using namespace std;
const int MIN_NUM = 1;
const int MAX_PALINDROMIC = 10000;
const int MAX_ODD_SUM = 100000;

//function to find if prime number is a palindrome
void find_palindromic(int num, std::string num_string, int num_length) {
	//check if number is less than the 10000 cap for palindromic numbers
	if (num < MAX_PALINDROMIC) {
		//check if the first number is equal to last number, then second number is equal to second last number...(repeat)
		for (int first_num = 0; first_num <= num_length / 2; first_num++) {
			//if the numbers are not equal to eachother, break the loop and move on to the next number 
			if (num_string.at(first_num) != num_string.at(num_length - 1 - first_num)) {
				break;
			}
			//if the number is equal all the way to the middle, declare palindromic prime
			else if (num_length / 2 == first_num) {
				std::cout <<" (palindromic prime)";
				break;
			}
		}
	}
}

//function to find if prime number is an odd sum
void  find_odd_sum(int num, int num_length) {
	//check if number is less than the 100000 cap for odd sum numbers
	if (num < MAX_ODD_SUM) {
		//variable declaration
		int sum = 0;

		//add up all the digits
		for (int digit_place = 0; digit_place < num_length; digit_place++) {
			sum += num / pow(10, digit_place);
		}

		//if there is a remainder in the sum when dividing by 2, declare odd
		if (sum % 2 == 1) {
			std::cout << " (digit sum is odd)";
		}
	}
}

//function to find the prime numbers and link to other functions
void find_primes(int input) {
	//title print
	std::cout << "\nPrime Numbers:\n\n";

	//loops through all numbers from 2 to the input number
	for (int num = 2; num <= input; num++) {
		//used to find single digit primes and associates them with palindromic and odd sum if necessary
		if (num == 2 || num == 3 || num == 5 || num == 7) {
			if (num == 2) {
				std::cout << num << " (palindromic prime)\n";
			}
			else {
				std::cout << num << " (palindromic prime)" << " (digit sum is odd)\n";
			}
		}
		//used to find all other prime numbers
		else if (num % 2 != 0 && num % 3 != 0 && num % 5 != 0 && num % 7 != 0) {
			//print prime number if found
			std::cout << num;

			//variable declaration for use in other functions (makes the number in question a string and finds the length of it)
			std::string num_string = std::to_string(num);
			int num_length = num_string.length();

			//direct to find_palindromic function
			find_palindromic(num, num_string, num_length);

			//direct to find_odd_sum function
			find_odd_sum(num, num_length);

			///new line for new number
			std::cout << "\n";
		}
	}
}

//function to get user input
void user_input() {
	//variable declaration
	int input;

	//get user input, if number below one, re-ask
	std::cout << "Enter integer greater than 1: ";
	std::cin >> input;
	while (input < MIN_NUM) {
		std::cout << "\nEnter integer greater than 1: ";
		std::cin >> input;
	}

	//direct to find_primes function
	find_primes(input);	
}

//root function to start script
int main() {
	user_input();
}
