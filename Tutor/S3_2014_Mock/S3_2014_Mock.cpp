#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

//WORKING NOW

int main(void)
{
	vector< vector<int> > vec;
	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		vector<int> cvec;
		for (int j = 0; j < c; j++)
		{
			int curr;
			cin >> curr;
			cvec.push_back(curr);
		}

		vec.push_back(cvec);

	}

	int n, ci;
	cin >> n;

	for (int k = 0; k < n; k++)
	{
		cin >> ci;
		ci -= 1;


		for (int u = 0; u < n; u++)
			for (int p = 1; p < r; p++)
				if (vec[p - 1][ci]>vec[p][ci])
					swap(vec[p - 1], vec[p]);


	}

	for (vector<int> v : vec)
	{
		for (int x : v)
			cout << x << ' ';
		cout << endl;
	}



	system("pause");
}