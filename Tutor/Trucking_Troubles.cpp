// TIMUS JUDGE ID: 189234ZA
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
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
#define newln print("")
typedef set<int> sI;
typedef queue<int> qI;
#define s(x) set<x >
#define reverse(x) reverse(begin((x)),end((x)));
#define sort(x) sort(begin((x)),end((x)));
#define printarr(x,y,arr) for ((x);(x)<(y);(x)++){cout<<((arr)[x])<<' ';} newln
#define printarr2(x1,y1,x2,y2,xy) for (int x=(x1);x<(y1);x++){ for (int y=(x2);y<(y2);y++) {cout<<(((xy)[x][y]))<<' ';} newln}
#define in(x) cin>>(x);
#define in2(x,y) cin>>(x)>>(y);
#define in3(x,y,z) cin>>(x)>>(y)>>(z);
#define in4(x,y,z,a) cin>>(x)>>(y)>>(z)>>(a);
#define in5(x,y,z,a,b) cin>>(x)>>(y)>>(z)>>(a)>>(b);
#define MAX 1000001
#define INF 9999999
#define vFill(v,f) fill((v).begin(),(v).end(),(f))

int C,R,D;

vVI neighbors(10001, vector<int>());
vVI weights(10001, vector<int>());
v(bool) visited(10001);
vI dest;

/*
-write a function that takes a specific weight W and returns true or false iff 
it's possible to visit all destination cities using only bridges that support a weight of at least W.
so for example on the sample case this function should return:
  possible(40)=false
  possible(25)=true
-now what's the smallest number of times that you have to call possible(W) 
with different values of W to find the 'final answer' ?

possible(1), possible(2), possible(3), .... possible(1000)
1111111..1111111111111111111100000000000000......00000
*/
int maxWeight;
int highestWeight;
void dfs(int city)
{
	if (visited[city]) return;
	visited[city]=true;
	//debug(city);
	for (int i=0;i<neighbors[city].size();i++)
	{
		if (weights[city][i]>=maxWeight)
		{
			dfs(neighbors[city][i]);
		}
	}
}

bool possible(int W)
{
	maxWeight=W;
	vFill(visited,false);
	//debug2("possible",W);
	dfs(1);
	for(int i=0;i<dest.lenn;i++)
		if (!visited[dest[i]]) return false;

	return true;
}

int solve()
{
	int w=highestWeight;
	int jump=100;

	while(w-jump>0)
	{
		if( possible(w-jump) ) break;
		w-=jump;
	}

	while(w>0)
	{
		if( possible(w) ) return w;
		w--;
	}

	return 0;
}

int main()
{
	in3(C,R,D);
	
	while(R--)
	{
		int source, dest, wire;
		in3(source,dest,wire);
		neighbors[source].pbb(dest);
		neighbors[dest].pbb(source);

		weights[source].pbb(wire);
		weights[dest].pbb(wire);
		highestWeight=max(highestWeight,wire);
	}
	while(D--)
	{
		int destCity;
		in(destCity);
		dest.pbb(destCity);
	}

	//debug(possible(40));
	//debug(possible(25));
	print(solve());
	return 0;
}