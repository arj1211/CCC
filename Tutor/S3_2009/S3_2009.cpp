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

vVI connections(51, vI());
vI dist(51); 

queue<pI> q;

void add(int node, int sep)
{
	if (dist[node]<INF) return;
	dist[node]=sep;
	q.push({node,sep});
}

void handle()
{
		pI state = q.front();
		q.pop();

		int node = state.first; 
		int sep = state.second; 
		//debug2(node,sep);
		//visit all neighbors

		for (int i=0;i<connections[node].size();i++)
			add(connections[node][i], sep+1);

}

void bfs(int start, int end)
{
	vFill(dist,INF);
	//debug3("*** bfs ",start, end);
	add(start, 0);

	while(!q.empty())
	{
		handle();
	}

	if (dist[end] < INF) print(dist[end])
	else print(-1);
}

void ff(int start)
{
	vFill(dist,INF);

	add(start, 0);

	while(!q.empty())
	{
		handle();
	}

	int total=0;
	for (int i=0; i<50; i++)
	{
		if (dist[i]==2) total++;
	}
	print(total);
}

void make(int i, int j)
{
    connections[i].push_back(j);
    connections[j].push_back(i);
}

void del(int i, int j)
{
	vector<int>::iterator it;
  	it = find (connections[i].begin(), connections[i].end(), j);
  	connections[i].erase(it);

  	it = find (connections[j].begin(), connections[j].end(), i);
  	connections[j].erase(it);
}

void declare(void)
{
    make(2,6);
    make(1,6);
    make(7,6);
    make(5,6);
    make(4,6);
    make(3,6);
    make(3,4);
    make(4,5);
    make(3,5);
    make(3,15);
    make(15,13);
    make(14,13);
    make(12,13);
    make(12,11);
    make(11,10);
    make(9,10);
    make(9,12);
    make(8,9);
    make(7,8);
    make(16,18);
    make(18,17);
    make(16,17);
}




int main()
{
	declare();
	while (1)
	{
		string s;
		in(s);
		int x,y;

		if (s[0]=='i')
		{
			in2(x,y);
			make(x,y);
		}
		else if (s[0]=='d')
		{
			in2(x,y);
			del(x,y);
		}
		else if (s[0]=='n')
		{
			in(x);
			print(connections[x].size());
		}
		else if (s[0]=='f')
		{
			in(x);
			ff(x);
		}
		else if (s[0]=='s')
		{
			in2(x,y);
			bfs(x,y);
		}
		else if (s[0]=='q') break;

	}

	return 0;
}