/*
Program name : MouaJustin_DiscrMath_PrgmA1SN1.cpp
Author       : Justin Moua
Date         : 9/25/2023
Description  : Given the truth values of the propositions p and q, find the truth values of the
			   conjunction, disjunction, exclusive or, conditional statement, and biconditional of these
			   propositions. (You may use numeric value 0 to represent “False” and numeric value 1 to
			   represent “True”.) 
*/
#include <iostream> 
#include <string>

int main(){ 
	using namespace std;

	//============Variable Declaration Starts Here===========
	string strTruthValP;
	string strTruthValQ;
	
	bool boolContinue = true;
	//============Variable Declaration Ends Here===========

	cout << "===================================\n\nName: Justin Moua\nProfessor: Sachin Jain\nCourse: Discrete Mathematics\nProgramming Assignment - 1 | SN1\n\n===================================\n\n";

	while (boolContinue == 1){

		//=======================INPUT STARTS HERE===================INPUT STARTS HERE===================INPUT STARTS HERE===================
		//Input for P
		cout << "\n===========\nInput For P\n===========\n\nInput a truth value for P with T as true or F as false.\nEnter here: ";
		cin >> strTruthValP;
		cout << endl;


		//Input for Q
		cout << "\n===========\nInput For Q\n===========\n\nInput a truth value for Q with T as true or F as false.\nEnter here: ";
		cin >> strTruthValQ;
		cout << endl;
		//=======================INPUT ENDS HERE===================INPUT ENDS HERE===================INPUT ENDS HERE===================
 

		//======================IF STATEMENTS START HERE=================IF STATEMENTS START HERE=================IF STATEMENTS START HERE=================
		
		//CONJUNCTION
		cout << "\n===========\nConjunction\n===========\n\nThe Conjunction of P and Q is: ";
		if (strTruthValP == "T" && strTruthValQ == "T") {
			cout << "True" << endl << endl;
		}
		else {
			cout << "False" << endl << endl;
		}

		//DISJUNCTION
		cout << "\n===========\nDisjunction\n===========\n\nThe Disjunction of P and Q is: ";
		if (strTruthValP == "F" && strTruthValQ == "F") {
			cout << "False" << endl << endl;
		}
		else {
			cout << "True" << endl << endl;
		}

		//EXCLUSIVE OR
		cout << "\n============\nExclusive Or\n============\n\nThe Exclusive Or of P and Q is: ";
		if ((strTruthValP == "T" && strTruthValQ == "T") || (strTruthValP == "F" && strTruthValQ =="F")) {
			cout << "False" << endl << endl;
		}
		else {
			cout << "True" << endl << endl;
		}

		//CONDITIONAL STATEMENT/IMPLICATION
		cout << "\n=================================\nConditional Statement/Implication\n=================================\n\nThe Conditional Statement (Implication) of P and Q is: ";
		if (strTruthValP == "T" && strTruthValQ == "F") {
			cout << "False" << endl << endl;
		}
		else {
			cout << "True" << endl << endl;
		}

		//BI-CONDITIONAL
		cout << "\n===============\nBi-Conditional\n===============\n\nThe Bi-Condition of P and Q is: ";
		if ((strTruthValP == "T" && strTruthValQ == "T") || (strTruthValP == "F" && strTruthValQ == "F")) {
			cout << "True" << endl << endl;
		}
		else {
			cout << "False" << endl << endl;
		}
		//======================IF STATEMENTS END HERE=================IF STATEMENTS END HERE=================IF STATEMENTS END HERE=================


		//While loop to indicate whether a user wants to continue the progrma
		while (true) {
			string strLoopChecker;
			cout << "\n========================\nDo you want to continue?\n========================\n\nNote: Y for Yes and N for No\n\nEnter here: ";
			cin >> strLoopChecker;
			cout << endl;
			if (strLoopChecker == "N") {
				boolContinue = 0;
				cout << endl;
				break;
			}
			else if (strLoopChecker == "Y") {
				cout << endl;
				break;
			}
			else {
				cout << "==========================================\nInvalid Input. Please either enter Y or N!\n==========================================";
				cout << endl << endl;
			}
		}
	}

	cout << endl << endl;

	return 0; 
} 