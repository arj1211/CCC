#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

//WORKING

int main(void)
{

	int n;
	cin >> n;
	bool identical = false;

	set< vector<int> > vec;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		vector<int> tmpvec = { a, b, c, d, e, f };

		sort(tmpvec.begin(), tmpvec.end());

		if (vec.count(tmpvec) == 1)
		{
			identical = 1; break;
		}

		vec.insert(tmpvec);
		//vec.push_back(tmpvec);
	}

	if (identical)
		cout << "Twin snowflakes found.";
	else
		cout << "No two snowflakes are alike.";

}



/*
int main(void)
{

	int n;
	cin >> n;

	vector< vector<int> > vec;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d, e, f;
		cin >> a >> b >> c >> d >> e >> f;
		vector<int> tmpvec = { a, b, c, d, e, f };

		sort(tmpvec.begin(), tmpvec.end());


		vec.push_back(tmpvec);

	}




	bool identical = false;

	sort(vec.begin(), vec.end());


	for (int j = 0; j < vec.size() - 1; j++)
		if (vec[j] == vec[j + 1])
			identical = true;





	if (identical)
		cout << "Twin snowflakes found.";
	else
		cout << "No two snowflakes are alike.";









}
*/