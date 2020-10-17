/*
************************************************************
Student Name: Nirmal Hegde
Student Number: 20894403

SYDE 121 Assignment 002 Question 002

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Distance Calculator
Purpose: Calculates and outputs time for distance of 15000m
Due Date: Friday, October 9th, 2020
*************************************************************


STEPS FOR STEP 1:
1. Create table layout for values and declare constants max time and gravity

2. Create for loop that increases by 1 every time to loop through seconds

3. Input function d=1/2*g*t^2 to calculate distance

4. Calculate current distance by subtracting total distance travelled (d) by the previous value of current distance

5. Output all values in a table format


STEPS FOR STEP 2:
1. Create table layout for values and declare constants max distance, gravity, and short distance (distance when close to the ground)

2. Create while loop that ensures the distance travelled is not greater than the max distance

3. Input function d=1/2*g*t^2 to calculate distance travelled

4. Calculate current distance by subtracting total distance travelled (d) by the previous value of current distance

5. Calculate total distance before ground by subtracting total distance travelled (d) from max distance

6. Output all values in a table format

7. Before end of while loop, create if statement to see if the total distance travelled is greater than the short distance (very close to the ground),
   if so, make t increment by 0.1 instead of 1


VALUES USED TO TEST PROGRAM LOGIC:
MAX_DISTANCE=15000 and SHORT_DISTANCE=14000 (given in question)
MAX_DISTANCE=900 and SHORT_DISTANCE=800 (to test hundreds place)
MAX_DISTANCE=90 and SHORT_DISTANCE=80 (to test tens place)
MAX_DISTANCE=9 and SHORT_DISTANCE=8 (to test ones place)


VALID RANGE OF VALUES:
Any positive real number would work (do not exceed double memory)


OUTPUT FOR STEP 2:
Time (s):           Distance During Interval (m):           Total Distance (m):
0                   0.000                                   15000.000
1                   4.903                                   14995.097
2                   14.710                                  14980.387
3                   29.420                                  14955.870
4                   49.033                                  14921.547
5                   73.550                                  14877.417
6                   102.970                                 14823.480
7                   137.293                                 14759.737
8                   176.520                                 14686.187
9                   220.650                                 14602.831
10                  269.683                                 14509.667
11                  323.619                                 14406.698
12                  382.459                                 14293.921
13                  446.203                                 14171.338
14                  514.849                                 14038.948
15                  588.399                                 13896.752
16                  666.852                                 13744.749
17                  750.209                                 13582.939
18                  838.469                                 13411.323
19                  931.632                                 13229.900
20                  1029.698                                13038.670
21                  1132.668                                12837.634
22                  1240.541                                12626.791
23                  1353.318                                12406.141
24                  1470.997                                12175.685
25                  1593.581                                11935.422
26                  1721.067                                11685.352
27                  1853.457                                11425.476
28                  1990.750                                11155.793
29                  2132.946                                10876.304
30                  2280.046                                10587.007
31                  2432.049                                10287.905
32                  2588.956                                9978.995
33                  2750.765                                9660.279
34                  2917.478                                9331.756
35                  3089.095                                8993.427
36                  3265.614                                8645.291
37                  3447.037                                8287.348
38                  3633.364                                7919.599
39                  3824.593                                7542.043
40                  4020.727                                7154.680
41                  4221.763                                6757.511
42                  4427.702                                6350.535
43                  4638.5                                  5933.752
44                  485492                                  5507.163
45                  50.941                                  5070.767
46                  00.494                                  4624.564
47                  5530.951                                4168.555
48                  5766.310                                3702.739
49                  6006.573                                3227.117
50                  6251.739                                2741.688
51                  6501.809                                2246.452
52                  6756.782                                1741.409
53                  7016.658                                1226.560
54.0                7281.438                                701.904
54.1                7069.663                                648.899
54.2                7334.541                                595.796
54.3                7122.864                                542.595
54.4                7387.840                                489.296
54.5                7176.261                                435.899
54.6                7441.335                                382.404
54.7                7229.855                                328.810
54.8                7495.026                                275.119
54.9                7283.644                                221.329
55.0                7548.914                                167.442
55.1                7337.630                                113.456
55.2                7602.998                                59.373
55.3                7391.811                                5.191
55.4                7657.277                               -49.089 (END)

Therefore, it takes approx. 55.3 seconds before the ball hits the ground
*/

//start using iostream and std and declare all libraries and constants
#include <iostream>
#include <iomanip>
using namespace std;
const double G = 9.80665;
const int MAX_DISTANCE = 15000; //did not exist in step 1
const int SHORT_DISTANCE = 14000; //did not exist in step 1
//const int MAX_TIME = 30; (USED IN STEP 1)

//used for ball calculations from the drone
void drone_calculations() {
	//Create title using setw
	std::cout << "Time (s):";
	std::cout << std::setw(40);
	std::cout << "Distance During Interval (m):";
	std::cout << std::setw(30);
	std::cout << "Total Distance (m):" << std::endl;

	//variable declaration
	double d_total = 0; //did not exist in step 1
	double d = 0;
	double d_current = 0;
	double t = 0;

	//while loop for looping as distance is less than max distance
	while (d < MAX_DISTANCE) {
		//calculation for distance travelled
		d = 0.5 * G * pow(t, 2);

		//calculate current distance travelled in the last 1 or 0.1 seconds and total distance before ground is reached
		d_current = d - d_current;
		d_total = MAX_DISTANCE - d;

		//values outputted and formatted using setprecision and setw
		if (d < SHORT_DISTANCE) {
			std::cout << std::fixed;
			std::cout << std::setprecision(0);
		}
		else {
			std::cout << std::fixed;
			std::cout << std::setprecision(1);
		}
		std::cout << t;
		std::cout << std::fixed;
		std::cout << std::setprecision(3);
		std::cout << std::setw(26);
		std::cout << d_current;
		std::cout << std::setw(42);
		std::cout << d_total << std::endl;

		//check if distance travelled is less than short distance, if it is greater, it means that the ball is close to the ground and resolution must increase
		if (d < SHORT_DISTANCE) {
			t += 1;
		}
		else {
			t += 0.1;
		}
	}
	/* USED IN STEP 1
		//for loop to loop through time before 30 seconds
		for (int t = 0; t <= MAX_TIME; t++) {
			//distance calculations
			d = 0.5 * G * pow(t, 2);

			//current distance travelled in the last second calculation
			d_current = d - d_current;

			//table formatting using setw
			std::cout << t;
			std::cout << std::setw(26);
			std::cout << std::fixed;
			std::cout << std::setprecision(3);
			std::cout << d_current;
			std::cout << std::setw(41);
			std::cout << d << std::endl;
		}
	*/
}

//root function to link to drone calculations
int main() {
	drone_calculations();
}