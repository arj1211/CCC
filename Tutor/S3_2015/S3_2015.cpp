#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;
//return to later
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


int G, P, maxPlanes = 0;
vI planes;
v(char) gates(100001,1); // 1: open gate, 0:closed

int main()
{

	cin >> G >> P;
	
	while (P--)
	{
		int plane;
		cin >> plane;
		//planes.pbb(plane);
		int i;
		for (i=plane;i>0;i--)
		{
			if (gates[i])
			{
				break;
			}
		}

		if (i)
		{
			gates[i]=0;
			maxPlanes++;
		}
		else
		{
			debug(maxPlanes);
			return 0;
		}
	}
	debug(maxPlanes);
	// printvec(planes);
	// printvec(gates);
	//up till here ok


	// for (int i : planes)
	// {
	// 	int j = (i - 1);
	// 	debug4("i,j: ", i, " ", j);
	// 	debug(gates[j]);
	// 	// while (!gates[j] && j>=0)
	// 	// {
	// 	// 	j--;
	// 	// }

	// 	// if (!gates[j]) break;

	// 	// // if gate matching planeReqested is open
	// 	// maxPlanes++;
	// 	// gates[j] = 0;
	// }

	// debug(maxPlanes);

	return 0;
}