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

int N, M;
int phos[100001];
qI q;
sI times;

v(v(bool)) path(100001, v(bool)(100001));
//vvv reset these two each time new start node in dfs
bool visited[100001];
bool isPho[100001];

int minTime = INF;

bool allHasBeen()
{
	for (int i = 0; i < N; i++)
		if (!visited[phos[i]]) return false;
	return true;
}

bool foundAll = false;

void dfs(int node, int localTime)
{
	if (foundAll) return;//if we've already gotten to all phos: backtrack
	if (allHasBeen())
	{
		print("***Visited All***");
		debug2(localTime, minTime);
		minTime = min(localTime, minTime);
		times.insert(minTime);
		foundAll = true;
		return;
	}

	if (visited[node]) return;
	print4("Visiting", node, "localTime:", localTime);
	visited[node] = true;//visit this node

	if (allHasBeen())
	{
		print("***Visited All***");
		debug2(localTime, minTime);
		minTime = min(localTime, minTime);
		print2("New minTime:", minTime);
		times.insert(minTime);
		foundAll = true;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (foundAll) break;
		if (path[node][i] && !visited[i])
		{
			print2("Going to visit:", i);
			dfs(i, localTime + 1);
		}
	}

	print3("No more neighbors of", node, "found. Backtracking...");
	//if this node has no more neighbors, and it was a pho restaurant, increment localTime by 1. 
	//if it wasnt a pho restaurant, but had atleast 1 pho neighbor, increment localTime by 1.

	//at this point, node has no more neighbors
	if (isPho[node]) localTime++;
	else
	{
		//check thru all neighbors
		for (int i = 0; i < N; i++)
			if (path[node][i] && visited[i])//if neighbor of current node, and we've gone to it already
			{//this is a valid neighbor
				if (isPho[phos[i]])//and if its a pho
				{
					localTime++;
					return;
				}
			}

		//at this point, this node wasnt pho, and had no pho neighbors we visited. dont increment localTime
	}


}

void bfs(int start)
{
	int localTime = 0;
	q.push(start);
	visited[start] = true;
	print2("Starting point node:", start);
	while (!q.empty())
	{
		if (allHasBeen())
		{
			print("***Visited All***");
			debug2(localTime, minTime);
			minTime = min(localTime, minTime);
			times.insert(minTime);
			return;
		}

		int node = q.front(); //consider current restaurant 
		q.pop();// take it off queue
		visited[node] = true;//"visit" this restaurant
		localTime++;//simulate going to this restaurant from the last one, so add 1 minute
		print4("Visiting (", node, "), current localTime:", localTime);

		//add every valid neighbor of this restaurant to queue
		bool foundANeighbor = false;
		for (int i = 0; i < N; i++)
			if (path[node][i] && !visited[i])
			{
				q.push(i);
				foundANeighbor = true;
			}
		if (!foundANeighbor) localTime--;
	}

	print("Visited every node, never reached all phos.");

	return;

}


/* BFS
input:
8 2
5 2
0 1
0 2
2 3
4 3
6 1
1 5
7 3

output:

phos: 5 2

Starting point node: 5
Visiting ( 5 ), current localTime: 1
Visiting ( 1 ), current localTime: 2
Visiting ( 0 ), current localTime: 3
Visiting ( 6 ), current localTime: 4
Visiting ( 2 ), current localTime: 4
***Visited All***
localTime 4 minTime 99999999
Starting point node: 2
Visiting ( 3 ), current localTime: 1
Visiting ( 2 ), current localTime: 2
Visiting ( 4 ), current localTime: 3
Visiting ( 7 ), current localTime: 3
Visiting ( 0 ), current localTime: 3
Visiting ( 1 ), current localTime: 4
Visiting ( 5 ), current localTime: 5
***Visited All***
localTime 4 minTime 4
times: { 4 }

Press any key to continue . . .*/

/*
8 5
0 6 4 3 7
0 1
0 2
2 3
4 3
6 1
1 5
7 3
*/


int main()
{
	fast_input;
	in2(N, M);
	for (int i = 1; i <= M; i++)
	{
		in(phos[i]);
		isPho[phos[i]] = true;
	}

	for (int i = 1; i < N; i++)
	{
		int x, y;
		in2(x, y);
		path[x][y] = true;
		path[y][x] = true;
	}


	newln;
	cout << "phos: ";
	for (int i = 1; i <= M; i++)
		cout << phos[i] << ' ';
	newln; newln;

	print("DFS:");
	for (int i = 1; i <= M; i++)
	{
		print2("Starting node:", phos[i]);
		dfs(phos[i], 0);
		foundAll = false;
		arrFill(visited, false);
		arrFill(isPho, false);
		newln;
	}

	/*print("BFS:");
	for (int i = 1; i <= M; i++)
	{
	bfs(phos[i]);
	arrFill(visited, false);
	newln;
	}*/


	cout << "times: {";
	for (int i : times)
		cout << ' ' << i << ' ';
	print("}"); newln;

	print(minTime);

	pause;

	return 0;
}