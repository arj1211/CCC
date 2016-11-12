#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
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

int startx, starty, endx, endy, board[9][9];

void hop(int row, int col, int hops)
{

	//if (board[row][col] != 9999) return;

	if (row > 0 && row <= 8 && col > 0 && col <= 8 && hops <= board[row][col])
	{
		board[row][col] = hops;

		/*
		5|		8		1
		4|	7				2
		3|			K
		2|	6				3
		1|		5		4
		-+----------------------
		|	1	2	3	4	5

		8 possible moves given a Knight's spot...


		K(3,3)

		1(4,5)	+1,+2
		2(5,4)	+2,+1
		3(5,2)	+2,-1
		4(4,1)	+1,-2
		5(2,1)	-1,-2
		6(1,2)	-2,-1
		7(1,4)	-2,+1
		8(2,5)	-1,+2
		*/


		for ( int dr=-2; dr<=2; dr++ )
			for ( int dc=-2; dc<=2; dc++ )
				if ( abs(dr)+abs(dc) == 3 )
					hop(row + dr, col + dc, hops + 1);

/*
		hop(row + 1, col + 2, hops + 1);
		hop(row + 2, col + 1, hops + 1);
		hop(row + 2, col - 1, hops + 1);
		hop(row + 1, col - 2, hops + 1);
		hop(row - 1, col - 2, hops + 1);
		hop(row - 2, col - 1, hops + 1);
		hop(row - 2, col + 1, hops + 1);
		hop(row - 1, col + 2, hops + 1);
		*/
	}
}

int main()
{

	cin >> startx >> starty >> endx >> endy;

	for (int i = 0; i <= 8; i++)
		for (int j = 0; j <= 8; j++)
			board[i][j] = 9999;


	hop(startx, starty, 0);

	debug(board[endx][endy]);

	return 0;
}