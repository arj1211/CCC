#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
//WORKS (first try)
#define debug(x) cout << (x) << endl;
#define debug2(x,y) cout << (x) << " " << (y) << endl;
#define debug3(x,y,z) cout << (x) << " " << (y) << " " << (z) <<  endl;
#define debug4(x,y,z,q) cout << (x) << " " << (y) << " " << (z) << " " << (q) <<  endl;
#define fast_input ios::sync_with_stdio(0);cin.tie(0)
#define pause system("pause")
#define pbb push_back
#define printvec(vec) for(auto i:vec){ cout<<i<<" ";}cout<<endl;
#define printvec2(vec2) for(auto i:vec2)for(auto k: i){ cout<<k<<" ";}cout<<endl;
#define vI vector<int>
#define vVI vector<vector<int> >
#define pI pair<int,int>
#define p(x) pair<x,x>
#define vpI vector<pair<int,int> >


int totalMins, totalChores, choresComplete=0;

int main()
{

	cin >> totalMins >> totalChores;
	
	vI chores;

	while (totalChores--)
	{
		int thisChore;
		cin >> thisChore;
		chores.pbb(thisChore);
	}

	sort(begin(chores), end(chores));

	int countUp = chores[0];

	for (int y = 1; y < chores.size(); y++)
	{
		if (countUp > totalMins)
		{
			debug(choresComplete);
			return 0;
		}
		else
		{
			countUp += chores[y]; choresComplete++;
		}
	}
	debug(choresComplete);
	return 0;
}