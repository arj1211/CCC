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
#define pbb push_back
#define printvec(vec) for(auto i:vec){ cout<<i<<" ";}cout<<endl;
#define printvec2(vec2) for(auto i:vec2)for(auto k: i){ cout<<k<<" ";}cout<<endl;

//WORKING


int N, in_L; //dynamically changing size of array 'N'; 'in_L' input # of comparisons


bool BinarySearch(int x)
{
	int p, q, i, L;

	p = 0;   /* Left border of the search  */
	q = N - 1; /* Right border of the search */
	L = 0;   /* Comparison counter         */
	while (p <= q)
	{
		i = (p + q) / 2;
		//debug2("i: ", i);
		++L; //increment number of comparisons
		if (i == x && L == in_L )
		{
			// if we found the target value 'x' AND in 
			// the right amount of comparisons...
			return true;
		}
		if (x < i) 
			q = i - 1;
		else
			p = i + 1;
	}
	return false;
}



int main()
{

	int x; 
	
	cin >> x >> in_L; //input the target 'x' and the number of comparisons we need to find it in
	vector<int> possibleN; //vector of possible 'N' values

	bool flag = false; //flag to see if we ever find our target at all (output 0 afterwards if we dont find)
	for (N = 1; N <= 10000; N++)
		if (BinarySearch(x)) //if we found target with this val of N...
		{
			//debug2("N: ",N);
			possibleN.pbb(N);//add this val of N to the list of possible 'N' vals
			flag = true;//we found target atleast once
		}



	if (!flag)// if we never found our target...
	{
		debug(0);
		return 0;
	}

	
	vector<pair<int, int> > vecpair;//vector to hold intervals of N-vals
	for (int t = 0; t < possibleN.size(); t) //t will manually be incremented, which is why it shouldn't be here
	{
		int expected = possibleN[t];// expected ending interval, initialized to the current value of N. We will be increasing this value until we find the upper bound of this interal
		
		int orig = t;//the original index 't', since we will be changing it
		while (t<possibleN.size() && expected == possibleN[t]) // while we are within the limits of the list of possible N vals, and the 'expected end' interval value is a valid possible N value of this current interval...
		{
			t++; //inc t
			expected++;//inc expected

		}//eventually, possibleN[t] will be more than 1 less than possibleN[t+1], and thats when the while loop will terminate, and we will have our interval start and end values
		
		vecpair.pbb({ possibleN[orig], expected - 1 });//add the start,end interval vals as a pair
		//debug2(possibleN[orig], expected - 1);
	}


	//output the # of intervals, and the intervals themselves
	debug(vecpair.size());
	for (pair<int, int> p : vecpair)
		debug2(p.first, p.second);

	/*
	vector<int> tmpvec;
	for (int y = 0; y < possibleN.size() - 1; y++)
	{

		if (possibleN[y] < possibleN[y + 1] - 1)
		{
			tmpvec.pbb(possibleN[y]);
			vec.pbb(tmpvec);
			tmpvec.clear();
			tmpvec.pbb(possibleN[y + 1]);
			y++;
		}

	}
	tmpvec.pbb(possibleN[possibleN.size() - 1]);
	vec.pbb(tmpvec);
	tmpvec.clear();

	//printvec(possibleN);

	debug(vec.size());
	for (vector<int> i : vec)
	{
		if (i.size() == 1)
		{
			debug2(i[0], i[0]);
		}
		else
		{
			debug2(i[0], i[1]);
		}
	}
	*/
//	pause;

	return 0;
}