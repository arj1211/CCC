#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
//WORKING
#define debug(x) cout << (x) << endl;
#define debug2(x,y) cout << (x) << " " << (y) << endl;
#define debug3(x,y,z) cout << (x) << " " << (y) << " " << (z) <<  endl;
#define debug4(x,y,z,q) cout << (x) << " " << (y) << " " << (z) << " " << (q) <<  endl;
#define fast_input ios::sync_with_stdio(0);cin.tie(0)
#define pause system("pause")
#define pbb push_back
#define printvec(vec) for(auto i:vec){ cout<<i<<" ";}cout<<endl;
#define printvec2(vec2) for(auto i:vec2)for(auto k: i){ cout<<k<<" ";}cout<<endl;


int a, b; // size of list 1 and 2
vector<int> veca, vecb; //the lists

int main()
{
	//take in size of first list, then the list itself into veca
	cin >> a;

	while (a--)
	{
		int tmp;
		cin >> tmp;
		veca.pbb(tmp);
	}

	//take in size of second list, then the list itself into vecb
	cin >> b;

	while (b--)
	{
		int tmp;
		cin >> tmp;
		vecb.pbb(tmp);
	}

	/*

	Rough idea:
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	|for every x in A[]					|
	|	target=10000-x					|
	|	does `target exist in B[] ?		|
	|		for every y in B[]			|
	|			if x+y==10000:			|
	|				RETURN 'YES'		|
	|									|
	|return 'no'						|
	|									|
	|									|
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	More efficient:

	for every element (i) in first list:
		'target' is the complementary value to element (i) in the first list; the value we're looking for in second list
		'mini', an index initialized to 0; 'maxi', an index initialized to the last index in second list (size - 1)
		while we haven't zeroed in on the target we're looking for in the second list:
			'guess', according to standard binary search
			if we found our target: print out 'YES' and exit the program
			else if vecb at element 'guess'	is too high or too low, then change it according to standard binary search techniques
	if we've gotten to this point, its not possible to get a sum of 10k from any two elements in the two lists; print out "NO".

	*/
	for (int x = 0; x < veca.size(); x++)
	{
		int mini = 0, maxi = vecb.size() - 1, target = 10000 - veca[x];

		while (mini <= maxi)
		{
			int guess = (mini + maxi) / 2;

			if (vecb[guess] == target)
			{
				debug("YES");
				//debug2(veca[x], target);
				//pause;
				return 0;
			}

			if (vecb[guess] < target)
				maxi = guess - 1;
			else
				mini = guess + 1;
		}
	}

	debug("NO");
	pause;
	return 0;
}