/*
Program name : MouaJustin_DiscreteMath_PA5SN2.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 3 December 2023
Description  : Write a program whether the following graph 
               is Bipartite or not. (Based on CH-10).

               Image can be founded in .PDF provided by Professor Jain. 
               I've already made a matrice below though so I don't really need
               to look back at it. 
*/

#include <iostream>
#include <cmath>
int main()
{
    int intN; //Size of array
    bool boolStayOrQuit = true;
    std::cout << "\n==============================================================\n\nAssignment: PA5 SN2\nAuthor of Program: Justin moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n\n==============================================================\n\n";
    std::cout << std::endl << std::endl;



    while (true) {

        //==================SELF NOTE, RELEARNING ABOUT MULTIDIMENSIONAL/2D ARRAYS=============
        //Other people call this a multi dimensional array. However, in the C++ textbook by Stephen Prata, 
        //These are known as 2Dimensional arrays. Page 244 discusses
        // 
        // Say we have something like int maxtemps[4][5]. Well, we 
        // would have a 2D array that has a total of 4 elements in which EACH of those 4 elements
        // contain an array of length 5. maxtemps[0][0] would be the start of the first array in the first elmeent. 
        // maxtemps[1][0] would be the start of the second array in the second element, and so on.
        //==================SELF NOTE, RELEARNING ABOUT MULTIDIMENSIONAL/2D ARRAYS=============

        int intArrGraphMatrix[7][7] = 
        {              { 0, 0, 1, 0, 1, 1, 1 }, //row a
                       { 0, 0, 1, 0, 1, 1, 0 }, //row b
                       { 1, 1, 0, 1, 0, 0, 0 }, //row c
                       { 0, 0, 1, 0, 1, 1, 1 }, //row d
                       { 1, 1, 0, 1, 0, 0, 0 }, //row e
                       { 1, 1, 0, 1, 0, 0, 0 }, //row f
                       { 1, 0, 0, 1, 0, 0, 0 }, //row g

        };
        
        bool boolTorF = true;

        //I noticed that there is a pattern in the matrix. (a, a) is 0, (a, b) is 0 and (b, a) is 0. (a, c) and (c, a) is 0. 
        //Given this pattern, I made the algorithm below to check for that. As long as they equal each other then
        //This is going to always be bipartite BUT ONLY for a matrix that has a size that can be taken the square root of. 
        //In this case, we have a 7x7 matrix resulting in 49 which can be taken the square root of. Otherwise, a different algorithm
        //Would need to be created. 
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (intArrGraphMatrix[j][i] != intArrGraphMatrix[i][j]) {
                    boolTorF = false;
                }
            }
        }

        //===========================FAILED ATTEMPT AT CREATING ALGORITHM================================
        //for (int i = 0; i < 7; i++) {
        //    for (int j = 0; j < 7; j++) {
        //        if ((intArrGraphMatrix[j][i] != intArrColor[j]) && (j == 0)) {
        //            boolTorF = false;
        //        }
        //        else if ((intArrGraphMatrix[j][i] != intArrColor[j]) && (j >= 1)) {
        //            boolTorF = false;
        //            break;
        //        }
        //    }
        //}
        //===========================FAILED ATTEMPT AT CREATING ALGORITHM================================

        if (boolTorF == true) {
            std::cout << "==================\nThis is bipartite.\n==================\n\n===========\nExplanation\n===========\n\nGiven that the Matrix is 7x7 or NxN, I was able to create an algorithm to check for the matrix at (i, j) and (j, i) both starting at 0 and increasing by one to seven. Were this to not be a NxN matrix, the algorithm I created would not work anymore and need to be adjusted.";
        }
        else {
            std::cout << "=====================\nThis is not bipartite\n=====================";
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