/*
Program name : MouaJustin_DiscrMath_PrgmPA2SN1.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 14 October 2023
Description  : Given subsets A and B of a set of integers with n elements.
               For example, subset A = {1, 2, 3, 4, 5} and subset B = {4, 5, 6, 7, 8}.
               Write a program to find Complement of A, Union of A and B, Intersection of A and B, 
               A - B, and A XOR B. The value of n, i.e., the number of elements in 
               both the subsets and actual elements in both the subsets, must be taken by the 
               user through the keyboard.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fnPrintVec(vector<int> vec)
{
    //Must be numerically sorted before being put into the array. Otherwise, erasing duplicates won't work.
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    if (vec.size() == 1) {
        cout << vec[0];
    }
    else {
        for (int i = 0; i < vec.size(); i++)
            if (i != vec.size() - 1) {
                cout << vec[i] << ", ";
            }
            else {
                cout << "& " << vec[i] << ".";
            }
    }
    cout << endl;
}

void fnBubbleSort(vector<int> vec) {
    int i, j;
    bool swapped;
    for (i = 0; i < vec.size() - 1; i++) {
        swapped = false;
        for (j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
    fnPrintVec(vec);
}

void fnAUnionB(vector<int> vecA, vector<int> vecB) {
    vector<int> vecTemp;
    for (int i = 0; i < vecA.size(); i++) {
        vecTemp.push_back(vecA[i]);
    }
    for (int i = 0; i < vecB.size(); i++) {
        vecTemp.push_back(vecB[i]);
    }
    fnBubbleSort(vecTemp);
}

void fnAIntersectB(vector<int> vecA, vector<int> vecB) {

    vector<int> vecTemp;

    bool match = false;
    bool isNull = false;
    for (int i = 0; i < vecA.size(); i++) {
        for (int j = 0; j < vecB.size(); j++) {
            if (vecA[i] == vecB[j]) {
                match = true;
            }
        }
        if (match == true) {
            vecTemp.push_back(vecA[i]);
        }
        match = false;
    }
    
    if (vecTemp.size() == 0) {
        cout << "No Values Valid for an Intersection";
    }
    else {
        fnBubbleSort(vecTemp);
    }

}

void fnADiffB(vector<int> vecA, vector<int> vecB) {
    vector<int> vecTemp;

    bool isNull = false;
    bool match = false;
    for (int i = 0; i < vecA.size(); i++) {
        for (int j = 0; j < vecB.size(); j++) {
            if (vecA[i] == vecB[j]) {
                match = true;
            }
        }
        if (match == false) {
            vecTemp.push_back(vecA[i]);
        }
        match = false;
    }
    if (vecTemp.size() == 0) {
        cout << "No Values Valid for a difference operation";
    }
    else {
        fnBubbleSort(vecTemp);
    }

}

void fnASymDiffB(vector<int> vecA, vector<int> vecB) {
    vector<int> vecTemp;

    bool match = false;
    bool isNull = false;
    //A - B
    for (int i = 0; i < vecA.size(); i++) {
        for (int j = 0; j < vecB.size(); j++) {
            if (vecA[i] == vecB[j]) {
                match = true;
            }
        }
        if (match == false) {
            vecTemp.push_back(vecA[i]);
        }
        match = false;
    }

    //B - A
    for (int i = 0; i < vecA.size(); i++) {
        for (int j = 0; j < vecB.size(); j++) {
            if (vecA[j] == vecB[i]) {
                match = true;
            }
        }
        if (match == false) {
            vecTemp.push_back(vecB[i]);
        }
        match = false;
    }
    if (vecTemp.size() == 0) {
        cout << "No Values Valid for a symmetric difference operation";
    }
    else {
        fnBubbleSort(vecTemp);
    }
}

bool fnContinueOrNo() {
    bool tOrF = true;
    while (true) {
        string usrInp;
        cout << endl << endl;
        cout << "========================\nContinue with same list?\n========================\n\nEnter Y or N here: ";
        cin >> usrInp;

        if (usrInp == "Y" || usrInp == "y") {
            break;
        }
        else if (usrInp == "N" || usrInp == "n") {
            tOrF = false;
            break;
        }
        else {
            cout << endl;
            cout << "=============\nInvalid Input\n============\n\nPlease try again! Either enter Y or N.\n\n";
        }

    }
    return tOrF;
}

int main()
{
    vector<int> listA;
    vector<int> listB;
    int intInpUsrSizeOfList;

    cout << "\n==============================================================\n\nAssignment: PA2SN1\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";
    cout << "What size do you want the lists to be? Enter here : ";
    cin >> intInpUsrSizeOfList;
    cout << endl;

    //========================Take Input for List A Starts Here========================
    cout << "==========================\nEnter elements for list A\n==========================\n";
    for (int i = 0; i < intInpUsrSizeOfList; i++) {
        int intUsrInp;
        cout << "\nEnter value for element " << i << " here: ";
        cin >> intUsrInp;
        listA.push_back(intUsrInp);
    }

    cout << endl;
    cout << "Excluding duplicates, you have entered the following into list A: ";
    fnBubbleSort(listA);
    cout << endl;
    //========================Take Input for List A Ends Here========================

    //========================Take Input for List B Starts Here========================

    cout << "==========================\nEnter elements for list B\n==========================\n";
    for (int i = 0; i < intInpUsrSizeOfList; i++) {
        int intUsrInp;
        cout << "\nEnter value for element " << i << " here: ";
        cin >> intUsrInp;
        listB.push_back(intUsrInp);
    }

    cout << endl;
    cout << "Excluding duplicates, you have entered the following into list B: ";
    fnBubbleSort(listB);
    //========================Take Input for List B Ends Here========================




    bool tOrF = true;
    while (tOrF == true) {
        //Ask user which operation they want to perform.
        int intUsrOpInput;
        cout << endl;
        cout << "================\nChoose Operation\n================\n\nNote: These are the values in your list (excluding duplicates)\nSet A consists of numbers ";
        fnPrintVec(listA);
        cout << "Set B consists of numbers ";
        fnPrintVec(listB);
        cout << endl;
        
        cout << "1. Complement\n2. Union\n3. Intersection\n4. Difference\n5. Symmetric Difference\n6. Quit the program\n\nEnter with a number from 1-6: ";
        cin >> intUsrOpInput;
        cout << endl;

        //Complement
        if (intUsrOpInput == 1) {
            //===============COMPLEMENT OF A STARTS HERE ===============COMPLEMENT OF A STARTS HERE===============
            //This loop is made to make sure that the user selects a correct input. If the user has not, then the loop needs to continue. Otherwise, set false and stop loop. 
            bool boolContinueWithLoop = true;
            while (boolContinueWithLoop) {
                //Asks whether user wants to find complement of A or B. 
                int intInpOp1OrOp2;
                cout << "==========\nComplement\n==========\n\nWhat would you like to find the complement of? Enter 1 or 2.\n1. A\n2. B\nEnter here: ";
                cin >> intInpOp1OrOp2;

                cout << endl;
                
                //Checks whether user wants wanted to find complement of A or B. 1 = A and 2 = B. Otherwise, ask again. 
                switch (intInpOp1OrOp2) {
                    //Complement of A
                    case 1:
                        cout << "===============\nComplement of A\n===============\n\nSet A consists of Numbers ";
                        fnPrintVec(listA);
                        cout << "\nSet B consists of numbers: ";
                        fnPrintVec(listB);
                        cout << "\n\nThus, the complement of A is all integers except for ";
                        fnPrintVec(listA);
                        cout << "\nThis is because {x is an element of Z->Z | x is not an element of A} where A is and Z->Z is every integer that is not included in A.";
                        boolContinueWithLoop = false;
                        break;
                    
                    //Complement of B
                    case 2:
                        cout << "===============\nComplement of B\n===============\n\nSet A consists of Numbers ";
                        fnPrintVec(listA);
                        cout << "\nSet B consists of numbers: ";
                        fnPrintVec(listB);
                        cout << "\n\nThus, the complement of B is all integers except for ";
                        fnPrintVec(listB);
                        cout << "\nThis is because {x is an element of Z->Z | x is not an element of B} where B is and Z->Z is every integer that is not included in A.";
                        boolContinueWithLoop = false;
                        break;
                    default:
                        cout << "=============\nInvalid Input\n============\n\nPlease try again! Either enter 1 or 2.\n\n";

                }
            }
            //===============COMPLEMENT OF A ENDS HERE ===============COMPLEMENT OF A ENDS HERE===============
            tOrF = fnContinueOrNo();
        }
        
        //Union
        else if (intUsrOpInput == 2) {

            //===============A UNION B STARTS HERE===============A UNION B STARTS HERE===============
            cout << endl << endl;
            cout << "=========\nA Union B\n=========\n\n*Note that this also applies for B U A*\nSet A consists of numbers ";
            fnPrintVec(listA);
            cout << "\nSet B consists of numbers ";
            fnPrintVec(listB);
            cout << "\nThus, A U B : ";
            fnAUnionB(listA, listB);
            //===============A UNION B ENDS HERE===============A UNION B ENDS HERE===============
            tOrF = fnContinueOrNo();
        }
        
        //Intersectoin
        else if (intUsrOpInput == 3) {
            //===============A INTERSECT B STARTS HERE===============A INTERSECT B STARTS HERE===============
            cout << endl << endl;
            cout << "=============\nA Intersect B\n=============\n\n*Note that B Intersects A results in the same output*\nSet A consists of numbers ";
            fnPrintVec(listA);
            cout << "\nSet B consists of numbers ";
            fnPrintVec(listB);
            cout << "\nThus, A intersection B : ";
            fnAIntersectB(listA, listB);
            //===============A INTERSECT B ENDS HERE===============A INTERSECT B ENDS HERE===============
            tOrF = fnContinueOrNo();
        }
        
        //Difference
        else if (intUsrOpInput == 4) {
            //===============A DIFF B STARTS HERE===============A DIFF B STARTS HERE===============
            //This loop is made to make sure that the user selects a correct input. If the user has not, then the loop needs to continue. Otherwise, set false and stop loop. 
            bool boolContinueWithLoop = true;
            while (boolContinueWithLoop) {
                //Asks whether user wants to find difference of A and B (A-B) or the difference of B and A (B-A). 
                int intInpOp1OrOp2;
                cout << "=========\nDifference\n=========\n\nWhat would you like to find the difference of? Enter 1 or 2.\n1. A - B\n2. B - A\nEnter here: ";
                cin >> intInpOp1OrOp2;

                cout << endl;

                //Checks whether user wants to find difference of A and B (A-B) or the difference of B and A (B-A). 1 = A-B and 2 = B-A.
                switch (intInpOp1OrOp2) {
                    //A - B
                    case 1:
                        cout << endl << endl;
                        cout << "========\nA DIFF B\n========\n\nSet A consists of numbers ";
                        fnPrintVec(listA);
                        cout << "\nSet B consists of numbers ";
                        fnPrintVec(listB);
                        cout << "\nThus, A - B : ";
                        fnADiffB(listA, listB);
                        boolContinueWithLoop = false;
                        break;

                    //B - A
                    case 2:
                        cout << endl << endl;
                        cout << "========\nB DIFF A\n========\n\nSet A consists of numbers ";
                        fnPrintVec(listA);
                        cout << "\nSet B consists of numbers ";
                        fnPrintVec(listB);
                        cout << "\nThus, A - B : ";
                        fnADiffB(listB, listA);
                        boolContinueWithLoop = false;
                        break;
                    default:
                        cout << "=============\nInvalid Input\n============\n\nPlease try again! Either enter 1 or 2.\n\n";

                }
            }

            //===============A DIFF B ENDS HERE===============A DIFF B ENDS HERE===============
            tOrF = fnContinueOrNo();
        }
        
        //Symmetrical Difference
        else if (intUsrOpInput == 5) {
            //===============A SYMM DIFF B STARTS HERE===============A SYMM DIFF B STARTS HERE===============
            cout << endl << endl;
            cout << "========\nA XOR B\n========\n\n*Note That B XOR A results in the same output*\nSet A consists of numbers ";
            fnPrintVec(listA);
            cout << "\nSet B consists of numbers ";
            fnPrintVec(listB);
            cout << "\nThus, A XOR B : ";
            fnASymDiffB(listA, listB);
            //===============A SYMM DIFF B ENDS HERE===============A SYMM DIFF B ENDS HERE===============
            tOrF = fnContinueOrNo();
        }
        else if (intUsrOpInput = 6) {
            break;
        }
        //Invalid Input
        else {
            cout << endl << endl;
            cout << "=============\nInvalid Input\n=============\n\nPlease enter a number from 1 to 5.\n\n";
        }

    }

    cout << "\n===================\nClick enter to quit\n===================\n";
    cin.get();
}
