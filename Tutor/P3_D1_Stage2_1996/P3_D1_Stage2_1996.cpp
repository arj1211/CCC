#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;
//WORKING NOW
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


int N, stringIndxrGL;
string pre1, pre2;

int blackpix;

int fig1[33][33], fig2[33][33];


/*
	split the sqr into 4 each time, and keep splitting each of those into 4

	*/

// fills up the fig1 and fig2 arrays to represent black/white sectors. 
void gen(int posx, int posy, int resoUnits = 32)
{
	int x, y;
	stringIndxrGL++;
	//we want to actually CHANGE the 'stringIndxrGL' value, so we never read letters we've read before
	if (pre1[stringIndxrGL-1] == 'p')
	{
		/*	[2][1]
			[3][4]	*/

		//1
		gen(posx + (resoUnits / 2), posy, resoUnits / 2);
		//2
		gen(posx, posy, resoUnits / 2);
		//3
		gen(posx, posy + (resoUnits / 2), resoUnits / 2);
		//4
		gen(posx + (resoUnits / 2), posy + (resoUnits / 2), resoUnits / 2);

		return;

	}
	if (pre1[stringIndxrGL-1] == 'e')//if its white
	{
		for ( x = posx; x < posx+resoUnits; x++)
			for ( y = posy; y < posy+resoUnits; y++)
				fig1[y][x] = 0;
		return;
	}
	if (pre1[stringIndxrGL-1] == 'f')//if its black
	{
		for ( x = posx; x < posx+resoUnits; x++)
			for ( y = posy; y < posy+resoUnits; y++)
				fig1[y][x] = 1;
		return;
	}
}

void gen2(int posx, int posy, int resoUnits = 32)
{
	int x, y;
	stringIndxrGL++;
	//we want to actually CHANGE the 'stringIndxrGL' value, so we never read letters we've read before
	if (pre2[stringIndxrGL-1] == 'p')
	{
		/*	[2][1]
			[3][4]	*/

		//1
		gen2(posx + (resoUnits / 2), posy, resoUnits / 2);
		//2
		gen2(posx, posy, resoUnits / 2);
		//3
		gen2(posx, posy + (resoUnits / 2), resoUnits / 2);
		//4
		gen2(posx + (resoUnits / 2), posy + (resoUnits / 2), resoUnits / 2);

		return;

	}
	if (pre2[stringIndxrGL-1] == 'e')//if its white
	{
		for ( x = posx; x < posx+resoUnits; x++)
			for ( y = posy; y < posy+resoUnits; y++)
				fig2[y][x] = 0;
		return;
	}
	if (pre2[stringIndxrGL-1] == 'f')//if its black
	{
		for ( x = posx; x < posx+resoUnits; x++)
			for ( y = posy; y < posy+resoUnits; y++)
				fig2[y][x] = 1;
		return;
	}
}

int main()
{
	cin >> N;


	while (N--)
	{
		cin >> pre1 >> pre2;
		stringIndxrGL = 0;
		gen(1, 1);
		stringIndxrGL = 0;
		gen2(1, 1);

		for (int i = 0; i <= 32; i++)
			for (int j = 0; j <= 32; j++)
				blackpix += max(fig1[i][j], fig2[i][j]);

		cout << "There are " << blackpix << " black pixels." << endl;
		blackpix = 0;
	}


	pause;
	return 0;
}