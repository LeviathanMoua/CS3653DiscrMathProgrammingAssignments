/*
Program name : MouaJustin_DiscrMath_PrgmPA3SN1.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 4 November 2023
Description  : Given the positive integers a, b, and m with m > 1, find (a^b) mod m.
               The value of a, b and m should be taken from the user through keyboard. 
*/


#include <iostream>
#include <cmath>

int main(){
    int intA;
    int intB;
    int intM;
    std::cout << "\n==============================================================\n\nAssignment: PA3SN1\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";

    bool boolStayOrQuit = true;
    while (true) {

        std::cout << "This program will take inputs a, b, and m to compute (a^b) % m.";
        std::cout << std::endl << std::endl;

        std::cout << "Enter integer A: ";
        std::cin >> intA;
        std::cout << std::endl;

        std::cout << "Enter integer B: ";
        std::cin >> intB;
        std::cout << std::endl;

        std::cout << "Enter integer M: ";
        std::cin >> intM;
        std::cout << std::endl;

        int result = pow(intA, intB);
        result = result % intM;

        std::cout << "(a^b) % m = (" << intA << "^" << intB << ") % " << intM << " = " << result;
        std::cout << std::endl << std::endl;
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
    std::cin.get();
}