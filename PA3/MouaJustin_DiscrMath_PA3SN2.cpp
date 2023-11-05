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
#include <string>

void fnDecimalToBinary(int intN) {
    //==============BINARY CONVERSION================
    std::vector<int> vecBinary; // list that will hold binary values


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
        vecBinary.push_back(intN % 2); // adds binary value to the back of string 
        i++; // i gets incremented for the next position in vector 
        intN = intN / 2;

    }

    reverse(vecBinary.begin(), vecBinary.end()); // reverses order of vector 

    std::string strFinalResult;

    for (int i = 0; i < vecBinary.size(); i++) {
        std::cout << vecBinary[i];
    }


    std::cout << std::endl;
    //==============BINARY CONVERSION================

}

void fnDecimalToOctal(int intN) {
    //==============OCTAL CONVERSION================
    std::vector<int> vecOctal; // list that will hold binary values


    int i = 0; // iterator for vector


    while (intN != 0)
    {
        //Similar approach with that of octal but instead we deal with base 8.
        vecOctal.push_back(intN % 8); // adds binary value to the back of string 
        i++; // i gets incremented for the next position in vector 
        intN = intN / 8;

    }

    reverse(vecOctal.begin(), vecOctal.end()); // reverses order of vector 

    for (int i = 0; i < vecOctal.size(); i++) {
        std::cout << vecOctal[i];
    }


    std::cout << std::endl;
    //==============OCTAL CONVERSION================

}

void fnDecimalToHexadecimal(int intN) {
    //==============HEXADECIMAL CONVERSION================
    std::vector<int>vecBinary; // list that will hold binary values


    int i = 0; // iterator for vector


    while (intN != 0)
    {
        //Similar approach with that of octal but instead we deal with base 8.
        vecBinary.push_back(intN % 2); // adds binary value to the back of string 
        i++; // i gets incremented for the next position in vector 
        intN = intN / 2;

    }

    reverse(vecBinary.begin(), vecBinary.end()); // reverses order of vector 

    std::string temp = "";

    //This checks to see if the binary number can be equally seperated into 4 bits. 
    //In some cases, we may have 1 1111 or 11 1111 or 111 1111 but need 0001 1111, 0011 1111, 0111 1111. This solves that problem.
    //Note that we also have a variable j. j will be used in the following for loop. 
    int j = 0;
    if ( (vecBinary.size() + 1) % 4 == 0) {
        temp = "0";
        j = 1;
        //std::cout << "\ntemp max size + 1 is true\n\n";
    }
    else if ( (vecBinary.size() + 2) % 4 == 0) {
        temp = "00";
        j = 2;
        //std::cout << "\ntemp max size + 2 is true\n\n";
    }
    else if ( (vecBinary.size() + 3) % 4 == 0) {
        temp = "000";
        j = 3;
        //std::cout << "\ntemp max size + 3 is true\n\n";
    }


    //If Binary string is MORE than length 4
    if (vecBinary.size() > 4) {
        //Loops through the the vector containing binary string.
        for (int i = 0; i < vecBinary.size(); i++) {

            //If j is 0. J may already be three to indicate for the given 0s that were not previously added if it were 1 1111 for example. Or it may be 2 or 1. 
            //When J = 0 though, we know that the entire bit string is equally splitted into 4 parts.
            //Thus, we have to be sure that we concatonate whatever is in num[0] to temp, in which temp is empty.
            if (j == 0) {
                temp = temp + std::to_string(vecBinary[i]);
                j = j + 1;
            }
            //J % 4 indicates that we have a 4 bit string. We want to the 4 bt string to a temp vector so that we can then 
            //convert that string into a hexadecimal later. 
            else if ((j % 4 == 0) && (j != 0)) {
                temp = "" + std::to_string(vecBinary[i]);
                //Resets j = 0 since we have already looped through a full length of 4 bit string. Or 4 characters.
                j = 0;
            }
            //If j is 5, 6, 7, 9, 10, 11, 13, etc., as long as j%4 != 0. 
            else {
                temp = temp + std::to_string(vecBinary[i]);
                if (temp == "0000") {
                    std::cout << "0";
                }
                else if (temp == "0001") {
                    std::cout << "1";
                }
                else if (temp == "0010") {
                    std::cout << "2";
                }
                else if (temp == "0011") {
                    std::cout << "3";
                }
                else if (temp == "0100") {
                    std::cout << "4";
                }
                else if (temp == "0101") {
                    std::cout << "5";
                }
                else if (temp == "0110") {
                    std::cout << "6";
                }
                else if (temp == "0111") {
                    std::cout << "7";
                }
                else if (temp == "1000") {
                    std::cout << "8";
                }
                else if (temp == "1001") {
                    std::cout << "9";
                }
                else if (temp == "1010") {
                    std::cout << "A";
                }
                else if (temp == "1011") {
                    std::cout << "B";
                }
                else if (temp == "1100") {
                    std::cout << "C";
                }
                else if (temp == "1101") {
                    std::cout << "D";
                }
                else if (temp == "1110") {
                    std::cout << "E";
                }
                else if (temp == "1111") {
                    std::cout << "F";
                }
                //std::cout << "Branch 3 is True. Thus, temp is: " << temp;
                //std::cout << std::endl << std::endl;
                j = j + 1;

            }
            //std::cout << std::endl;
        }
    }

    //If binary string is ONLY of length 4
    else {
        for (int i = 0; i < vecBinary.size(); i++) {
            temp = temp + std::to_string(vecBinary[i]);

        }
        if (temp == "0000") {
            std::cout << "0";
        }
        else if (temp == "0001") {
            std::cout << "1";
        }
        else if (temp == "0010") {
            std::cout << "2";
        }
        else if (temp == "0011") {
            std::cout << "3";
        }
        else if (temp == "0100") {
            std::cout << "4";
        }
        else if (temp == "0101") {
            std::cout << "5";
        }
        else if (temp == "0110") {
            std::cout << "6";
        }
        else if (temp == "0111") {
            std::cout << "7";
        }
        else if (temp == "1000") {
            std::cout << "8";
        }
        else if (temp == "1001") {
            std::cout << "9";
        }
        else if (temp == "1010") {
            std::cout << "A";
        }
        else if (temp == "1011") {
            std::cout << "B";
        }
        else if (temp == "1100") {
            std::cout << "C";
        }
        else if (temp == "1101") {
            std::cout << "D";
        }
        else if (temp == "1110") {
            std::cout << "E";
        }
        else if (temp == "1111") {
            std::cout << "F";
        }
    }

    std::cout << std::endl;
    //==============HEXADECIMAL CONVERSION================

}

int main()
{
    std::vector<int>vecBinaryVal; // list that will hold binary values
    int intN;
    bool boolStayOrQuit = true;

    std::cout << "\n==============================================================\n\nAssignment: PA3SN2\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";
    std::cout << std::endl << std::endl;

    while (true) {
        std::cout << "This program will convert a given integer into its binary, octal, and hexadecimal value.\n\nEnter Number here: ";
        std::cin >> intN; // number input 
        std::cout << std::endl;

        //Find a way to make fnDecimalToBinary into a int function that returns an int. 

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