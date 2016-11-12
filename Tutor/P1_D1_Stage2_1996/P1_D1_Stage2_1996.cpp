#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define pb push_back


//WORKING (on first try/submit )

int main(void)
{

	int testcases;
	cin >> testcases;

	while (testcases > 0)
	{
		int l;
		cin >> l;
		vector<int> vec;
		for (int i = 0; i < l; i++)
		{
			int currentCarriage;
			cin >> currentCarriage;
			vec.pb(currentCarriage);
		}

		int trainSwaps = 0;

		vector<int> presorted = vec;
		sort(presorted.begin(), presorted.end());

		while (vec != presorted)
		{
			for (int count = 1; count < vec.size(); count++)
			{
				if (vec[count - 1] > vec[count])
				{
					swap(vec[count - 1], vec[count]);
					trainSwaps++;
				}
			}
		}

		cout << "Optimal train swapping takes " << trainSwaps << " swap(s)." << endl;

		testcases--;

	}
}