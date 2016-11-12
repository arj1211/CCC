#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;
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
#define newln debug("")
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)>(y)?(y):(x)
typedef set<int> sI;

//COME BACK TO 

vVI partsList;
int sum(vI v)
{
	int sum = 0;
	for (int i : v) sum += i;
	return sum;
}

// void part(int k, vI currPartition)
// {

// 	// if (sum(currPartition) == k)
// 	// {
// 	// 	partsList.pbb(currPartition);
// 	// 	return;
// 	// }
// 	// if (sum(currPartition) > k) return;
// 	// for (int u = 1; u <= k; u++)
// 	// {
// 	// 	currPartition.pbb(u);
// 	// 	part(k, currPartition);
// 	// 	currPartition.pop_back();
// 	// }

// 	// return;
// }


int cases, target, partInd;

int slots[101];
int counter=0;
void recurse(int prev, int currTotal, int currSlot)
{
	if (counter>=partInd) return;
	if (currTotal>target) return;
	if (currTotal==target)
	{
		counter++;
		if (counter==partInd)
		{
			int i=1;
			cout<<'(';
			for (;i<currSlot-1;i++)
			{
				cout<<slots[i]<<',';
			}
			cout<<slots[i]<<')'<<endl;
		}
		return;
	}

	for (int i=1;i<=prev;i++)
	{
		slots[currSlot]=i;
		recurse(i,currTotal+i,currSlot+1);
	}

}

int main()
{
	cin>>cases;
	while (cases--)
	{
		cin >> target >> partInd;
		recurse(target,0,1);
		if (counter<partInd) print("Too big");
		counter=0;
	}
	// cin>>cases;

	// while(cases--)
	// {
	// 	int k,a;
	// 	cin>>k>>a;

	// }
	//vI parts;
	// part(k, parts);
	// reverse(partsList.begin(),partsList.end());

	// printvec2(partsList);

	// if (a>partsList.lenn) print("Too big")
	// 	else
	// 	{
	// 		cout<<'(';
	// 		int i=0;
	// 		for (;i<partsList[a-1].lenn-1;i++)
	// 			cout<<partsList[a-1][i]<<',';
	// 		cout<<partsList[a-1][i]<<')';
	// 	}
	
	return 0;
}