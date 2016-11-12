#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
* WORKING !!!
*/

map< int, int > allowed;

bool isRotateable(int i)
{
	// break up the digis into array
	vector<int> digits;

	while (i != 0)
	{
		digits.push_back(i % 10);
		i /= 10;
	}

	int size = digits.size();
	bool rotatable = true;
	// if the ends of the number are 0, 1, 8, or if there are 6-9, 9-6 pairs

	int left = 0; int right = size - 1;

	while (left <= right)
	{
		int a = digits[left];
		int b = digits[right];
		if (allowed.count(a) == 0 || allowed.count(b)==0)
		{
			rotatable = false;
			break;
		}
		if ( allowed[a]!=b )
		{
			rotatable = false;
			break;
		}

		left++; right--;
	}

	/*
	for (int curr = 0; curr < size; ++curr)
	{
		int otherEnd = size - (curr + 1);

		if (digits[curr] == 0 && digits[otherEnd] == 0);

		else if (digits[curr] == 1 && digits[otherEnd] == 1);

		else if (digits[curr] == 8 && digits[otherEnd] == 8);

		else if (digits[curr] == 6 && digits[otherEnd] == 9);

		else if (digits[curr] == 9 && digits[otherEnd] == 6);

		else
		{
			rotatable = false; break;
		}
	}
	*/

	return rotatable;

}

int main(void)
{
	int in1, in2, count = 0;

	cin >> in1;
	cin >> in2;

	bool result;

	//0, 1, 8, or if there are 6 - 9, 9 - 6 pairs
	allowed[0] = 0;
	allowed[1] = 1;
	allowed[8] = 8;
	allowed[6] = 9;
	allowed[9] = 6;

	for (in1; in1 <= in2; ++in1)
		if (isRotateable(in1))
		{
			//cout << in1 << endl;
			++count;
		}

	cout << count << endl;;

	system("pause");
}
