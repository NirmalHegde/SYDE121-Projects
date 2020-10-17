/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 BONUS 1

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Calculator
Purpose: Calculates function that is hardcoded
Due Date: Monday, October 5, 2020
*************************************************************
*/

//Included cmath to gain access to pow function
#include <iostream>
#include <cmath>

using namespace std;

void calculator() {

    //initialized variables
    double x = 2;
    const char* function = "(x^3)+(24x^2)+(12x)+(44)";
    double final_val = NULL;

    //calculation of (x^3)+(24x^2)+(12x)+(44)
    final_val = pow(x, 3) + 24 * pow(x, 2) + 12 * x + 44;

    //output
    cout << "final answer of " << function << " is: " << final_val << "\n";

}

int main() {
    //start calculator function
    calculator();
}
