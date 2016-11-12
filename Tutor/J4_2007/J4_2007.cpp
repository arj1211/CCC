//	CONFIRMED WORKS: 70/70 PEG




#include <iostream>
#include <string>
# include <vector>
using namespace std;


bool anagram(string a, string b)
{
	//arrays to hold # of times each letter in a string occurs, init to 0
	//int freq_A[26] = { 0 };
	//int freq_B[26] = { 0 };
	vector <int> freq_A(256, 0);
	vector <int> freq_B(256, 0);

	/*
	fills up the first char array;
	adding 1 for each occurance of a letter to
	that letter count, stored in the index of
	the array associated with that
	letter. ( 'a'==0, 'z'==25; indicies)
	*/
	for (int count = 0; count < a.size(); ++count)
	{
		freq_A[a[count]]++;
	}

	//same with the second char array...

	for (int count = 0; count < b.size(); ++count)
	{
		freq_B[b[count] ]++;
	}


	/*
	now, for each letter in the english alphabet,
	see if the number of occurances of each
	letter in either string is the same.
	if even 1 letter count is not the same, return false and stop.
	*/

	for (int count = 'A'; count <= 'Z'; count++)
	{
		if (freq_A[count] != freq_B[count])
			return false;
	}

	return true;

}


int main(void)
{

	string line1, line2;
	//char line1arr[100], line2arr[100];

	vector <char> ca;
	vector <char> db;

	getline(cin, line1);
	getline(cin, line2);

	//line1.replace(' ', '');

	/*
	for (int u = 0; u < line1.length(); u++)
	{
		if (line1[u] != ' ')
			ca.push_back(line1[u]);
	}
	for (int u = 0; u < line2.length(); u++)
	{
		if (line2[u] != ' ')
			db.push_back(line2[u]);
	}
	*/

	if (anagram(line1, line2))
	{
		cout << "Is an anagram." << endl;
	}
	else
	{
		cout << "Is not an anagram." << endl;
	}

	system("pause");


}