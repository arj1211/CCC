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

bool possibles[5000001];
int operations, digits, digs[12], targets, targs[7];

//how do I include operations count?


/*
	6
	10
	0
	1
	2
	3
	4
	5
	6
	7
	8
	9
	5
	56854
	531441
	48735
	14458
	99338
*/

//531441

bool visited[4782969+1][7];

void finder(int currentAmount, int slotNum)
{

	if (visited[currentAmount][slotNum]) return;
	visited[currentAmount][slotNum]=true;

	if (slotNum==operations+1) 
	{
		//debug2(currentAmount,slotNum);
		possibles[currentAmount]=true;
		return;
	}

	for (int y=1;y<=digits;y++)
	{
		finder(currentAmount+digs[y],slotNum+1);
		finder(currentAmount*digs[y],slotNum+1);
	}

	// if (targs[targetInd] == currentAmount) return true;

	// if (targs[targetInd] < currentAmount || digInd > digits) return false;


	// if (finder(targetInd, currentAmount + digs[digInd], digInd + 1) ||
	// 	finder(targetInd, currentAmount * digs[digInd], digInd + 1))
	// 	return true;
	// else return false;


}

int main()
{
	cin >> operations >> digits;

	for (int i = 1; i <= digits; i++)
		cin >> digs[i];

	cin >> targets;

	for (int u=1;u<=digits;u++)
		finder(digs[u],1);

	while(targets--)
	{
		int targ;
		cin>>targ;
		if (possibles[targ]) print('Y')
		else print('N');
	}


	return 0;
}