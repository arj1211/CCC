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


//COME BACK TO
int tests;
int grid[26][26];
bool visited[26][26];
//bool found = false;
int N;
//vI answers;
//
//void dfs(int orig /* orig/start point elevation*/, int x, int y, int oxy /* current oxygen usage */)
//{
//	//base cases
//
//	if (visited[x][y]) return;
//	//if (found) return;
//
//	if (x<1 || y<1 || x>N || y>N)
//		return;
//
//	if (grid[x][y] > orig + 2 || grid[x][y] < orig - 2)
//		return;
//
//	//visit point
//	visited[x][y] = true;
//
//	//print5("Visit ", x, y, " current oxy ", oxy)
//
//	if (x == N && y == N) //if final point
//	{
//		//if (grid[x][y] > orig) oxy++; //if oxygen required to get to final point
//	//	print2("Found a path with oxy",oxy);
//		grid[x][y] = oxy;
//		answers.pbb(grid[x][y]);
//		//found = true;
//		return;
//	}
//
//	//if intermidiate point
//		dfs(grid[x][y], x, y - 1, oxy + ((grid[x][y - 1] > grid[1][1]) || grid[x][y] > grid[1][1]));
//		dfs(grid[x][y], x, y + 1, oxy + ((grid[x][y + 1] > grid[1][1]) || grid[x][y] > grid[1][1]));
//		dfs(grid[x][y], x - 1, y, oxy + ((grid[x - 1][y] > grid[1][1]) || grid[x][y] > grid[1][1]));
//		dfs(grid[x][y], x + 1, y, oxy + ((grid[x + 1][y] > grid[1][1]) || grid[x][y] > grid[1][1]));
//}
//
//
//int main()
//{
//	in(tests);
//	while (tests--)
//	{
//		in(N);
//		for (int i = 1; i <= N; i++)
//			for (int j = 1; j <= N; j++)
//				in(grid[i][j]);
//		dfs(grid[1][1], 1, 1, 0);
//		printvec(answers);
//		sortV(answers);
//		printvec(answers);
//
//		if (answers.empty()) cout << "CANNOT MAKE THE TRIP" << "\n" << endl;
//		else cout << answers[0] << "\n" << endl;
//
//		//found = false;
//
//		for (int i = 0; i <= 25; i++)
//			for (int j = 0; j <= 25; j++)
//			{
//				grid[i][j] = 0;
//				visited[i][j] = 0;
//			}
//		answers.clear();
//	}
//	pause;
//	return 0;
//}


queue<pI> q;

int bfs(int startx, int starty)
{
	visited[startx][starty] = true;
	int oxygen = 0;//initial oxygen required
	q.push({ startx, starty });//put initial point in queue

	while (!q.empty())
	{
		pI v = q.front(); //current point
		q.pop();


		if (v.first == N && v.second == N)//got to last cell
			return oxygen + ((grid[N][N] > grid[1][1]) ? 1 : 0);


		oxygen += (grid[v.first][v.second] > grid[1][1]);

		//neighbors of 'v'
		pI up = { v.first, v.second - 1 };
		pI down = { v.first, v.second + 1 };
		pI left = { v.first - 1, v.second };
		pI right = { v.first + 1, v.second };


		// if we have not visited that neighbor yet
		// and if it is within +-2 elevation units
		// and if its not out of bounds

		// && grid[.first][.second]>=grid[v.first][v.second]-2 && grid[.first][.second]<=grid[v.first][v.second]+2

		if ((!visited[up.first][up.second]) && (grid[up.first][up.second] >= grid[v.first][v.second] - 2) && (grid[up.first][up.second] <= grid[v.first][v.second] + 2))
		{
			if ((0 < up.first < N) && (0 < up.second < N))
			{
				cout << "v:" << v.first << ' ' << v.second << endl;

				visited[up.first][up.second] = true;
				q.push(up);
			}
		}
		if ((!visited[down.first][down.second]) && (grid[down.first][down.second] >= grid[v.first][v.second] - 2) && (grid[down.first][down.second] <= grid[v.first][v.second] + 2))
		{
			if ((0 < down.first < N) && (0 < down.second < N))
			{
				cout << "v:" << v.first << ' ' << v.second << endl;

				visited[down.first][down.second] = true;
				q.push(down);
			}
		}
		if ((!visited[right.first][right.second]) && (grid[right.first][right.second] >= grid[v.first][v.second] - 2) && (grid[right.first][right.second] <= grid[v.first][v.second] + 2))
		{
			if ((0 < right.first < N) && (0 < right.second < N))
			{
				cout << "v:" << v.first << ' ' << v.second << endl;

				visited[right.first][right.second] = true;
				q.push(right);
			}
		}
		if ((!visited[left.first][left.second]) && (grid[left.first][left.second] >= grid[v.first][v.second] - 2) && (grid[left.first][left.second] <= grid[v.first][v.second] + 2))
		{
			if ((0 < left.first < N) && (0 < left.second < N))
			{
				cout << "v:" << v.first << ' ' << v.second << endl;

				visited[left.first][left.second] = true;
				q.push(left);
			}
		}
	}

	return -1;


}

int main()
{

	in(tests);
	while (tests--)
	{
		in(N);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				in(grid[i][j]);


		if (bfs(1, 1) == -1) print("CANNOT MAKE THE TRIP\n")
		else cout << bfs(1, 1) << "\n" << endl;


		for (int i = 0; i <= 25; i++)
			for (int j = 0; j <= 25; j++)
			{
				grid[i][j] = 0;
				visited[i][j] = 0;
			}

	}
	pause;
	return 0;
}