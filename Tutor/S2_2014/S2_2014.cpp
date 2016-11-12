#include <iostream>
#include <string>
#include <map>
using namespace std;

// WORKING (full marks on the first try)


int main(void)
{

	int n;

	map< int, pair<string, string> > nameMapPair; //pair#, pairNames

	cin >> n;

	for (int num = 0; num < n; num++)
		cin >> nameMapPair[num].first;

	for (int num = 0; num < n; num++)
		cin >> nameMapPair[num].second;


	bool g_b = true; // good/bad

	for (int num = 0; num < n; num++)
	{
		if (nameMapPair[num].first == nameMapPair[num].second) //if someone is pair with themself
		{
			cout << "bad"; g_b = false; break;
		}


		bool found = false;
		int u = 0; //index of where 'num's first name is in the second line
		while (!found)
		{
			if (nameMapPair[num].first == nameMapPair[u].second)
			{
				found = true; break;
			}
			u++;
		}

		if (nameMapPair[u].first != nameMapPair[num].second)
		{
			cout << "bad"; g_b = false; break;
		}


	}

	if (g_b)
		cout << "good";





}