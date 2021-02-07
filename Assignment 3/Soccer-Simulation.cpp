/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 Assignment 001 Question 001

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Soccer
Purpose: Soccer Simulation Game
Due Date: Friday, October 30, 2020
*************************************************************

STEPS:
1. Declare all functions, constructors, and booleans to allow for memory management and easy to read code 

2. Use srand to make sure all rand functions called will give a random value

3. Find random event number and create for loop to loop through all events

4. Make another rng to find the event type for each specific event

5. correspond event number to the event type and output the event then calculate the shot type and/or foul type

6. for case 1 and 2, run another rng for the shot type and associate it with the commands

7. change boolean values goals, shots on, and blocked to specify the struct values that will be incremented later; also output the shot type

8. use if else statements to determine what values are each boolean type so that struct can be incremented (ex: if goals is true, then increment goals for a by 1 (a has scored a goal))

9. for case 2 and 3, do same rng shot type process, however also do foul type function

10. run foul type rng and correspond it to its specific foul type

11. Change boolean values red card and yellow card based on each case

12. use if else to check shot type and also foul type (ex: if red_card is true, then increment a's red card count by 1 (a has received a red card)

13. for case 5 and 6, do same as case 3 and 4, but replace shot type with penalty shot type

14. When the for loop reaches half of the event number, output halftime results (all struct values) in a readable format

15. Do same as step 14, but after the game ends

PROGRAM VERIFICATION:
OUTPUT:
"WELCOME TO THE FIFA FINALS! LET THE GAMES BEGIN!!!

Team A has shot the ball!
Blocked by Goalkeeper!

Team B has shot the ball!
Huge block by defender!

HALFTIME STATS:

TEAM A:
Shots On Goal: 1
Shots Off Goal: 0
Blocked Shots: 1
Fouls: 0
Yellow Cards: 0
Red Cards: 0

TEAM B:
Shots On Goal: 0
Shots Off Goal: 1
Blocked Shots: 1
Fouls: 0
Yellow Cards: 0
Red Cards: 0

CURRENT SCORE: 0 - 0

Team A has fouled Team B! Free Kick has been awarded!
Red card was given.
GOOOOOAAALL!!!

Team A has fouled Team B! Free Kick has been awarded!
No card was given.
Wide Miss...

FINAL STATS:

TEAM A:
Shots On Goal: 1
Shots Off Goal: 0
Blocked Shots: 1
Fouls: 1
Yellow Cards: 0
Red Cards: 1

TEAM B:
Shots On Goal: 1
Shots Off Goal: 2
Blocked Shots: 1
Fouls: 0
Yellow Cards: 0
Red Cards: 0

FINAL SCORE: 0 - 1"

HOW I CHECKED:
I verified each outcome by looking at the different events and determining what each stat should hold on paper.
I also ensured that multiple outcomes were not repeating by running the program 20 times and determining the specific outcome of each one. (sample output above)
I then changed the rng values to hold specific values to ensure each case would come.

TESTING SCENARIOS:
Sample scenario above; changed rng values manually to ensure all values came, below are values tested:
Event rng: 1, 10, 20
Shot rng: 0, 1, 2, 3
Foul rng: 0, 1, 2
After all simulations were run, simulation was determined to be accurate.

LIMITATIONS RELATED TO SIMULATION:
This game would not declare an absolute winner every time as it was very possible for both teams to tie.
In real soccer, there would be overtime and penalty kicks to prevent this from happening, which would be a next step for this program simulation.
No possibilities of having 1.5 events.
Events are also usually not divided up equally, as some halves may be more intense than others.
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void start_soccer_game();
//INPUT: n/a
//PROCESS: Start Soccer Game, Find Number of Events, Root for all other functions
//OUTPUT: Halftime stats, Final stats

void event_action();
//INPUT: n/a
//PROCESS: Random Number Generation for Actions
//OUTPUT: Event number

void event_type(int event_action);
//INPUT: Event number (event_action)
//PROCESS: Find the event type to correspond with the event number
//OUTPUT: Event corresponding to event number

void shot_action();
//INPUT: n/a
//PROCESS: Random Number Generation for shot
//OUTPUT: Shot number

void penalty_action();
//INPUT: n/a
//PROCESS: Random Number Generation for penalty shot
//OUTPUT: Penalty shot number

void foul_action();
//INPUT: n/a
//PROCESS: Random Number Generation for foul declaration
//OUTPUT: Foul declaration number

void shot_type(int shot_action);
//INPUT: Shot/Penalty Shot number (shot_action)
//PROCESS: Identify shot type based on shot number
//OUTPUT: Shot corresponding to shot number

void foul_type(int foul_action);
//INPUT: Foul number (foul_action)
//PROCESS: Identify foul type based on foul number
//OUTPUT: Foul corresponding to foul number

//Boolean Declaration
bool goal = false; //determines if goal scored
bool shot_on = false; //determines if shot was on or off net
bool blocked = false; //determines if ball was blocked
bool yellow_card = false; //determines if yellow card was awarded
bool red_card = false; //determines if red card was awarded

//Stats variable declaration
struct stats {
    int shots_on = 0; //shots on the net
    int shots_off = 0; //shots off the net
    int blocked_shots = 0; //blocked shots by the team
    int goals = 0; //goals made by each team
    int fouls = 0; //fouls by a team
    int yellow_cards = 0; //number of yellow cards received by a team
    int red_cards = 0; //number of red cards received by a team
} a, b; //a corresponds to a team, b corresponds to b team

//initialization
int main() {
    start_soccer_game();
}

//initialize soccer game
void start_soccer_game() {
    srand(time(NULL)); //ensures numbers will not constantly repeat
    int event_number = rand() % 20 + 1; //randomizes event number between 1 and 20
    int halftime = round(event_number / 2); //halftime variable (half of all events)
    
    cout << "WELCOME TO THE FIFA FINALS! LET THE GAMES BEGIN!!!\n\n\n" << endl;

    //for loop to loop through all events
    for (int event = 1; event <= event_number; event++) {
        //action for the specific event
        event_action();
        cout << "\n";

        //halftime stats (output struct stats)
        if (event == halftime) {
            cout << "\n\nHALFTIME STATS:\n" << endl;

            cout << "TEAM A:\n";
            cout << "Shots On Goal: " << a.shots_on << endl;
            cout << "Shots Off Goal: " << a.shots_off << endl;
            cout << "Blocked Shots: " << a.blocked_shots << endl;
            cout << "Fouls: " << a.fouls << endl;
            cout << "Yellow Cards: " << a.yellow_cards << endl;
            cout << "Red Cards: " << a.red_cards << endl;

            cout << "\nTEAM B:\n";
            cout << "Shots On Goal: " << b.shots_on << endl;
            cout << "Shots Off Goal: " << b.shots_off << endl;
            cout << "Blocked Shots: " << b.blocked_shots << endl;
            cout << "Fouls: " << b.fouls << endl;
            cout << "Yellow Cards: " << b.yellow_cards << endl;
            cout << "Red Cards: " << b.red_cards << endl;

            cout << "\nCURRENT SCORE: " << a.goals << " - " << b.goals << "\n\n\n" << endl; //score team a - team b
        }
        //final stats (output struct stats)
        else if (event == event_number) {
            cout << "\n\nFINAL STATS:\n" << endl;

            cout << "TEAM A:\n";
            cout << "Shots On Goal: " << a.shots_on << endl;
            cout << "Shots Off Goal: " << a.shots_off << endl;
            cout << "Blocked Shots: " << a.blocked_shots << endl;
            cout << "Fouls: " << a.fouls << endl;
            cout << "Yellow Cards: " << a.yellow_cards << endl;
            cout << "Red Cards: " << a.red_cards << endl;

            cout << "\nTEAM B:\n";
            cout << "Shots On Goal: " << b.shots_on << endl;
            cout << "Shots Off Goal: " << b.shots_off << endl;
            cout << "Blocked Shots: " << b.blocked_shots << endl;
            cout << "Fouls: " << b.fouls << endl;
            cout << "Yellow Cards: " << b.yellow_cards << endl;
            cout << "Red Cards: " << b.red_cards << endl;

            cout << "\nFINAL SCORE: " << a.goals << " - " << b.goals << "\n\n\n" << endl; //score team a - team b
        }
    }
}

//rng for events
void event_action() {
    int event_action = rand() % 6 + 1;
    event_type(event_action);
}

//event type to correspond to event number
void event_type(int event_action) {
    //switch case to correspond
    switch (event_action) {
        case 1:
            cout << "Team A has shot the ball!" << endl;

            //run shot action function then check for the booleans to determine struct incrementation
            shot_action();
            if (goal) {
                a.goals += 1;
            }

            if (shot_on) {
                a.shots_on += 1;
            } else {
                a.shots_off += 1;
            }
            
            if (blocked) {
                b.blocked_shots += 1;
            }
            break;

        case 2:
            cout << "Team B has shot the ball!" << endl;

            //run shot action function then check for the booleans to determine struct incrementation
            shot_action();
            if (goal) {
                b.goals += 1;
            }

            if (shot_on) {
                b.shots_on += 1;
            } else {
                b.shots_off += 1;
            }

            if (blocked) {
                a.blocked_shots += 1;
            }
            break;

        case 3:
            cout << "Team B has fouled Team A! Free Kick has been awarded!" << endl;
            //run foul action function then check for the booleans to determine struct incrementation
            foul_action();
            if (yellow_card) {
                b.fouls += 1;
                b.yellow_cards += 1;
            } else if (red_card) {
                b.fouls += 1;
                b.red_cards += 1;
            }

            //run shot action function then check for the booleans to determine struct incrementation
            shot_action();
            if (goal) {
                a.goals += 1;
            }

            if (shot_on) {
                a.shots_on += 1;
            } else {
                a.shots_off += 1;
            }

            if (blocked) {
                b.blocked_shots += 1;
            }
            break;

        case 4:
            cout << "Team A has fouled Team B! Free Kick has been awarded!" << endl;
            //run foul action function then check for the booleans to determine struct incrementation
            foul_action();
            if (yellow_card) {
                a.fouls += 1;
                a.yellow_cards += 1;
            } else if (red_card) {
                a.fouls += 1;
                a.red_cards += 1;
            }

            //run shot action function then check for the booleans to determine struct incrementation
            shot_action();
            if (goal) {
                b.goals += 1;
            }

            if (shot_on) {
                b.shots_on += 1;
            }
            else {
                b.shots_off += 1;
            }

            if (blocked) {
                a.blocked_shots += 1;
            }
            break;

        case 5:
            cout << "Team B has fouled Team A! Free Kick has been awarded!" << endl;
            //run foul action function then check for the booleans to determine struct incrementation
            foul_action();
            if (yellow_card) {
                b.fouls += 1;
                b.yellow_cards += 1;
            } else if (red_card) {
                b.fouls += 1;
                b.red_cards += 1;
            }
            //run penalty shot action function then check for the booleans to determine struct incrementation
            penalty_action();
            if (goal) {
                a.goals += 1;
            }

            if (shot_on) {
                a.shots_on += 1;
            } else {
                a.shots_off += 1;
            }

            if (blocked) {
                b.blocked_shots += 1;
            }
            break;

        case 6:
            cout << "Team A has fouled Team B near the goal! Penalty Kick has been awarded!" << endl;
            //run foul action function then check for the booleans to determine struct incrementation
            foul_action();
            if (yellow_card) {
                a.fouls += 1;
                a.yellow_cards += 1;
            } else if (red_card) {
                a.fouls += 1;
                a.red_cards += 1;
            }

            //run penalty shot action function then check for the booleans to determine struct incrementation
            penalty_action();
            if (goal) {
                b.goals += 1;
            }

            if (shot_on) {
                b.shots_on += 1;
            } else {
                b.shots_off += 1;
            }

            if (blocked) {
                a.blocked_shots += 1;
            }
            break;
    }
}

//rng for shot
void shot_action() {
    int shot_action = rand() % 4;
    shot_type(shot_action);
}

//rng for penalty shot
void penalty_action() {
    int shot_action = rand() % 3;
    shot_type(shot_action);
}

//rng for foul
void foul_action() {
    int foul_action = rand() % 3;
    foul_type(foul_action);
}

//takes shot action and correspondin
void shot_type(int shot_action) {
    switch (shot_action) {
        //goal scored; change booleans to represent case
        case 0:
            cout << "GOOOOOAAALL!!!" << endl;
            goal = true;
            shot_on = true;
            blocked = false;
            break;
        //blocked by final defender; change booleans to represent case
        case 1:
            cout << "Blocked by Goalkeeper!" << endl;
            goal = false;
            shot_on = true;
            blocked = true;
            break;
        //missed goal; change booleans to represent case
        case 2:
            cout << "Wide Miss..." << endl;
            goal = false;
            shot_on = false;
            blocked = false;
            break;
        //not goalie blocks ball; change booleans to represent case
        case 3:
            cout << "Huge block by defender!" << endl;
            goal = false;
            shot_on = false;
            blocked = true;
            break;
    }
}

//takes foul action and relates it to foul type
void foul_type(int foul_action) {
    switch (foul_action) {
        //no card given; change booleans to represent case
        case 0:
            cout << "No card was given." << endl;
            yellow_card = false;
            red_card = false;
            break;
        //yellow card; change booleans to represent case
        case 1:
            cout << "Yellow card was given." << endl;
            yellow_card = true;
            red_card = false;
            break;
        //red card; change booleans to represent case
        case 2:
            cout << "Red card was given." << endl;
            yellow_card = false;
            red_card = true;
            break;
    }
}