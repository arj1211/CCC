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
#define printvec2(vec2) for(auto i:vec2)for(auto k: i){ cout<<(k)<<" ";}cout<<endl;
#define printpair(p) cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
#define printmap(m) for (auto i : m){cout<<"{"<<i.first<<", "<<i.second<<"}"<<endl;}
#define vI vector<int>
#define vS vector<string>
#define v(x) vector<x >
#define vVI vector<vector<int> >
#define vV(x) vector<vector<x > >
#define pI pair<int,int>
#define pS pair<string,string>
#define p(x) pair<x,x >
#define vpI vector<pair<int,int> >
#define vp(x) vector<pair<x,x> >
#define lenn length()
#define newln debug("")
#define max(x,y) (x)>(y)?(x):(y)

vS a,b;

int m,n;

int choices[40];
bool found=false;
void recurse(string partialA, string partialB, int slot)
{
	if (slot==m) return;
	if (found) return;

	int k = min(partialA.lenn,partialB.lenn);

	for (int y=0;y<k;y++)
	{
	//	if (partialA[y]!=partialB[y]) return;
	}

	if (partialA!="" && partialB==partialA)
	{
		found=true;
		print(slot);
		for (int i = 0; i < slot; ++i)
		{
			print(choices[i]+1);
		}
		return;
	}

	for (int i=0;i<n;i++)
	{
		choices[slot]=i;
		recurse(partialA+a[i],partialB+b[i],slot+1);
	}
}


int main()
{
	cin>>m>>n;

	for (int i=0;i<n;i++)
	{
		string tempp;
		cin>>tempp;
		a.pbb(tempp);
	}

	for (int i=0;i<n;i++)
	{
		string tempp;
		cin>>tempp;
		b.pbb(tempp);
	}

	recurse("","",0);

	if (!found)
		print("No solution.");


	return 0;
}