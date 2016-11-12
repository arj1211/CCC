#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
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
#define printvec2(vec2) for(auto i:vec2)for(auto k: i){ cout<<(k)<<" ";}cout<<endl;
#define printpair(p) cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
#define printmap(m) for (auto i : m){cout<<"{"<<i.first<<", "<<i.second<<"}"<<endl;}
#define vI vector<int>
#define v(x) vector<x >
#define vVI vector<vector<int> >
#define vV(x) vector<vector<x > >
#define pI pair<int,int>
#define p(x) pair<x,x >
#define vpI vector<pair<int,int> >
#define vp(x) vector<pair<x,x > >

/*
Greedy Algorithm, and the Greedy Approach (Reading):
	https://www.topcoder.com/community/data-science/data-science-tutorials/greedy-is-good/


Excerpt:

"So, if we are to choose a single activity, 
choosing the one that ends first (at a time t1), 
will leave all the remaining time interval 
free for choosing other activities. If we choose 
any other activity instead, the remaining time 
interval will be shorter."


The gist...
— Select the activity with the earliest finish time
— Eliminate/Disregard the activities that could 
	not be scheduled (all and up till the last activity that conflicts with 'this' one)
— Repeat!


— Greedy in the sense that it leaves as much opportunity 
	as possible for the remaining activities to be scheduled
— The greedy choice is the one that maximizes the amount
	of unscheduled time remaining


*/
int N;//# of reports
vpI events;//list of pairs, holding the start and ending intervals of the times of the reports
int main()
{
	cin >> N;

	while (N--)
	{
		int end,start;
		cin >> start>>end; // take in start and end time
		events.pbb({end,start}); //insert it into the list of pairs in REVERSE order, so we can sort by the ending time.
	}

	sort(begin(events),end(events));//sort the reports by their ending time (the one that finishes soonest, will be first in the list)

	int last = -1, numEvents=0; 
	// 'last': finishing time of the previous activity 
	// considered (ie. the last activity). it is 
	// initialized to -1 so it can be re-assigned 
	// on the first iteration of the following loop
	//'numEvents' is the max # of reports he can attend. Initialized to 0


	for (int y=0;y<events.size();y++)//for each report in the sorted 'events' list
	{
		if (events[y].second>last)//if the starting time of the activity in question is after the ending time of the last activity...
		{
			numEvents++; // inc numEvents
			last=events[y].first; // reassign the 'last' activity to the finishing time of the current activity
		}
	}

	debug(numEvents);
	pause;
	return 0;
}