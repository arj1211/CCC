#include <iostream>

//WORKS
using namespace std;

/*
1987 mod 10 = 7,   div 10 = 198
198 / 10 = 19
19 / 10 = 1
1 / 10 = 0
*/

bool checkUnique(int year)
{
	int digit[10] = { 0 };//count of all digits

	while (year != 0)
	{
		int units = year % 10;//returns current 'ones place'
		digit[units]++;
		year /= 10;//actually gets rid of that digit in the current 'ones place', so we can consider the digit after that next time (current tens place), and so forth
	}

	for (int i = 0; i < 10; i++)
	{
		if (digit[i] >1)//if any digit occurs more than once, not unique
			return false;
	}
	return true;//else, unique

}


int main()
{

	int yearIn, yearOut;

	cin >> yearIn;


	int year = yearIn + 1;

	while (checkUnique(year) == false)
	{
		year++;
	}

	cout << year;


	return 0;
}
