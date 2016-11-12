#include <iostream>
using namespace std;

// WORKS

int main(void)
{

	int x, y;
	cin >> x;
	cin >> y;

	for (int i = x; i <= y; i += 60)
	{
		cout << "All positions change in year " << i << endl;
	}
	system("pause");

}
