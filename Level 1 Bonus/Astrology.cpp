/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 BONUS 2

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Astrology
Purpose: Determines sign based on date inputted
Due Date: Monday, October 5, 2020
*************************************************************
*/

//Initialized libraries and std
#include <iostream>
using namespace std;

//Horoscope function; outputs sign based on birth month and day
void horoscope() {
    //variable initialization
    int month;
    int day;
    const int month_count = 12;
    bool verify = false;
    int sign_date[] = { 20,19,21,20,21,21,23,23,23,23,22,22 };
    const char* sign[] = {
        "Capricorn",
        "Aquarius",
        "Pisces",
        "Aries",
        "Taurus",
        "Gemini",
        "Cancer",
        "Leo",
        "Virgo",
        "Libra",
        "Scorpio",
        "Saggitarius",
        "Capricorn"
    };

    //ask for birth month, if wrong month is inputted, reprompt for birth month
    while (verify == false) {
        std::cout << "Enter your birth month (MM): ";
        std::cin >> month;

        if (month <= 12 && month >= 1) {
            verify = true;
        }
    }

    verify = false;

    //ask for birth day, if wrong day is inputted, reprompt for birth day
    while (verify == false) {
        std::cout << "Enter your birth day (DD): ";
        std::cin >> day;

        if (day <= 31 && day >= 1) {
            verify = true;
        }
    }

    //Start conclusion statement
    std::cout << "\nYour sign is ";

    //Loop through all months to find a match then use day to determine the sign
    for (int i = 0; i < month_count; i++) {
        if (month == i + 1) {
            if (day < sign_date[i]) {
                std::cout << sign[i] << "\n";
            }
            else {
                std::cout << sign[i + 1] << "\n";
            }

            break;
        }
    }
}

//Start horoscope function
int main() {
    horoscope();
}