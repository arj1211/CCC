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
#define debug(x) cout << #x<<' '<< (x) << endl;
#define debug2(x,y) cout << <<#x<<' '<< (x) << " " << #y << ' '<<(y) << endl;
#define debug3(x,y,z) cout << #x<<' '<<(x) << " " << #y<<' '<<(y) << " " << #z<<' '<<(z) <<  endl;
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
#define vp(x) vector<pair<x,x> >
#define lenn length()
#define newln debug("")
#define max(x,y) (x)>(y)?(x):(y)


vI motelLocations = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };

int A, B, N, m;


int totalWays=0;

void recurse(int currInd, int prevInd)
{

	int hotelDist = motelLocations[currInd]-motelLocations[prevInd]; //distance of next hotel from previous one stayed at
	if (hotelDist>B) return; // if violates law maximum
	if (motelLocations[currInd]==7000)//if its last hotel...
	{
		//cout<<"found ";
		//debug3(currInd,prevInd,hotelDist);
		if (hotelDist>=A)//and we've gone far enough
			totalWays++;
		return;
	}


	//debug3(currInd,prevInd,hotelDist);



	/*
		Stay at currHotel:
	*/

	if (hotelDist>=A)
	{
		recurse(currInd+1,currInd);
	}

	// Skip currHotel:

	recurse(currInd+1,prevInd);

}




int main()
{
	cin >> A >> B >> N;

	while (N--)
	{
		cin >> m;
		motelLocations.pbb(m);
	}

	sort(motelLocations.begin(),motelLocations.end());

	recurse(1,0);

	//debug(totalWays);
	cout<<totalWays<<endl;
	return 0;
}