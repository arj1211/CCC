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


int best[101][105];
int rows[101][105];
int triangle[101][105];

int N;

int getBest(int r,int c)
{
	if (r==N)
		return triangle[r][c];
	if (best[r][c]!=-1)return best[r][c];
	int left, right;

	left=getBest(r+1,c);
	right=getBest(r+1,c+1);

	return best[r][c]=(triangle[r][c]+max(left,right));

}

int solve()
{
	int i, j, maxx;
	best[1][1] = rows[1][1];//the best you can have for the first row, is the number at that row
	for (i = 2; i <= N; i++)//for everything else...
	{
		best[i][1] = rows[i][1] + best[i - 1][1];//the best of the start of this row, is the element directly above it, plus itself
		for (j = 2; j <= i; j++)//for every other number in this row except the last...
			best[i][j] = rows[i][j] + max(best[i - 1][j], best[i - 1][j - 1]);//the best at ANY location, is the current element, plus the max of the two elements above it
		best[i][i] = rows[i][i] + best[i - 1][i - 1];//the best of the end of this row, is the element directly above it, plus itself
	}
	maxx = best[N][1];//the initial max sum is the best sum of the last row, first element
	for (i = 2; i<=N; i++)//for every element in the last row of best sums...
		if (best[N][i] > maxx)//if the current element is better than the current best sum...
			maxx = best[N][i];//the new maximum is the current element
	return maxx;
}

int main()
{
	in(N);

	for (int k = 0; k < 101; k++)
		for (int t = 0; t < 101; t++)
			best[k][t] = -1;


	for(int row=1;row<=N;row++)
		for(int col=1;col<=row;col++)
			in(triangle[row][col]);

	print(getBest(1,1));
	pause;
	return 0;
}