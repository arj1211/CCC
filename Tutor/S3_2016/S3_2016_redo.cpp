#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
#define debug(x) cout << #x <<' '<< (x) << endl;
#define print(x) cout << (x) << endl;
#define debug2(x,y) cout << #x << ' ' << (x) << ' ' << #y << ' ' << (y) << endl;
#define print2(x,y) cout << (x) << ' ' << (y) << endl;
#define debug3(x,y,z) cout << #x << ' ' << (x) << ' ' << #y << ' ' << (y) << ' ' << #z << ' ' << (z) <<  endl;
#define print3(x,y,z) cout << (x) << ' ' << (y) << ' ' << (z) << endl;
#define debug4(x,y,z,a) cout << #x << ' ' << (x) << ' ' << #y << ' ' << (y) << ' ' << #z << ' ' << (z) << ' ' << #a << ' ' << (a) << endl;
#define debug5(x,y,z,a,b) cout << #x << ' ' << (x) << ' ' << #y << ' ' << (y) << ' ' << #z << ' ' << (z) << ' ' << #a << ' ' << (a) << ' ' << #b << ' ' << (b) << endl;
#define print4(x,y,z,a) cout << (x) << ' ' << (y) << ' ' << (z) << ' ' << (a) << endl;
#define print5(x,y,z,a,b) cout << (x) << ' ' << (y) << ' ' << (z) << ' ' << (a) <<' '<<(b)<< endl;
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
#define reverseV(x) reverse(begin((x)),end((x)));
#define sortV(x) sort(begin((x)),end((x)));
#define printarr(x,y,arr) for ((x);(x)<(y);(x)++){cout<<((arr)[x])<<' ';} newln
#define printarr2(x1,y1,x2,y2,xy) for (int x=(x1);x<(y1);x++){ for (int y=(x2);y<(y2);y++) {cout<<(((xy)[x][y]))<<' ';} newln}
#define in(x) cin>>(x);
#define in2(x,y) cin>>(x)>>(y);
#define in3(x,y,z) cin>>(x)>>(y)>>(z);
#define in4(x,y,z,a) cin>>(x)>>(y)>>(z)>>(a);
#define in5(x,y,z,a,b) cin>>(x)>>(y)>>(z)>>(a)>>(b);
#define MAX 1000001
#define INF 99999999
#define vFill(v,f) fill((v).begin(),(v).end(),(f))
#define sqrdist(x,y) ((x)*(x)+(y)*(y))
#define arrFill(a,filler) memset((a),(filler),sizeof (a))

v(bool) availNums(10,true);

int N, M, W, P;

vVI neighbors(100001, vector<int>());
v(bool) visited(100001);
int endNode;

vI distances(100001);
vI phos;

int bestDist = INF;

void dfs(int node, int partialD)
{
	if (visited[node]) return;
	visited[node]=true;

	distances[node]=partialD;
	//debug2(node,partialD);
	// if (node==endNode) 
	// {
	// 	//print(partialD);
	// 	return;
	// }
	for (int i=0;i<neighbors[node].size();i++)
	{
		dfs(neighbors[node][i],1+partialD);
	}
}

int getDist(int start, int end)
{
	vFill(visited,false);
	dfs(start,0);
	return distances[end];
}

void recurse(int slotIndx, int partialDist, int prevNode)
{

	if (partialDist>=bestDist) return;
	//debug3(slotIndx,partialDist,prevNode);

	if (slotIndx==(M-1))
	{
		//debug2(partialDist, bestDist);
		bestDist = partialDist;
		return;
	}

	for (int i=0;i<M;i++)
	{
		if (availNums[i])
		{
			int nextNode = phos[i];
			int nextDist = getDist(prevNode,nextNode);
			availNums[i]=false;
			recurse(slotIndx+1, partialDist+nextDist, nextNode);
			availNums[i]=true;
		}
	}
}


int main()
{

	fast_input;
	in2(N, M);
	for (int i = 1; i <= M; i++)
	{
		int t;
		in(t);
		phos.pbb(t);
	}

	N--;
	while(N--)
	{
		int source, dest;
		in2(source,dest);
		neighbors[source].pbb(dest);
		neighbors[dest].pbb(source);
	}

	for (int i = 0; i <= M/2; i++)
	{
		availNums[i]=false;
		recurse(0, 0, phos[i]);
		availNums[i]=true;
	}

	print(bestDist);

	return 0;
}