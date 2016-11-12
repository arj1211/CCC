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
#include <stack>
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

//TLE ON LAST TEST CASE


/*
	radius <= 25 000
	count < 2 000 000 000
*/

//doesnt works
//vI coors(25001, 0);//index: radius, val: #ofpoints -4 


//bool check(int x, int y, int r)
//{
//	if (x*x + y*y <= r*r) return true;
//	else return false;
//}

// y <= sqrt( r*r-x*x )
	int points(int r) //given radius r, find all integer coordinates in boundary 
	{
		int numPoints = 0;
		//from [-r,-r] to [r,r] incrementative by +1, check: if true, count++;
		for (int i = -r; i <= r; i++)
		{
			numPoints += 2 * (int(sqrt(r*r - i*i))) + 1;
		}
			/*for (int j = -r; j <= r; j++)
				if (check(i, j, r)) numPoints++;*/
		return numPoints;
	}

/*

//doesnt work

int points(int r) //given radius r, find all integer coordinates in boundary 
{
	int numPoints = 0;

	if (coors[r] != 0) return coors[r];

	//from [-r,-r] to [r,r] incrementative by +1, check: if true, count++;
	for (int i = -(r-1); i <= r-1; i++)
			if (check(i, r-1, r)) numPoints++;

	coors[r] = points(r - 2) + 4 * numPoints;

	return coors[r];

}
*/
int main()
{
	int radius;
	fast_input;
	while (cin>>radius && radius != 0)
	{
		print(points(radius));
	}
	return 0;
}