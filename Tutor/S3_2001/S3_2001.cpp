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

bool points['Z' + 1]['Z' + 1] //adjacency list; [i][j] where 'j' is a neighbor of 'i'
, visited['Z' + 1];
string roads[10001];
v(string) bomb;
int bombs=0;

/*bool path(char a, char b)//true: there is a path, false: there isnt
{
	if (points[a][b] || points[b][a])
		return visited[a] = true;

	if (visited[a]) return false;

	visited[a] = true;

	bool found = false;

	for (char neighbor : points[a])
		if (path(neighbor, b))
		{
			found = true;
			break;
		} 
	return found;
}*/

void resetVisited()
{
	for (int i = 'A'; i <= 'Z'; i++)
			visited[i] = false;
}


void startDFSon(char p)
{
	if (visited[p]) return;
	visited[p]=true;
	//go to each neighbor of point 'p'
	for (int i = 'A';i<='Z';i++)
		if (points[p][i]) startDFSon(i);
}

	/*for (char i = 'A'; i <= 'Z'; i++)
		for (char j = i + 1; j <= 'Z';j++)
			if (edge[i][j]){
				reset();
				edge[i][j] = false;
				edge[j][i] = false;
				visit('A');
				if (visited['B'] == false){
					cout << i << j << endl;
					counter++;
				}
				edge[i][j] = true;
				edge[j][i] = true;
			}	*/

void solve()
{
	//go throgh each road one by one, destroy each, re-check to see if theres still a path from 'A' to 'B'
	for (char i='A';i<='Z';i++)
		for (char j=i+1;j<='Z';j++)
			if (points[i][j])
			{
				resetVisited();
				points[i][j]=false;
				points[j][i]=false;
				startDFSon('A');
				if (!visited['B']) 
				{
					cout<<i<<j<<endl;
					bombs++;
				}
				points[i][j]=true;
				points[j][i]=true;
			}
}


int main()
{
	string s;
	while (cin>>s && s != "**")
	{
		points[s[0]][s[1]] = true;
		points[s[1]][s[0]] = true;
		//print(s);
	}

	/*for (string rd : roads)
	{
		
		points[rd[0]][rd[1]] = false;
		points[rd[1]][rd[0]] = false;
		if (!path('A', 'B')) bomb.pbb(rd);
		resetVisited();
		points[rd[0]][rd[1]] = true;
		points[rd[1]][rd[0]] = true;
	}
	printvec(bomb);*/

	solve();

	print3("There are",bombs,"disconnecting roads.");


	pause;

	return 0;
}

/*Old

//int points[27];
//bool roads[2 * 'Z' + 2][2 * 'Z' + 2], visited[2 * 'Z' + 2];
//v(string) block;
//char alphas[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
////vV(bool) roads(91, v(char)());
//
//bool path(char a, char b)
//{
//	if (roads[a][b] || roads[b][a]) return true;//if direct road...
//	if (visited[a]) return false;
//	visited[a] = true;
//	bool found = false;
//	//for every connected point to 'a'
//	for (char neighbor : roads[a])
//	{
//		if (path(neighbor, b))
//		{
//			found = true;
//			break;
//		}
//	}
//
//	return found;
//
//}
//
//void brkroad(char a, char b)
//{
//	roads[a][b] = false;
//	roads[b][a] = false;
//}
//void mkroad(char a, char b)
//{
//	roads[a][b] = true;
//	roads[b][a] = true;
//}
//
//void destroy()
//{
//	for (char c : alphas)
//	{
//		for (char d : roads[c])
//			{
//				if (!roads[c][d]) continue;
//				brkroad(c, d);
//				if (!path('A', 'B'))
//				{
//					string rd = "" + c + d;
//					block.pbb(rd);
//				}
//				mkroad(c, d);
//			}
//	}
//}
//
//int main()
//{
//	string s;
//	while (cin >> s && s != "**")
//	{
//		roads[s[0]][s[1]] = true;//adjacency list
//		roads[s[1]][s[0]] = true;//adjacency list
//	}
//	//printvec(block);
//	pause;
//	return 0;
//}

*/