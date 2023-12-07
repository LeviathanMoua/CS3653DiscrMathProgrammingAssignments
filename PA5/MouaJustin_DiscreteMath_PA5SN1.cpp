/*
Program name : MouaJustin_DiscreteMath_PA5SN1.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 9 December 2023
Description  : Let the relation R = {(a, b) | a divides b}
               on the set of Fibonacci numbers (excluding 0
               and 1), i.e., {1, 2, 3, 5, 8, 13, 21, 34, 55, …, n}. 
               List all the ordered pairs in this relation. 

               Note: a divides b 
                    a | b -> b = ac -> b/a = c
*/

#include <iostream>
#include <cmath>

//Function that outputs fibonacci numbers and borrowed from my previous Honors Assignment PA3 SN3.
int fnIntFibonacci(int intN) { 
    if (intN <= 1) {
        return intN;
    }
    else {
        return fnIntFibonacci(intN - 1) + fnIntFibonacci(intN - 2);
    }

}

int main()
{
    int intN; //Size of array
    bool boolStayOrQuit = true;
    std::cout << "\n==============================================================\n\nAssignment: PA5 SN1\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";
    std::cout << std::endl << std::endl;



    while (true) {
        std::cout << "This program will list all the ordered pairs in the relation of Fibonacci numbers where a divides b. ";
        std::cout << std::endl << std::endl;

        std::cout << "Enter N here: ";
        std::cin >> intN;
        std::cout << std::endl;

        std::cout << "Given N = " << intN << ", the resulting fibonacci numbers are: ";


        //========================NOTE TO SELF, RELEARNING ABOUT POINTERS IN C++===========================
        //Textbook Used: C++ Primer Plus by Stephen Prata. PAGES 153-167
        
        int* intPtrArray = new int[intN]; //Sought the follow link for help in respect to textbook. https://stackoverflow.com/questions/4029870/how-to-create-a-dynamic-array-of-integers-in-c
        //intPtrArray stores address of "new int [intN]" I think.
        //*intPtrArray gives us the value of what is stored in the address. 
        // new is a keyword that allocates memory IF WE DON'T DO THIS, it is literally UNDEFINED what we are accessing. 
        //          for example, we could access a memory address that another program is taking up which could be fatal
        // new int allocates memory for type int
        // We will need to delete this later to avoid memory leaks. 
        //========================NOTE TO SELF, RELEARNING ABOUT POINTERS IN C++===========================


        //Beforehand, the code had i <= intN. This would not work since we want to exclude the first
        //0 and 1. This means that the n amount of numbers we would receive are going to be n-2 integers. 
        //Thus, we would have to pass through i+2 into the fibonacci function to avoid obtaining the first 0 and 1. 
        //This way, we can also access the pointer array intPtrArray starting from 0 and not go outside of it's bounds. 
        //The case that would go outside of bounds is if we did not put a intN-2. This would mean that we are trying to also
        //input two more values outside of the range of what intPtrArray is allocated to. 
        for (int i = 0; i <= intN-2; i++) {
            intPtrArray[i] = fnIntFibonacci(i+2); //stores result of function into the pointer array 
        }

        for (int i = 0; i <= intN-2; i++) {
            std::cout << intPtrArray[i] << " "; //prints out fibonacci numbers
        }
        std::cout << std::endl << std::endl;

        //======================Brainstorming======================
        //Make somethign to compare the first element with the second element, then third, all the way until we get to the end. 
        //Then compare the second element, with the second element, then with the third element, all the way to the end. 
        //Maybe a nested loop would work? Also, if value is true then we want to print out the pair. 
        //Is true if modulo of the 2 are 0. 
        //======================Brainstorming======================

        for (int i = 0; i <= intN - 2; i++) {
            for (int j = i; j <= intN - 2; j++) {
                if (intPtrArray[j] % intPtrArray[i] == 0) {
                    std::cout << "(" << intPtrArray[i] << "," << intPtrArray[j] << "), ";
                }
            }
        }
        std::cout << std::endl << std::endl;

        delete[] intPtrArray; //clears up memory space. We don't want memory leaks to happen....

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