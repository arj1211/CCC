#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define debug(x) cout << (x) << endl;
#define debug2(x,y) cout << (x) << " " << (y) << endl;
#define debug3(x,y,z) cout << (x) << " " << (y) << " " << (z) <<  endl;
#define debug4(x,y,z,q) cout << (x) << " " << (y) << " " << (z) << " " << (q) <<  endl;
#define fast_input ios::sync_with_stdio(0);cin.tie(0)
#define pause system("pause")
#define pb push_back


//WORKS

vector<int> houses;
int max_hoses;

int getHoses(int diam) //gets the minimum number of hoses required, given a diameter
{
	int numHoses = 1; //we will atleast need 1 hose, since there will be atleast 1 house
	int last = houses[0]; // we are using a "window-paning/sliding-window" technique, so we must keep 
	//track of the two ends of the 'window'. The first/left end (when you make the circle 
	//street into a straight line) is houses[0], the first house. 'last' just means its the previous edge of the 'window'.

	// current hose covers interval [last, last+diam]
	for (int i = 1; i < houses.size(); i++)//for all houses on the street...
		if (houses[i] - last > diam) //if the distance between the 'last' house and 'current' 
			//house (house that this loop is currently on) is more than the given diameter, 
			//increase the number of hoses needed and re-assign the 'last' house to this 'current' one. 
		{
			numHoses++;
			last = houses[i];
		}

	//cout << "diam, #hoses: "; debug2(diam, numhoses);
	return numHoses;
}

/*
h=50
getHoses(0), getHoses(1), getHoses(2), ...
50, 50, 50 ,50, ,50, 49, 49 , 49 49 47 47
46 46 45 45 45 41 41 ... 2 2 2 2 1 1 1 1
iters = 1000000/j  +  j 
*/

int solve()
{
	//SQRT SEARCH METHOD:
	//debug("sqrt search start:");
	//int d;
	//for (d = 0; d < 1000000; d += 1000)
	//{
	//	if (getHoses(d + 1000) <= max_hoses)
	//		break;
	//}
	//for (; d < 1000000; d++)
	//{
	//	if (getHoses(d) <= max_hoses)
	//	{
	//		//cout << "d: "; debug(d);
	//		break;
	//	}

	//}
	//return (d + 1) / 2;

	//
	//debug("sqrt search end.");
	//debug("bin search start:");
	//

	// Binary Search FIXED
	int diam, lo = 0, hi = 1000000 / max_hoses;//diam is used like the 'middle' value in generic Binary Search. 
												//'hi' isn't always 1,000,000 because it doesn't have to be that 
												//high when theres more than 1 hose allowed. The higher the number 
												//of hoses allowed, the lower the diameter of a hose needs to be.
	while (lo < hi)
	{
		diam = ((lo + hi) / 2);
		if (getHoses(diam)>max_hoses) //if diam isn't large enough...
			lo = diam + 1; //increase the lower-bound for the diameter
		if (getHoses(diam) <= max_hoses) //if diam is too large/just large enough (at which point lowering it is an attempt to optimize)
			hi = diam - 1; //reduce the higher-bound for the diameter
	}

	//
	//debug("bin search end.");
	//cout << "sqrt search result:"; debug(d); //debug((d + 1) / 2);
	//cout << "bin search result:"; debug(diam);//debug(diam / 2);
	//
	//debug(lo / 2);

	return (lo+1) / 2;//return the radius (which is what the problem asks for). 
						//'lo+1' because of the second 'if' clause in the loop; 
						//when the condition is no longer met, the diameter is exactly
						//1-unit too short, so we add one before converting to radius and returning.

}

int main()
{
	int h;
	cin >> h;

	while (h--)
	{
		int house;
		cin >> house;
		houses.pb(house);
	}

	cin >> max_hoses;
	sort(begin(houses), end(houses));//sort to enable binary search

	debug(solve());

	pause;
	return 0;
}