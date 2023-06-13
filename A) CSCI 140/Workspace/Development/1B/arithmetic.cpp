// who: <Austin Ngo>
// what: <Arithmetic of 3 Variables>
// why: <Lab_1b>
// when: <03/06/2022>

#include <iostream>

int main(int argc, char const* argv[])
{
	float num1{ 0 };
	float num2{ 0 };
	float num3{ 0 };
	float sum{ 0 };
	float avg{ 0 };
	float prod{ 0 };
	float sumsqr{ 0 };
	float sqrsum{ 0 };

	std::cout << "Please enter the first number: ";
	std::cin >> num1;

	std::cout << "Please enter the second number: ";
	std::cin >> num2;

	std::cout << "Please enter the third number: ";
	std::cin >> num3;

	std::cout << "Three input intergers: " << num1;
	std::cout << ", " << num2;
	std::cout << ", " << num3 << "\n";

	sum = num1 + num2 + num3;

	avg = (num1 + num2 + num3) / 3;

	prod = (num1 * num2 * num3);

	sumsqr = (num1 * num1) + (num2 * num2) + (num3 * num3);

	sqrsum = (num1 + num2 + num3) * (num1 + num2 + num3);

	float max{ 0 };
	if (num1 > num2)
	{
		max = num1;
	}
		else
		{
			max = num2;
		}
		if (num3 > max)
		{
			max = num3;
		}
	
	float min{ 0 };
	if (num1 < num2)
	{
		min = num1;
	}
		else
		{
			min = num2;
		}
		if (num3 < min)
		{
			min = num3;
		}

	std::cout << "Sum is: " << sum << "\n";
	std::cout << "Average is: " << avg << "\n";
	std::cout << "Product is: " << prod << "\n";
	std::cout << "Sum of their squares is: " << sumsqr << "\n";
	std::cout << "The square of their sums is: " << sqrsum << "\n";
	std::cout << "The maximum is: " << max << "\n";
	std::cout << "The minimum is: " << min << "\n";


	return 0;
}

