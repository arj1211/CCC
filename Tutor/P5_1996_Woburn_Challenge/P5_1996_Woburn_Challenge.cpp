#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;
//WORKING
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

int grid[101][101];
int dp[101][101];

int M, N;
//int appleCount = 0;
//vI appleCounts;
////0: empty, 1: apple
////either choose to go up or right
//
//
//
//int countx = 0, county = 0;//number of steps needed to get to next apple/ starting from either right or up
//
//int rightCount(int posx, int posy)//input coordinates of sqr just right to current one
//{
//	countx++;
//	if (grid[posx][posy])
//	{
//		int c = countx;
//		countx = 0;
//		return c;
//	}
//
//	if (posx == M && posy == N) return 9999;//sentinal: never found apple on this route
//
//	/*
//		ex.
//		—>
//		/        \
//		^	    	—>
//		/     \       /    \
//		^        —>    ^     —>
//
//		*/
//
//
//	//if sqr above has apple and to the right doesnt, dont even go to right
//	if (grid[posx][posy + 1] > grid[posx + 1][posy])
//		rightCount(posx, posy + 1);
//	//if sqr to right has apple and up doesnt, dont even go up
//	else if (grid[posx][posy + 1] < grid[posx + 1][posy])
//		rightCount(posx + 1, posy);
//	//if neither has apple, u gotta go both places
//	else
//	{
//		rightCount(posx, posy + 1);
//		rightCount(posx + 1, posy);
//	}
//
//
//}
//
//
//
//
//void recurse(int posx, int posy)
//{
//	if (posx == M && posy == N)
//	{
//		appleCounts.pbb(appleCount);
//		appleCount = 0;
//		return;//if we're at last square
//	}
//
//	if (grid[posx][posy] == 1) appleCount++;
//
//	if (grid[posx][posy + 1] > grid[posx][posy + 1])//if the one above has apple but to the right doesnt
//		//try up
//		recurse(posx, posy + 1);
//	else if (grid[posx][posy + 1] < grid[posx][posy + 1])//if the one to the right has apple but the one above doesnt
//		//try right
//		recurse(posx + 1, posy);
//
//}
//



void plenty()
{

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == 1)
			{
				if (j == 1)
				{
					//newln;
					dp[i][j] = grid[i][j];
					//cout << "dp[" << i << "][" << j << ']' << " " << dp[i][j] << endl;
				}
				else
				{
					//newln;
					dp[i][j] = (grid[i][j] + dp[i][j - 1]);
					//cout << "dp[" << i << "][" << j << ']' << " " << dp[i][j] << endl;
				}
			}
			else
			{
				if (j == 1)
				{
					//newln;
					dp[i][j] = (grid[i][j] + dp[i - 1][j]);
					//cout << "dp[" << i << "][" << j << ']' << " " << dp[i][j] << endl;
				}
				else
				{
					//newln;
					dp[i][j] = (grid[i][j] + max(dp[i - 1][j], dp[i][j - 1]));
					//cout << "dp[" << i << "][" << j << ']' << " " << dp[i][j] << endl;
				}
			}
		}
	}
}


int main()
{


	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
		{
			grid[i][j] = 0;
			dp[i][j] = 0;
		}




	cin >> M >> N;
	//sentinels 
	/*for (int i = 0; i <= M + 1; i++)
		grid[i][0] = 0;

		for (int i = 0; i <= N + 1; i++)
		grid[0][i] = 0;*/


	while (1)
	{
		int p, q;
		cin >> p >> q;
		if (p == 0 && q == 0) break;
		grid[p][q] = 1;
		dp[p][q] = 1;
	}
	//newln;
	//printarr(1, M + 1, 1, N + 1, grid);
	plenty();
	//newln;
	//printarr(1, M + 1, 1, N + 1, dp);
	//newln;
	print(dp[M][N]);



	//recurse(1, 1);
	//sort(appleCounts);
	//reverse(appleCounts);
	//print(appleCounts[0]);

	pause;

	return  0;

}

/*
4 4
1 3
2 2
2 3
2 4
3 2
3 4
4 1
4 4
0 0

*/