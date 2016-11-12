#include <iostream>
#include <vector>
#include <string>

using namespace std;

// WORKS

int main(void)
{

	int numOfLines, eng = 0, fr = 0;

	vector<char> array;

	cin >> numOfLines;

	//read in lines
	for (int i = 0; i <= numOfLines; ++i)
	{
		string s;
		getline(cin, s);
		for (char c : s)
			array.push_back(c);
	}

	for (int k = 0; k < array.size(); ++k)
	{
		char c = array[k];

		if (c == 'T' || c == 't')
		{
			++eng;
		}
		else if (c == 'S' || c == 's')
		{
			++fr;
		}
		else continue;


	}

	if (eng > fr)
	{
		cout << "English";
	}
	else
	{
		cout << "French";
	}

	system("pause");

}