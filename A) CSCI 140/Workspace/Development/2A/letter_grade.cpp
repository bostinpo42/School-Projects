/*
	This is the standard template for CSCI 140 Lab.
	Unless otherwise directed, start your programs with this template file. 
	Be sure to rename the file appropriately when used for a lab.
	Also you can/should remove this comment before use. Leave the following comments.
*/

// who: <your name and Mt SAC username goes here>
// what: <the function of this program>
// why: <the name of the lab>
// when: < the due date of this lab.

// includes go here
#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[])
{
	int score{0};
    int sum{0};
    int count{0};
	
    do
    {
        std::cout << "Please enter a score between 0 and 105 (-1 to quit): ";
        std:: cin >> score;

        if(score > 105)
        {
            std::cout << "Score must be less than 105!\n";
            continue;
        }

        if(score < 0) break;

        sum += score;
        ++count;

        if(score > 100)
            std::cout << "A+\n";
        else if(score >= 90)
            std::cout << "A\n";
        else if(score >= 80)
            std::cout << "B\n";
        else if(score >= 70)
            std::cout << "C\n";
        else if(score >= 60)
            std::cout << "D\n";
        else
            std::cout << "F\n";
        
        
    } while (true);
    
    std::cout << std::setprecision(2) << std::fixed; // setprecision to set the number of decimal places, fixed to ensure the output is not in scientific notation
    std::cout << count << " scores were entered for an average score of: " 
              << static_cast<double>(sum) / count << std::endl; // static_cast<double>(sum) converts the int sum into a type double.
	return 0;
}