/*
Program name : MouaJustin_DiscreteMath_PrgmPA4SN1.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 11 November 2023
Description  :Write a program with the specified input and output. Take the value of n (>=2) and r
              (>=1) from the keyboard. (Based on CH-6).
              Given positive integers n and r, find the number of r-permutations when repetition is
              allowed and r-combinations when repetition is allowed of a set with n elements.
*/

#include <iostream>
#include <cmath>

int main()
{
    //Variable Declaration (if any)
    int intN;
    int intR;
    
    //Variable Declaration and Initialization (if any)
    int intWithRep = 1;
    int intWithoutRep = 1;

    //Introduction of Program
    std::cout << "\n==============================================================\n\nAssignment: PA4SN1\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";
    std::cout << std::endl << std::endl;


    while (true) {


        //=======================ASK FOR USER INPUT STARTS HERE====================ASK FOR USER INPUT STARTS HERE====================ASK FOR USER INPUT STARTS HERE====================
        
        //Asks user to input N
        while (true) {
            std::cout << "Enter value for N where N is greater than or equal to 2 here: ";
            std::cin >> intN;
            std::cout << std::endl;
            std::cout << std::endl;

            if (intN < 2) {
                std::cout << "==============\nInvalid Input!\n==============\n\nPlease enter a value N greater than or equal to 2!";
                std::cout << std::endl;
                std::cout << std::endl;
            }
            else {
                break;
            }
        }
        
        //Asks user to input R
        while (true) {
            std::cout << "Enter value for N where N is greater than or equal to 1 here: ";
            std::cin >> intR;
            std::cout << std::endl;
            std::cout << std::endl;

            if (intR < 1) {
                std::cout << "==============\nInvalid Input!\n==============\n\nPlease enter a value N greater than or equal to 1!";
                std::cout << std::endl;
                std::cout << std::endl;
            }
            else {
                break;
            }
        }

        //=======================ASK FOR USER INPUT ENDS HERE====================ASK FOR USER INPUT ENDS HERE====================ASK FOR USER INPUT ENDS HERE====================

        //======================OPERATION STARTS HERE======================OPERATION STARTS HERE======================OPERATION STARTS HERE======================

        //With repetition
        std::cout << "With repetition, P(n, r) = P(" << intN << ", " << intR << ") = ";
        for (int i = 0; i < intR; i++) {
            if (i == intR-1) {
                std::cout << intN;
            }
            else {
                std::cout << intN << " x ";
            }
            intWithRep = intWithRep * intN;
        }
        std::cout << " = " << intWithRep;
        std::cout << std::endl;
        std::cout << std::endl;

        //Without repition
        std::cout << "Without repetition, P(n, r) = P(" << intN << ", " << intR << ") = ";
        for (int i = 0; i < intR; i++) {
            if (i == intR - 1) {
                std::cout << intN-i;
            }
            else {
                std::cout << intN-i << " x ";
            }
            intWithoutRep = intWithoutRep * (intN-i);
        }
        std::cout << " = " << intWithoutRep;
        std::cout << std::endl;
        std::cout << std::endl;

        //resets values incase user wants to go through the program again
        intWithRep = 1;
        intWithoutRep = 1;

        //======================OPERATION ENDS HERE======================OPERATION ENDS HERE======================OPERATION ENDS HERE======================

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
}