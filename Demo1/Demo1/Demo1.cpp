#include <iostream>
#include <string>
using namespace std;

int main()
{
	for (long i = 2; i < pow(2, 30); i += (2 * i--))
	{
		cout << i << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}