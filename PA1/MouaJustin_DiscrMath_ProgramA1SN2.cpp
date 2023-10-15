/*
Program name : MouaJustin_DiscrMath_PrgmA1SN2.cpp
Author       : Justin Moua
Date         : 9/25/2023
Description  : Given two bit strings of length n, find the bitwise AND, bitwise OR, and bitwise XOR of
			   these strings. (The value of n should be taken by user through the keyboard.) 
*/
#include <iostream> 
#include <string>
#include <sstream>

int main() {
	using namespace std; 

	cout << "===================================\n\nName: Justin Moua\nProfessor: Sachin Jain\nCourse: Discrete Mathematics\nProgramming Assignment - 1 | SN2\n\n===================================\n\n";

	bool boolContinue = true;
	while (boolContinue == 1) {

		//==================VARIABLE INITIALIZATION=====================VARIABLE INITIALIZATION=====================
		int n;
		string strBitString1;
		string strBitString2;
		//==================VARIABLE INITIALIZATION=====================VARIABLE INITIALIZATION=====================




		//===============================USER BITWISE STRING INPUT ENDS HERE============================USER BITWISE STRING INPUT ENDS HERE============================
		cout << "Please enter the length, n, that you would like your bit strings to be: ";
		cin >> n;
		//Checks to see if the user inputted bitwise strings of length n.
		while (true) {
			cout << "\nInput bitwise string 1 of length " << n << ": ";
			cin >> strBitString1;

			cout << "\nInput bitwise string 2 of length " << n << ": ";
			cin >> strBitString2;

			if (strBitString1.length() != n && strBitString2.length() != n) {
				cout << "\n=============\nInvalid input!\n=============\n\nOne of your strings is either more or less than the length, n, that you chose of " << n << ". Please try again. Both of them must be of length " << n << "." << endl << endl;
			}
			else {
				break;
			}
		}
		//===============================USER BITWISE STRING INPUT ENDS HERE============================USER BITWISE STRING INPUT ENDS HERE============================





		//===============================BIT OPERATIONS START HERE======================BIT OPERATIONS START HERE======================BIT OPERATIONS START HERE======================
		stringstream tmp_stream1;
		stringstream tmp_stream2;
		tmp_stream1 << strBitString1;
		tmp_stream2 << strBitString2;

		//Bitwise OR
		cout << "\nThe Bitwise OR of the two given strings is: ";
		for (int i = 0; i < n; i++)
		{

			if (tmp_stream1.str().at(i) == '1' || tmp_stream2.str().at(i) == '1') {
				cout << "1";
			}
			else {
				cout << "0";
			}
		}
		cout << endl;

		//Bitwise AND
		cout << "\nThe Bitwise AND of the two given strings is: ";
		for (int i = 0; i < n; i++)
		{

			if (tmp_stream1.str().at(i) == '1' && tmp_stream2.str().at(i) == '1') {
				cout << "1";
			}
			else {
				cout << "0";
			}
		}
		cout << endl;

		//Bitwise XOR
		cout << "\nThe Bitwise XOR of the two given strings is: ";
		for (int i = 0; i < n; i++)
		{

			if ((tmp_stream1.str().at(i) == '1' && tmp_stream2.str().at(i) == '1') || (tmp_stream1.str().at(i) == '0' && tmp_stream2.str().at(i) == '0')) {
				cout << "0";
			}
			else {
				cout << "1";
			}
		}
		cout << endl;
		//===============================BIT OPERATIONS END HERE======================BIT OPERATIONS END HERE======================BIT OPERATIONS END HERE======================


		//=============================ASK IF USER WANTS TO CONTINUE==========================
		while (true) {
			string strLoopChecker;
			cout << "\n========================\nDo you want to continue?\n========================\n\nNote: Y for Yes and N for No\n\nEnter here: ";
			cin >> strLoopChecker;
			cout << endl;
			if (strLoopChecker == "N" || strLoopChecker == "n") {
				boolContinue = 0;
				cout << endl;
				break;
			}
			else if (strLoopChecker == "Y" || strLoopChecker == "y") {
				cout << endl;
				break;
			}
			else {
				cout << "==========================================\nInvalid Input. Please either enter Y or N!\n==========================================";
				cout << endl << endl;
			}
		}
		//=============================ASK IF USER WANTS TO CONTINUE==========================

	}

	cout << endl << endl;

	return 0; 
} 