#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;
//WORKING
#define debug(x) cout << #x <<' '<< (x) << endl;
#define print(x) cout << (x) << endl;
#define debug2(x,y) cout << #x << ' ' << (x) << ' ' << #y << ' ' << (y) << endl;
#define print2(x,y) cout << (x) << ' ' << (y) << endl;
#define debug3(x,y,z) cout << #x << ' ' << (x) << ' ' << #y << ' ' << (y) << ' ' << #z << ' ' << (z) <<  endl;
#define print3(x,y,z) cout << (x) << ' ' << (y) << ' ' << (z) << endl;
#define debug4(x,y,z,a) cout << #x << ' ' << (x) << ' ' << #y << ' ' << (y) << ' ' << #z << ' ' << (z) << ' ' << #a << ' ' << (a) << endl;
#define print4(x,y,z,a) cout << (x) << ' ' << (y) << ' ' << (z) << ' ' << (a) << endl;
#define fast_input ios::sync_with_stdio(0);cin.tie(0)
#define pause system("pause")
#define pbb push_back
#define printvec(vec) for(auto i:vec){ cout<<i<<" ";}cout<<endl;
#define printvec2(vec2) for(auto i:vec2){for(auto k: i){ cout<<(k)<<" ";}cout<<endl;}cout<<endl;
#define printpair(p) cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
#define printmap(m) for (auto i : m){cout<<"{"<<i.first<<", "<<i.second<<"}"<<endl;}
typedef vector<int> vI;
typedef vector<string> vS;
#define v(x) vector<x >
typedef vector<vector<int> > vVI;
#define vV(x) vector<vector<x > >
typedef pair<int, int> pI;
typedef pair<string, string> pS;
#define p(x) pair<x,x >
typedef vector<pair<int, int> > vPI;
#define vp(x) vector<pair<x,x> >
#define lenn size()
#define newln print("")
typedef set<int> sI;
#define s(x) set<x >;
#define reverse(x) reverse(begin((x)),end((x)));
#define sort(x) sort(begin((x)),end((x)));
#define printarr(x,y,arr) for ((x);(x)<(y);(x)++){cout<<((arr)[x])<<' ';} newln
#define printarr2(x1,y1,x2,y2,xy) for (int x=(x1);x<(y1);x++){ for (int y=(x2);y<(y2);y++) {cout<<(((xy)[x][y]))<<' ';} newln}
#define in(x) cin>>(x);
#define in2(x,y) cin>>(x)>>(y);
#define in3(x,y,z) cin>>(x)>>(y)>>(z);
#define in4(x,y,z,a) cin>>(x)>>(y)>>(z)>>(a);
#define in5(x,y,z,a,b) cin>>(x)>>(y)>>(z)>>(a)>>(b);

string names[101];
int maxGroupSize,queueLength,timeTake[101], choice[101];
//Params: the maximum size a group can have, the total amount of people in line, the time it takes the ith person to cross, the best size of group to take starting from the ith person


// 1, 2 3, ... k, k+1, k+2, ... Q

int slowest(int i, int j) //the time it'll take a group comprised of people at position i to position j in line
{

	int m=0;

	for (i;i<=j;i++)
		if (m<timeTake[i]) m=timeTake[i];
	
	return m;

}

int getBest(int k) //get lowest amount of time it'll take to get group of people [k to queueLength] over the bridge
{
	//Base case
	int peopleLeft = queueLength-k+1; //the amount of people remaining; 'k' is the left-most person in the current group (considering group going from left to right in queue order)
	if (peopleLeft<=maxGroupSize) //if there are only 'maxGroupSize' people left, or less, put them all in one group of size 'peopleLeft'
	{
		choice[k]=peopleLeft; //the best choice of group size at this point, would just be everyone left in the queue
		return slowest(k, queueLength);	//the max amount of time, for this group of people
	} 
	//General case
	int minTime=99999;//minimum amount of time, initialized to a sentinal value
	for (int i=1; i<=maxGroupSize;i++) //for every possible group size starting from group of size 1, up till the largest possible group size...
	{
		int right = k+i-1; //the right-most person in this group, considering the queue starting from the left
		int totalTime = slowest(k,right) + getBest(right+1); // the total time the entire queue will take is the max time this group will take, plus the lowest amount of time it'll take to get the rest of the people (in the queue) over the bridge
		if (totalTime<minTime) //if we have found a new minimum time achieveble, update the minimum time
		{
			minTime=totalTime;
			choice[k]=i; //since this specific size of group creates a new minimum time, it is the best choice of size, given 'k' as the position of the first person in this group
		}
	}
	return minTime;
}

void recnames(int k)//recontruct the groupings
{
	int gsize= choice[k]; //the size of the current group is the optimal size if we start at person 'k'
	if (gsize==0) return; //if the 'optimal size' is a group of 0, meaning we're done sending everyone over the bridge, exit out
	while(gsize--) //while there are people left in the group...
	{
		cout<<names[k]<<' '; //print out 'k' person's name
		k++; //increment to next person in this group
	}
	newln; //go to the next line, as we're done this group
	recnames(k); //the 'k' parameter is now at the idex of teh first person of the next group, so recursivly call this function again until there are no more groups
}

int main()
{
	in2(maxGroupSize, queueLength); //input 2 params

	for (int i = 1; i <= queueLength; i++) //for every person..
		in2(names[i], timeTake[i]);//input into corresponding arrays

	print2("Total Time:",getBest(1));//using getBest(1), we are returning the best (meaning lowest) time achievable making groups starting from first person in line, to teh very end.

	//for (int i = 1; i <= queueLength; i++)
	//	debug3(i,getBest(i),choice[i]);
	recnames(1); //similarly, we are printing out the groupings starting from the first group (with first person in it) to the very last person and the group that they're in

	return 0;
}