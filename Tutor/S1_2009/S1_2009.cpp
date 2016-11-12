#include <iostream>
#include <set>
#include <math.h>
using namespace std;
int a, b, n;
int coolNums;

// WORKS NOW

//bool cubes[100000000];
set<int> cubes;

bool checkSquare(int k)//true if k is perf sqr
{
	double root = sqrt(k);
	int int_root = int(root);
	return (int_root*int_root) == k;
}

int solve(int a, int b)
{
	int cnt = 0;
	while (a <= b)
	{
		if (cubes.count(a))//if 'a' exists...
		{
			
			if (checkSquare(a))//and its a perf sqr...
			{
				//cout << a << ' ' << cnt << endl;
				cnt++;
			}
		}

		a++;
	}

	return cnt;
}

int main(void)
{
	int k = 1;


	

	cin >> a;
	cin >> b;

	while (k*k*k <= b)//while k^3 is within the range
	{
		//cubes[k*k*k] = true;
		cubes.insert(k*k*k);//put k^3 into set (so that number we KNOW is a perf cube, we just need to check if its a perfSqr too)
		k++;
	}
	
	/*
	cout << cubes.size() << endl;

	coolNums = 0;

	for (int i = 1; i < 22; i++)
	{
		int j = pow(i, 6);

		if (j <= b && j >= a)
			coolNums++;

	}


	cout << coolNums << endl;
	*/
	

	cout << solve(a, b) << endl;

	system("PAUSE");
	return 0;
}