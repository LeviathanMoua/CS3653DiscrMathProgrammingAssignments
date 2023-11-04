/*
Program name : MouaJustin_DiscrMath_PrgmPA3SN1.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 31 October 2023
Description  : Given the positive integers a, b, and m with m > 1, find ab mod m.
               The value of a, b and m should be taken from the user through keyboard.


*/


#include <iostream>
#include <vector>

void fnDecimalToBinary(int intN) {
    //==============BINARY CONVERSION================
    std::vector<int>nums; // list that will hold binary values


    int i = 0; // iterator for vector


    while (intN != 0)
    {
        //By taking the modulous, we can be given a value of 0 or 1 which can indicate whether
        //a given "binary position" is on or off. For example, 
        //we know that 9 = 1001. But to convert 9 we do
        //9%2 = 1. 9/2 then becomes 4.
        //4%2 = 0. 4/2 then becomes 2
        //2%2 = 0. 2/2 then becomes 1.
        //1%2 = 1. 1/2 then becomes 0.
        //Program stops since we have reached 0. Note that we do not
        //Have decimals since we are dealing with integer, not float!
        nums.push_back(intN % 2); // adds binary value to the back of string 
        i++; // i gets incremented for the next position in vector 
        intN = intN / 2;

    }

    reverse(nums.begin(), nums.end()); // reverses order of vector 

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
    }


    std::cout << std::endl;
    //==============BINARY CONVERSION================

}

void fnDecimalToOctal(int intN) {
    //==============OCTAL CONVERSION================
    std::vector<int>nums; // list that will hold binary values


    int i = 0; // iterator for vector


    while (intN != 0)
    {
        //Similar approach with that of octal but instead we deal with base 8.
        nums.push_back(intN % 8); // adds binary value to the back of string 
        i++; // i gets incremented for the next position in vector 
        intN = intN / 8;

    }

    reverse(nums.begin(), nums.end()); // reverses order of vector 

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
    }


    std::cout << std::endl;
    //==============OCTAL CONVERSION================

}

void fnDecimalToHexadecimal(int intN) {
    //==============HEXADECIMAL CONVERSION================
    std::vector<int>nums; // list that will hold binary values


    int i = 0; // iterator for vector


    while (intN != 0)
    {
        //Similar approach with that of octal but instead we deal with base 8.
        nums.push_back(intN % 16); // adds binary value to the back of string 
        i++; // i gets incremented for the next position in vector 
        intN = intN / 16;

    }

    reverse(nums.begin(), nums.end()); // reverses order of vector 

    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
    }


    std::cout << std::endl;
    //==============HEXADECIMAL CONVERSION================

}

int main()
{
    int intN;
    bool boolStayOrQuit = true;

    std::cout << "\n==============================================================\n\nAssignment: PA3SN2\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";
    std::cout << std::endl << std::endl;

    while (true) {
        std::cout << "This program will convert a given integer into its binary, octal, and hexadecimal value.\n\nEnter Number here: ";
        std::cin >> intN; // number input 
        std::cout << std::endl;

        std::cout << "Binary: ";
        fnDecimalToBinary(intN);
        std::cout << std::endl;

        std::cout << "Octal: ";
        fnDecimalToOctal(intN);
        std::cout << std::endl;


        std::cout << "Hexadecimal: ";
        fnDecimalToHexadecimal(intN);
        std::cout << std::endl;

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