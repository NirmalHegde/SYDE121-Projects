/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 Assignment 001 Question 001

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Weight Scale
Purpose: Calculates and outputs the number of each type of weight that is required to weigh a certain object.
Due Date: Friday, September 25, 2020
*************************************************************

STEPS:
1. Ask for user input for the weight using cout for query and cin for response. 

2. Find number of 125 weights needed by doing (weight_given / 125), then save the weights in a variable called weight125.

3. Update weight_given variable using (weight given - 125 * weight125) before trying to find how many other weights are needed.
   This will allow us to find the weight that is left after 125 lb weight type can't be use anymore.

4. Repeat steps 2 and 3, but replace 125 with 75, then 42, then 15, then 1 for each weight type.

5. Output no. of each type of weight using cout. Test to see which weights are being used and remove ones with value of 0



VARIABLES USED:
weight_given - used to collect user input for weight along with all weight calculations.

unchanged_weight - used for final statement, simply contains the original input (ex: 2048).

weight125/75/42/15/1 - used to collect number of weights for each particular weight type.



VALID RANGE:
Values used for testing: 0, 1000, 10000000
ANY POSITIVE INTEGER WILL WORK



RESULTS OF STEP 1 (2048 lbs):
125 lbs: 16
42 lbs: 1
1 lbs: 6
Total: 23
*/

#include <iostream>
using namespace std;

void weight_check() {
    //ask for user input and variable declaration
    int weight_given;
    std::cout << "Enter Weight: ";
    std::cin >> weight_given;
    int unchanged_weight = weight_given;
    int weight125, weight75, weight42, weight15, weight1;
    int total_weights = 5;

    //find no. of 125 lb weight types needed
    weight125 = weight_given / 125;
    weight_given = weight_given - 125 * weight125;

    //find no. of 75 lb weight types needed
    weight75 = weight_given / 75;
    weight_given = weight_given - 75 * weight75;

    //find no. of 42 lb weight types needed
    weight42 = weight_given / 42;
    weight_given = weight_given - 42 * weight42;

    //find no. of 15 lb weight types needed
    weight15 = weight_given / 15;
    weight_given = weight_given - 15 * weight15;

    //find no. of 1 lb weight types needed
    weight1 = weight_given / 1;
    weight_given = weight_given - 1 * weight42;

    //output no. of each weight type used
    std::cout << "\nThe number of each weight type required to weigh " << unchanged_weight << " lbs is:";

    //Checks if there is more than 1 weight used for each value before outputting it
    if (weight125 >0) {
        std::cout << "\n125 lbs: " << weight125;
    }
    if (weight75 > 0) {
        std::cout << "\n75 lbs: " << weight75;
    }
    if (weight42 > 0) {
        std::cout << "\n42 lbs: " << weight42;
    }
    if (weight15 > 0) {
        std::cout << "\n15 lbs: " << weight15;
    }
    if (weight1 > 0) {
        std::cout << "\n1 lbs: " << weight1;
    }

    //Total Weights Used
    std::cout << "\nTotal: " << weight125 + weight75 + weight42 + weight15 + weight1 << "\n";
}

int main() {
    weight_check();
}
