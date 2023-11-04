/*
Program name : MouaJustin_DiscrMath_PrgmPA3SN2.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 32 October 2023
Description  : Given a positive integer n, determine the Binary, Octal 
               and Hexadecimal equivalent of n. The value of n should be 
               taken from the user through keyboard. 
*/


#include <iostream>
#include <cmath>

int main()
{
    int intN;
    int boolStayOrQuit = true;

    std::cout << "\n==============================================================\n\nAssignment: PA3SN2\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";

    while (true) {

        std::cout << "This program will convert an integer into its binary, octal, and hexadecimal values.\n\nEnter an integer N: ";
        std::cin >> intN;
        


        //=============OUTPUT=============OUTPUT=============OUTPUT=============OUTPUT=============OUTPUT


        //=============OUTPUT=============OUTPUT=============OUTPUT=============OUTPUT=============OUTPUT

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