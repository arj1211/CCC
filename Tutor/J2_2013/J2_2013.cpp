#include <iostream>
#include <string>
using namespace std;

// WORKS


int main(void)
{
	string acc = "IOSHZXN";
	string input;
	cin >> input;
	bool flag = true;

	for (int u = 0; u < input.length();++u)
	{
		char c = input[u];
		if (acc.find(c) == -1)
		{
			flag = false;
		}
	}
	if (flag)
		cout << "YES";
	else
		cout << "NO";


}