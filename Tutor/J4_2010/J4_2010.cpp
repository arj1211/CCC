#include <iostream>
#include <map>
#include <vector>
using namespace std;

// WORKING

/*vvvvvv examples of pre-processor macros  vvvvvvvvvv

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define sz(a) int((a).size())
#define pb push_back

vi myVect(100, -1);

#define DEBUG 0

#define debug(x) if ( DEBUG ){ cout << (x) << endl; }
#define debug2(x,y) cout << (x) << " " << (y) << endl;

#define mult2( z ) 2*z

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/

bool checkCycle(vector<int> diffVec, int cylength) // checks if 'cylength' is length of the cycles
{

	for (int i = 0; i + 1 < diffVec.size(); i++) // for all elems in diffVec...
	{
		//diffVec[i] is current elem
		int difference = diffVec[i + 1] - diffVec[i]; //the difference between next elem and current one
		int initIndex = i % cylength; // the index of the last elem whose difference with it's next elem (ex. diffvec[3+1] and diffVec[3], diffVec[3] being the subject elem) is the same as the difference between the two current elems
		/*
			i=3, cyl=2.

			i%cyl=1

			diffVec[1+1]-diffVec[1] MUST EQUAL diffVec[3+1]-diffVec[3]

		*/
		int initDiff = diffVec[initIndex + 1] - diffVec[initIndex]; // the difference of the last time the current difference should've occurred. (ex. diffVec[6] is current elem, cylength is 3.   diffVec[7]-diffVec[6] should be the same as diffVec[4]-diffVec[3])

		if (difference != initDiff) return false; // if the cycle isnt consistent, false
	}
	return true;
}

int main(void)
{
	int n;
	while (cin >> n && n != 0)
	{
		vector< int > diffVec;
		//take in the readings on that line
		for (int tests = 0; tests < n; tests++)
		{
			int temp;
			cin >> temp;
			diffVec.push_back(temp);
		}
		int len = 0;
		if (diffVec.size() > 1)
			for (len = 1; len <= n; len++)
				if (checkCycle(diffVec, len)) break;

		cout << len << endl;
	}
}