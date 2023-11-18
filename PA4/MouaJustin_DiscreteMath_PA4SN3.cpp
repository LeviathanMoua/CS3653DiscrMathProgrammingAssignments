/*
Program name : MouaJustin_DiscreteMath_PrgmPA4SN3.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 12 November 2023
Description  : Write a program with the specified input and output. Take the value of n (>=2) from
			   the keyboard. (Based on CH-8). To solve the Tower of Hanoi problem with n disks using recursion. 
*/
#include <iostream>

/* 
Refered to a textbook for some help that
I used at Tulsa Community College that discussed of the Tower of Hanoi
problem. Data Structures, A Pseudocode Approach with C by Richard F. Gilberg 
and Behrouz A. Forouzan. 

===================== towers =====================
Move one disk from source to destination through
the use of recursion.
 Pre The tower consists of n disks
 Source, destination, & auxiliary towers
 Post Steps for moves printed
*/


void fnTowerOfHanoi(int n, char A, char B, char C)
{
	if (n > 0) {
		std::cout << "Towers (" << n << ", " << A << ", " << B << ", " << C << ")";
		std::cout << std::endl;

		//move n-1 disks from a to b using c
		fnTowerOfHanoi(n - 1, A, C, B);
		//move a disc from a to c using b and display this step performed. Also note that a and c are different in the next called function
		std::cout << "Move a disk from " << A << " to " << C;
		std::cout << std::endl;
		std::cout << std::endl;
		fnTowerOfHanoi(n - 1, B, A, C);
	}

}

int main(){
	//Declarations (if any)
	int intNumDisks;

	//Declarations & Initializations (if any)

	// Statements
	std::cout << "\n==============================================================\n\nAssignment: PA4SN3\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";
	std::cout << std::endl << std::endl;
	
	//While loop to continously run the program until asked to stop.
	while (true) {


		//Asks user to input N
		while (true) {
			std::cout << "Enter value for N where N is greater than or equal to 2 here: ";
			std::cin >> intNumDisks;
			std::cout << std::endl;
			std::cout << std::endl;

			if (intNumDisks < 2) {
				std::cout << "==============\nInvalid Input!\n==============\n\nPlease enter a value N greater than or equal to 2!";
				std::cout << std::endl;
				std::cout << std::endl;
			}
			else {
				break;
			}
		}

		std::cout << "When solving the Tower of Hanoi Problem with n = " << intNumDisks << " disks, it takes ";

		//function call here

		fnTowerOfHanoi(intNumDisks, 'A', 'B', 'C');
		std::cout << std::endl << std::endl;


		//=====================WHILE LOOP TO STAY OR QUIT STARTS HERE=====================WHILE LOOP TO STAY OR QUIT STARTS HERE=====================
		bool boolStayOrQuit = true;
		std::string strUsrInpContinueOrNo;
		while (true) {

			std::cout << "===========================\nWould you like to continue?\n===========================\n\nEnter Y or N here: ";
			std::cin >> strUsrInpContinueOrNo;
			std::cout << std::endl;

			if (strUsrInpContinueOrNo == "Y" || strUsrInpContinueOrNo == "y") {
				std::cout << std::endl;
				break;
			}
			else if (strUsrInpContinueOrNo == "N" || strUsrInpContinueOrNo == "n") {
				boolStayOrQuit = false;
				std::cout << std::endl;
				break;
			}
			else {
				std::cout << "=============\nInvalid Input!\n=============\n\nPlease enter Y or N.";
				std::cout << std::endl;
				std::cout << std::endl;
			}

		}
		//If the user has selected to quit, boolStayOrQuit will be false and thus break the while loop. 
		if (boolStayOrQuit == false) {
			break;
		}
		//=====================WHILE LOOP TO STAY OR QUIT ENDS HERE=====================WHILE LOOP TO STAY OR QUIT ENDS HERE=====================

	}


	return 0;
}
