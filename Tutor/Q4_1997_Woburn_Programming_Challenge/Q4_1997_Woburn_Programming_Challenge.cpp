# include <stdio.h>
using namespace std;
# include <iostream>
# include <string>
# include <algorithm>

// WORKING

string abc = "abcdefghijklmnopqrstuvwxyz";

int main(void)
{

	//**
	string cases;
	getline(cin, cases);
	int caseme = stoi(cases); //c++11, stoi converts str to int
	/*
	OR

	int caseme;
	cin >> caseme;
	cin.ignore()   <-- clears the "\n" cin leaves behind in the stream;

	*/
	for (int i = 0; i < caseme; i++)
	{
		string line;

		getline(cin, line);

		sort(line.begin(), line.end());

		if (line == abc) cout << "OK.\n";
		else cout << "Nope.\n";
	}
}
