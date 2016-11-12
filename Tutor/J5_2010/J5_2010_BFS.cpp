#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <queue>
using namespace std;
//WORKS NOW
#define debug(x) cout << (x) << endl;
#define debug2(x,y) cout << (x) << " " << (y) << endl;
#define debug3(x,y,z) cout << (x) << " " << (y) << " " << (z) <<  endl;
#define debug4(x,y,z,q) cout << (x) << " " << (y) << " " << (z) << " " << (q) <<  endl;
#define fast_input ios::sync_with_stdio(0);cin.tie(0)
#define pause system("pause")
#define pbb push_back
#define printvec(vec) for(auto i:vec){ cout<<i<<" ";}cout<<endl;
#define printvec2(vec2) for(auto i:vec2)for(auto k: i){ cout<<(k)<<" ";}cout<<endl;
#define printpair(p) cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
#define printmap(m) for (auto i : m){cout<<"{"<<i.first<<", "<<i.second<<"}"<<endl;}
#define vI vector<int>
#define v(x) vector<x >
#define vVI vector<vector<int> >
#define vV(x) vector<vector<x > >
#define pI pair<int,int>
#define p(x) pair<x,x >
#define vpI vector<pair<int,int> >
#define vp(x) vector<pair<x,x> >
#define lenn length()
#define newln debug("")
#define max(x,y) (x)>(y)?(x):(y)
#define INF 9999
int startx, starty, endx, endy, dist[9][9];

struct state
{
	int row, col, hops;
};

queue<state> q; 

void add(int row, int col, int hops)
{
	if (row<1 || row>8 || col<1 || col>8) return;
	if(dist[row][col]<INF) return;
	dist[row][col]=hops;
	state newState = {row,col,hops};
	q.push(newState);
}

void handle()
{
		state stateFront = q.front();
		q.pop();

		//debug3(stateFront.row,stateFront.col,stateFront.hops);
		if (stateFront.row == endx && stateFront.col == endy) 
			{
				debug(dist[endx][endy]);
				exit(0);
			}
		for ( int dr=-2; dr<=2; dr++ )
			for ( int dc=-2; dc<=2; dc++ )
				if ( abs(dr)+abs(dc) == 3 )
					add(stateFront.row + dr, stateFront.col + dc, stateFront.hops + 1);
}

int main()
{

	cin >> startx >> starty >> endx >> endy;

	for (int i = 0; i <= 8; i++)
		for (int j = 0; j <= 8; j++)
			dist[i][j] = 9999;

	add(startx, starty, 0);

	while(!q.empty())
	{
		handle();
	}

	

	return 0;
}