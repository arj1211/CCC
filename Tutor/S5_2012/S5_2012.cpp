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
#define newln print("")
typedef set<int> sI;
#define reverse(x) reverse(begin((x)),end((x)));
#define sort(x) sort(begin((x)),end((x)));
#define printarr(x1,y1,x2,y2,xy) for (int x=(x1);x<(y1);x++){ for (int y=(x2);y<(y2);y++) {cout<<(((xy)[x][y]))<<' ';} newln}
#define in(x) cin>>(x);
#define in2(x,y) cin>>(x)>>(y);
#define in3(x,y,z) cin>>(x)>>(y)>>(z);
#define in4(x,y,z,a) cin>>(x)>>(y)>>(z)>>(a);
#define in5(x,y,z,a,b) cin>>(x)>>(y)>>(z)>>(a)>>(b);


int R, C, K;
int grid[26][26],
dp[26][26];


//Bottom-up DP approach 

int getWays1(int posx, int posy)
{
	if (dp[posx][posy] > -1) return dp[posx][posy];//if we've been here...
	if (posx == 1 && posy == 1)//if we're at the start (since this is bottom-up approach)
	{
		return dp[posx][posy] = 1;
	}
	if (posx < 1 || posy < 1) return 0;//if we're past our goal (went too far)
	if (grid[posx][posy] < 0) return 0;//theres a cat here

	return dp[posx][posy] = getWays1(posx - 1, posy) +
		getWays1(posx, posy - 1);

}

//Top-down not working..

int getWays2(int posx, int posy)
{
	if (dp[posx][posy] > -1) return dp[posx][posy];

	if (posx == R && posy == C)
		return dp[posx][posy] = 1;

	if (posx > R || posy>C) return dp[posx][posy] = 0;
	if (grid[posx][posy] < 0) return dp[posx][posy] = 0;

	return dp[posx][posy] = dp[posx + 1][posy] + dp[posx][posy + 1];

}

int main()
{

	for (int i = 0; i <= 25; i++)
		for (int j = 0; j <= 25; j++)
		{
			grid[i][j] = 1;
			dp[i][j] = -1;
		}

	
	
	in3(R, C, K);
	//R = 3, C = 4, K = 2;

	while (K--)
	{
		int g, h;
		in2(g, h);
		grid[g][h] = -999;
	}

	/*grid[1][3] = -1;
	grid[2][2] = -1;*/


	print(getWays1(R, C));
	//print(getWays2(1, 1));


	pause;
	return 0;
}