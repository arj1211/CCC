#include <iostream>
#include <map>
using namespace std;

// WORKING
// **made it very simple, now it works, go figure**

int main(void)
{
	int w, n, count = 0, weight4 = 0, carsOn = 0;

	map<int, int> cars;

	cin >> w;
	cin >> n;

	for (int u = 1; u <= n; u++)
		cin >> cars[u];

	for (int carNum = 1; carNum <= n; ++carNum)
	{
		if (carNum > 4)
			weight4 -= cars[carNum - 4];

		weight4 += cars[carNum];

		if (weight4 > w)
			break;
		else count++;


	}

	cout << count;

}