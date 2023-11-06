/*
Program name : MouaJustin_DiscrMath_PrgmPA3SN3.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 4 November 2023
Description  : Given a real number a and a nonnegative integer n, 
               find (a)^(2^n) using recursion. The value of a and
               n should be taken from the user through keyboard. 

*/

#include <iostream>
#include <cmath>

int intFn2PowN(int int2,  int intN) {

    if (intN == 0) {
        return 1;
    }
    else {
        for (int i = 0; i < intN; i++) {
            //This is only a recursion for n^2. Now figure out how to do the same thing 
            return int2 * (intFn2PowN(2, intN - 1));
        }
    }
    //=====Failed Attempt====
    //int int2PowN = 1;
    //if (intN == 0) {
    //    return 1;
    //}
    //else {
    //    for (int i = 0; i < intN; i++) {
    //        //This is only a recursion for n^2. Now figure out how to do the same thing 
    //        int2PowN = (2 * (aPow2PowN(2, intN - 1)));
    //        return intA * (aPow2PowN(intA, (2 * (aPow2PowN(2, intN - 1))) - 1));
    //    }
    //}

    ////Computes 2^n
    //int int2PowN = 1;
    //for (int i = 0; i < intN; i++) {
    //    if (intN != 0) {
    //        int2PowN = int2PowN * 2;
    //    }
    //}

    ////Computes a^(2^n)
    //int intResult = 1;
    //for (int i = 0; i < int2PowN; i++) {
    //    intResult = intResult * intA;
    //}
}

int intFnAPow2PowN(int intA, int intN) {
    if (intN == 0) {
        return 1;
    }
    else {
        for (int i = 0; i < intN; i++) {
            //This is only a recursion for n^2. Now figure out how to do the same thing 
            return intA * (intFnAPow2PowN(intA, intN - 1));
        }
    }
}

int main()
{
    int intA;
    int intN;
    bool boolStayOrQuit = true;
    std::cout << "\n==============================================================\n\nAssignment: PA3SN3\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";
    std::cout << std::endl << std::endl;

    while (true) {

        std::cout << "This program will computer a^(2^n).";
        std::cout << std::endl;

        std::cout << "Enter integer A: ";
        std::cin >> intA;
        std::cout << std::endl;

        std::cout << "Enter integer N: ";
        std::cin >> intN;
        std::cout << std::endl;

        std::cout << "a^(2^n) = " << intA << "^(2^" << intN << ") = " << intFnAPow2PowN(intA, intFn2PowN(2, intN));
        std::cout << std::endl << std::endl;

        //================NOT RECURSIVE, FOR LOOP ONLY================
        ////Computes 2^n
        //int int2PowN = 1;
        //for (int i = 0; i < intN; i++) {
        //    if (intN != 0) {
        //        int2PowN = int2PowN * 2;
        //    }
        //}

        ////Computes a^(2^n)
        //int intResult = 1;
        //for (int i = 0; i < int2PowN; i++) {
        //    intResult = intResult * intA;
        //}

        ////Ouput
        //std::cout << "a^(2^n) = " << intA << "^(2^" << intN << ") = " << intResult;
        //std::cout << std::endl << std::endl;
        //================NOT RECURSIVE, FOR LOOP ONLY================


        //Checks to see if user wants to continue
        //Var to check if user wants to continue
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
    }
}