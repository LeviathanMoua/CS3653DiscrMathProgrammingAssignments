/*
Program name : MouaJustin_DiscrMath_PrgmPA3SN3.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 4 November 2023
Description  : Determine which Fibonacci numbers are divisible by 2 or 3, and 5, out of the first n terms.
               The value of n should be taken from the user through keyboard. 

*/

#include <iostream>
#include <cmath>

//Function that outputs fibonacci numbers. 
int fnIntFibonacci(int intN) {
    //If the number is <= 1, return its given value. 
    if (intN <= 1) {
        return intN;
    }
    //Otherwise, we want to add the previous two values w/each other. 
    //Say intN = 3. fnIntFibonacci(3-1 = 2) + fnIntFibonacci(3-2 = 1)
    //then becomes (fnIntFibonacci(2-1 = 1) + fIntFibonacci(2-2 = 0)) + fnIntFibonacci(3-2 = 1)
    //Which becomes 1 + 0 + 1 = 2. 
    else {
        return fnIntFibonacci(intN - 1) + fnIntFibonacci(intN - 2);
    }
    
}

int main()
{
    int intN;
    bool boolStayOrQuit = true;
    std::cout << "\n==============================================================\n\nAssignment: PA3SN4\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";
    std::cout << std::endl << std::endl;
    


    while (true) {
        std::cout << "This program will find the first fnIntFibonaccionacci numbers that are divisible by 2 or 3 and 5 out of the first n terms you input. ";
        std::cout << std::endl << std::endl;

        std::cout << "Enter N here: ";
        std::cin >> intN;
        std::cout << std::endl;

        std::cout << "Given N = " << intN << ", the resulting fibonacci numbers are: ";
        for (int i = 0; i < intN; i++) {
            std::cout << fnIntFibonacci(i) << " ";
        }
        std::cout << std::endl << std::endl;

        int intEmptyCounter = 0;
        std::cout << "Those that are divisible 2 or 3 and 5 are: ";
        std::cout << std::endl << std::endl;
        for (int i = 0; i < intN; i++) {
            if (((fnIntFibonacci(i) % 2 == 0) && (fnIntFibonacci(i) % 3 == 0) && (fnIntFibonacci(i) % 5 == 0)) && (fnIntFibonacci(i) != 0)) {
                std::cout << fnIntFibonacci(i) << " is divisble by 2, 3 and 5.";
                std::cout << std::endl;
                intEmptyCounter += 1;

            }
            else if (((fnIntFibonacci(i) % 2 == 0) && (fnIntFibonacci(i) % 5 == 0)) && (fnIntFibonacci(i) != 0)) {
                std::cout << fnIntFibonacci(i) << " is divisble by 2 and 5.";
                std::cout << std::endl;
                intEmptyCounter += 1;

            }
            else if (((fnIntFibonacci(i) % 3 == 0) && (fnIntFibonacci(i) % 5 == 0)) && (fnIntFibonacci(i) != 0)) {
                std::cout << fnIntFibonacci(i) << " is divisble by 3 and 5.";
                std::cout << std::endl;
                intEmptyCounter += 1;
            }
        }

        if (intEmptyCounter == 0) {
            std::cout << "None.";
            std::cout << std::endl;
        }

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
    return 0;
}