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

int d, n, b, t, l, r;

char a[244][244];

int three[] = { 1, 3, 9, 27, 81, 243 };

int dimen;

int iters;

void generate()
{
	for (int i = 0; i <= dimen; i++)
		for (int j = 0; j <= dimen; j++)
			a[i][j] = '*';
}

void fillSpace(int left, int right, int top, int bottom, int iters)
{
	if (iters == 0) return;
	//debug2("iters ", iters);
	int x_go = (right - left) / 3;
	int y_go = (bottom - top) / 3;

	int x, y;

	//take out middle (purpose of this function)
	for (x = left + x_go; x < right - x_go; x++)
		for (y = top + y_go; y < bottom - y_go; y++)
			a[x][y] = ' ';

	// now we have 8 smaller squares, so call function 8 times...
	/*
		[1][2][3]
		[4]   [5]
		[6][7][8]
		*/

	//1
	fillSpace(left, right - 2 * x_go, top, bottom - 2 * y_go, iters - 1);
	//2
	fillSpace(left + x_go, right - x_go, top, bottom - 2 * y_go, iters - 1);
	//3
	fillSpace(x_go * 2 + left, right, top, bottom - 2 * y_go, iters - 1);
	//4
	fillSpace(left, right - 2 * x_go, top + y_go, bottom - y_go, iters - 1);
	//5
	fillSpace(left + x_go * 2, right, top + y_go, bottom - y_go, iters - 1);
	//6
	fillSpace(left, right - 2 * x_go, top + 2 * y_go, bottom, iters - 1);
	//7
	fillSpace(left + x_go, right - x_go, top + y_go * 2, bottom, iters - 1);
	//8
	fillSpace(left + x_go * 2, right, top + y_go * 2, bottom, iters - 1);
}


int main()
{
	cin >> d;
	//d = 1;
	while (d--)
	{
		cin >> n >> b >> t >> l >> r;

		//n = 3, b = 2, t = 10, l = 5, r = 27;

		iters = n;
		dimen = three[n];
		generate();
		fillSpace(0, dimen, 0, dimen, iters);

		/*for (int i = 0; i <= dimen; i++)
		{
		for (int j = 0; j <= dimen; j++)
		cout << a[i][j] << ' ';
		newln;
		}*/

		for (int y = t -1; y >= b-1; y--)
		{
			for (int x = l -1; x < r; x++)
			{
				cout << a[x][y] << ' ';
			}
			newln;
		}
	}
	pause;
	return 0;
}