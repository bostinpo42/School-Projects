// who: <Austin Ngo - ango26>
// what: <Calculates the gross pay for several employees>
// why: <2A - gross_pay.cpp>
// when: <03/13/2022>

// includes go here
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char const *argv[])
{
	int hours {0};
    float pay{0};
    float salary{0};

    do
    {
        cout << "Please enter the amount of hours worked (-1 to end): ";
        cin >> hours;

        if (hours < 0) break;

        cout << "Please enter the hourly rate of the employee ($00.00): ";
        cin >> pay;

        if (hours > 40)
            salary = (40 * pay) + ((hours % 40) * pay * 1.5) ;
        else 
            salary = hours * pay;

        cout << std::setprecision(2) << std::fixed;
        cout << "Salary is $" << salary << endl;
    } while (hours != -1);
    
	
	return 0;
}