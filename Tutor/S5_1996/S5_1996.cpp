#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//WORKS NOW (using binary search)

#define debug(x) cout << (x) << endl;
#define debug2(x,y) cout << (x) << " " << (y) << endl;
#define debug3(x,y,z) cout << (x) << " " << (y) << " " << (z) <<  endl;
#define debug4(x,y,z,q) cout << (x) << " " << (y) << " " << (z) << " " << (q) <<  endl;
#define fast_input ios::sync_with_stdio(0);cin.tie(0)
#define pause system("pause")
#define pb push_back

int n, temp, cases;

int main(void)
{
	int cases;
	cin >> cases; //read num of cases

	while (cases--) //for each case...
	{
		int seq_size;
		cin >> seq_size; //read in the size of the 2 following sequences

		vector<int> x, y;

		//fill in those two sequences...
		for (int r = 0; r < seq_size; r++)
		{
			int curr;
			cin >> curr;
			x.pb(curr);
		}
		for (int r = 0; r < seq_size; r++)
		{
			int curr;
			cin >> curr;
			y.pb(curr);
		}




		//this is where the searching starts
		int optimal = 0; // 'optimal' is the "max distance" possible. Initially set to 0, so that we can output 0 if there is no max distance (as per the problem requirement)

		for (int i = 0; i < seq_size; i++) //for each number in the first sequence...
		{
			//for each number in the first sequence...
			//binary search for furthest number in second sequence

			int low = i, hi = seq_size - 1, mid; // define 'low' as the index of the current number in the first sequence; 'hi' as the index of the last element in either sequence; 'mid' as the variable we use to binary search. 'low' and 'hi' will be changed depending on iterations in our binary search
		//cout << "i: "; debug(i);
			while (low < hi) //while we haven't centered in on the exact index in the second sequence that we're looking for...
			{
				//cout << "low, hi: "; debug2(low, hi);
				mid = (low + hi) / 2; //'mid' is the midpoint between 'low' and 'hi'
				//cout << "mid: "; debug(mid);
				if (y[mid] < x[i]) // if the number at index 'mid' in the second sequence is smaller than the current number from the first sequence, we know all numbers after this in the second sequence are smaller too, so we've gone too far. 
					hi = mid - 1; //adjust the higher bound ('hi') so that we go back towards the higher numbers in the second sequence, and don't look at these lower numbers again.
				else if (y[mid] >= x[i]) // if the number at index 'mid' in the second sequence is equal to or larger than the current number in the first sequence, we are on the right track, and we may not have the optimal number, so
					low = mid + 1; //we advance the lower bound ('low') one past the m'mid' index. if 'low' is now equal to or greater than 'hi', the loop breaks anyways.
			}

			if (low - i > optimal) optimal = low - i; //if the difference between the index 'low' and the index of the current number in the first sequence is better/greater than the optimal difference, re-assign the optimal difference.


		}
		//cout << "optimal: "; debug(optimal);
		cout << "The maximum distance is " << optimal << endl;
	}pause;
}
