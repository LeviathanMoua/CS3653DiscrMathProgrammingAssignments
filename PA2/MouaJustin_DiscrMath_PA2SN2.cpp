/*
Program name : MouaJustin_DiscrMath_PrgmPA2SN2.cpp
Author       : Justin Moua
Professor    : Sachin Jain
Course       : CS 3653 | Discrete Mathematics for Computer Science
Date         : 14 October 2023
Description  : Write a program to display the following in the list of integers of n elements. 
               (The value of n should be > 10 & taken by the user through the keyboard).
                   1. Even numbers
                   2. Odd numbers
                   3. Prime numbers
                   4. Second Largest
                   5. Second Smallest 
*/

#include <iostream>
#include <vector>
#include <algorithm>

void fnPrintVec(std::vector<int> vec)
{
    //Must be numerically sorted before being put into the array. Otherwise, erasing duplicates won't work. Bubble sort already does this for us. 
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    if (vec.size() == 1) {
        std::cout << vec[0];
    }
    else {
        for (int i = 0; i < vec.size(); i++)
            if (i != vec.size() - 1) {
                std::cout << vec[i] << ", ";
            }
            else {
                std::cout << "& " << vec[i] << ".";
            }
    }
    std::cout << std::endl << std::endl;
}

void fnBubbleSort(std::vector<int> vec) {
    int i, j;
    bool swapped;
    for (i = 0; i < vec.size() - 1; i++) {
        swapped = false;
        for (j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
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


void fnPrintEven(std::vector<int> vec) {
    std::vector<int> vecTemp;
    if (vec.size() == 1) {
        std::cout << vec[0];
    }
    else {
        for (int i = 0; i < vec.size(); i++)
            if (vec[i] % 2 == 0) {
                if (i != vec.size() - 1) {
                    vecTemp.push_back(vec[i]);
                }
            }
    }
    if (vecTemp.size() == 0) {
        std::cout << "None. No values valid for finding even numbers.";
        std::cout << std::endl << std::endl;
    }
    else {
        fnBubbleSort(vecTemp);
    }
}

void fnPrintOdd(std::vector<int> vec) {
    std::vector<int> vecTemp;
    if (vec.size() == 1) {
        std::cout << vec[0];
    }
    else {
        for (int i = 0; i < vec.size(); i++)
            if (vec[i] % 2 == 1) {
                if (i != vec.size() - 1) {
                    vecTemp.push_back(vec[i]);
                }
            }
    }
    if (vecTemp.size() == 0) {
        std::cout << "None. No values valid for finding odd numbers.";
        std::cout << std::endl << std::endl;
    }
    else {
        fnBubbleSort(vecTemp);
    }
}

void fnPrintPrime(std::vector<int> vec) {
    
    std::vector<int> vecTemp;
    //Loops through the entire array
    for (int i = 0; i < vec.size(); i++) {
        /*loops up until the value of vec[i].For e.g., if vec[0] = 17, loop up until 17.
        This is because we want to divide every number from j = 1 to i = 17 (or i = vec[i])
        And check whether if the number divides more than two times. If not, then it is a prime.*/
        int intCounter = 0;
        for (int j = 1; j <= vec[i]; j++) {
            /*Say vec[i] = vec[0] = 17. Now say j = 1. Check if 17%1 = 0.
            Then, vec[i] = vec[0] = 17 and j = 2. Check if 17%2 = 0 up until vec[i] or 17.*/
            if (vec[i] % j == 0) {
                intCounter++;
            }
        }
        if (intCounter <= 2) {
            vecTemp.push_back(vec[i]);
        }
    }
    if (vecTemp.size() == 0) {
        std::cout << "None. No values valid for finding prime numbers.";
        std::cout << std::endl << std::endl;
    }
    else {
        fnBubbleSort(vecTemp);
    }

    /*
    Brainstorming: Pseudocode for prime number and brainstorming:
    note tha tprime numbers can only be divided 2 times. By 1, and by itself.
    The number would not be able to be divided by anything higher than itself.
    Thus, we can just make a loop that goes up until that given value. Then try to divide each number.
    But what about negative numbers? Well, we can just start at 0 since the numberes from 0 up to
    that value will be "the same" as those negative ones.
    */
}

void fnPrintSecondLargest(std::vector<int> vec)
{
    //Bubble Sort. Sorts the list so we can find second largest. 
    bool swapped;
    for (int i = 0; i < vec.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
    
    //Must be numerically sorted before being put into the array. Otherwise, erasing duplicates won't work. Bubble sort already does this for us. 
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    //If the size of the list is 1, then output that value since that is the only largest value. 
    if (vec.size() == 1) {
        std::cout << vec[0];
    }
    //If there are more than 1 elements in a list, print the second to last to output the second largestinteger.
    //Note that we already bubblesorted before passing vector through this function.
    else if (vec.size() > 1) {
        std::cout << vec[vec.size()-2];
    }
    //If size of list happens to be 0. This shouldn't happen though since we already made it a condition to enter more than 11 values. 
    else {
        std::cout << "None. There were no elements inputted";
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void fnPrintSecondSmallest(std::vector<int> vec)
{
    //Bubble Sort. Sorts the list so we can find second smallest. 
    bool swapped;
    for (int i = 0; i < vec.size() - 1; i++) {
        swapped = false;
        for (int j = 0; j < vec.size() - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
    //Must be numerically sorted before being put into the array. Otherwise, erasing duplicates won't work. Bubble sort already does this for us. 
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    //If the size of the list is 1, then output that value since that is the only smallest value.
    if (vec.size() == 1) {
        std::cout << vec[0];
    }
    //If there are more than 1 elements in a list, print the second element to output the second smallest integer.
    //Note that we already bubblesorted before passing vector through this function.
    else if (vec.size() > 1) {
        std::cout << vec[1];
    }
    //If size of list happens to be 0. This shouldn't happen though since we already made it a condition to enter more than 11 values. 
    else{
        std::cout << "None. There were no elements inputted";
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    //Initialization
    
    std::vector <int> vecUsrList;

    std::cout << "==============================================================\nAssignment: PA2 SN2\nAuthor: Justin Moua\nProfessor: Sachin Jain\nCourse: CS 3653 | Discrete Mathematics for Computer Science\n==============================================================";
    std::cout << std::endl << std::endl;


    int intSizeOfList;
    //While loop to check whether or not user entered a number for the size of the list that is greater than 10. 
    while (true) {
        std::cout << "How many integers do you want in your list? It must be greater than 10. Enter here: ";
        std::cin >> intSizeOfList;
        std::cout << std::endl; 

        //If the user entered a number <= 10. 
        if (intSizeOfList <= 10) {
            std::cout << "=============\nInvalid Input!\n=============\n\nThe number must be greater than 10. Please try again.";
            std::cout << std::endl;
        }
        else {
            break;
        }
    }

    //For loop to enter data into usrList. 
    for (int i = 0; i < intSizeOfList; i++) {
        //The value the user inputs to be stored into their list. 
        int usrValueInp;
        std::cout << "Enter the value you would like to enter into element [" << i << "] of your list. Enter here: ";
        std::cin >> usrValueInp;
        vecUsrList.push_back(usrValueInp);
    }
    std::cout << std::endl; 

    //This is used to break from the main loop.
    bool boolStayOrQuit = true;
    while (true) {

        int intInpUsrOp;

        std::cout << "================\nChoose Operation\n================\n\nNote: These are the values in your list (excluding duplicates)";
        fnPrintVec(vecUsrList);
        std::cout << "\n1. Find Even Numbers\n2. Find Odd Numbers\n3. Find Prime Numbers\n4. Find Second Largest Number\n5. Find Second Smallest Number\n6. Quit the program\n\nEnter a number from 1 to 6 here: ";
        std::cin >> intInpUsrOp;
        std::cout << std::endl;

        //Find Even Numbers
        if (intInpUsrOp == 1) {
            std::cout << "============\nEven Numbers\n============\n\nThe even numbers of your list is: ";
            fnPrintEven(vecUsrList);
        }
        //Finds Odd Numbers
        else if (intInpUsrOp == 2) {
            std::cout << "===========\nOdd Numbers\n===========\n\nThe odd numbers of your list is: ";
            fnPrintOdd(vecUsrList);
        }
        //Finds Prime Numbers
        else if (intInpUsrOp == 3) {
            std::cout << "=============\nPrime Numbers\n=============\n\nThe prime numbers of your list is: ";
            fnPrintPrime(vecUsrList);
        }
        //Find second largest number.  | Uses bubble sort and prints second to last element. 
        else if (intInpUsrOp == 4) {
            std::cout << "==============\nSecond Largest\n==============\n\nThe second largest number of your list is: ";
            fnPrintSecondLargest(vecUsrList);
        }
        //Find second smallest element. | Uses bubble sort and prints second to first element. 
        else if (intInpUsrOp == 5) {
            std::cout << "===============\nSecond Smallest\n===============\n\nThe second smallest number of your list is: ";
            fnPrintSecondSmallest(vecUsrList);
        }
        else if (intInpUsrOp == 6) {
            break;
        }
        else {
            std::cout << "=============\nInvalid Input!\n=============\n\nThe input must be a number from 1 to 5. Please try again.";
            std::cout << std::endl;
        }

        //Var to check if user wants to continue
        std::string strUsrInpContinueOrNo;
        while (true) {

            std::cout << "===========================\nWould you like to continue?\n===========================\n\nEnter Y or N here: ";
            std::cin >> strUsrInpContinueOrNo;
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
                std::cout << "=============\nInvalid Input!\n=============\n\nThe input must be a number from 1 to 5. Please try again.";
                std::cout << std::endl;
            }

        }
        //If the user has selected to quit, boolStayOrQuit will be false and thus break the while loop. 
        if (boolStayOrQuit == false) {
            break;
        }
    }

    std::cout << "\n===================\nClick enter to quit\n===================\n";
    std::cin.get();

}
