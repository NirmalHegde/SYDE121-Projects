/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 Assignment 001 Question 002

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Sum
Purpose: Calculates sum of values between two numbers
Due Date: Friday, September 25, 2020
*************************************************************

STEPS:
1. Ask for user input for the starting number and ending number.

2. If starting number is greater than ending number, save d variable as -1, else save it as 1.

2. Find variable n in formula by finding difference between starting and ending number + 1 (account for loss of number) 
   and storing it in variable n.

3. Use formula sum=(n/2)(2firstnum+(n-1)d) and store result in variable sum

4. Output sum using cout



VALID RANGE:
Values used for testing: 1 to 500, 5 to 2020, 42 to 32000, -1 to -5
ANY INTEGERS WILL WORK



RESULTS OF STEP 1:
1 to 500 - 125250
5 to 2020 - 2.0412 * 10^6
42 to 32000 - 5.12015 * 10^8
*/

#include <iostream>
using namespace std;

void sum() {
    //variable declaration
    double first_num, last_num, n, d, sum;

    //gain input for starting and ending number
    std::cout << "Input Starting Number: ";
    std::cin >> first_num; //save starting number in first_num
    std::cout << "\nInput Ending Number: ";
    std::cin >> last_num; //save ending number in last_num
    
    //check if last_num is greater than first_num, if so then the difference between each number is 1
    if (last_num > first_num) {
        d = 1;
        n = last_num - first_num + 1; //calculate number of values
    }
    else {
        d = -1;
        n = first_num - last_num + 1;
    }

    //find sum using formula
    sum = (n / 2) * (2 * first_num + (n - 1) * d);

    //output final value
    std::cout << "\nSum: " << sum;   
}



int main() {
    sum();
}
