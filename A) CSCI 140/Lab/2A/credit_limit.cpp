// who: <Austin Ngo ; ango26>
// what: <Credit limit of a department store>
// why: <2a - section 2>
// when: <03/13/2022>

// includes go here
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
	int actnum{0};
    float sbal{0};
    float charge{0};
    float crtotal{0};
    float crlimit{0};
    float nbal{0};
    
    do
    {
        cout << "Enter account number (-1 to end): \n";
        cin >> actnum;

        if(actnum < 0) break;
      
        cout << "Enter beginning balance: ";
        cin >> sbal; 
        cout << "Enter total charges: ";
        cin >> charge;
        cout << "Enter total credits: ";
        cin >> crtotal;
        cout << "Enter credit limit: ";
        cin >> crlimit;

        nbal = sbal + (charge - crtotal);

        cout << std::setprecision(2) << std::fixed;

        cout << "New balance is " << nbal << endl;
        cout << "Account:       " << actnum << endl;
        cout << "Credit limit: " << crlimit << endl;
        cout << "Balance:       " << nbal << endl;

        if (nbal > crlimit)
        {
            cout << "Credit limit exceeded.\n";
        }

    } while (actnum != -1);
    
	return 0;
}