#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//WORKING
bool solve(int n)
{
	set<int> sums, diffs;

	for (int i = 1; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			int j = n / i;
			sums.insert(j + i);
			diffs.insert(abs(j - i));
		}
	}

	vector<int> intersect;
	set_intersection(sums.begin(), sums.end(), diffs.begin(), diffs.end(), back_inserter(intersect));

	//cout << intersect.size() << endl;
	return (intersect.size() > 0);
}



int main(void)
{

	int cases;
	cin >> cases;

	while (cases--)
	{
		int n;
		cin >> n;
		if (solve(n))
			cout << n << " is nasty" << endl;
		else
			cout << n << " is not nasty" << endl;

	}


	system("pause");

}