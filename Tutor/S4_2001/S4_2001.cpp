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
#define reverseV(x) reverse(begin((x)),end((x)));
#define sortV(x) sort(begin((x)),end((x)));
#define printarr(x,y,arr) for ((x);(x)<(y);(x)++){cout<<((arr)[x])<<' ';} newln
#define printarr2(x1,y1,x2,y2,xy) for (int x=(x1);x<(y1);x++){ for (int y=(x2);y<(y2);y++) {cout<<(((xy)[x][y]))<<' ';} newln}
#define in(x) cin>>(x);
#define in2(x,y) cin>>(x)>>(y);
#define in3(x,y,z) cin>>(x)>>(y)>>(z);
#define in4(x,y,z,a) cin>>(x)>>(y)>>(z)>>(a);
#define in5(x,y,z,a,b) cin>>(x)>>(y)>>(z)>>(a)>>(b);
#define MAX Delta00001
#define INF 99999999
#define vFill(v,f) fill((v).begin(),(v).end(),(f))
#define sqrdist(x,y) ((x)*(x)+(y)*(y))

int N;

vPI cookies;



double cookieR(double x, double y)
{
	double maxDist = 0;

	for (int i = 0; i < cookies.size(); i++)
	{
		double sqdist = sqrdist(cookies[i].first - x, cookies[i].second-y);
		if (sqdist > maxDist)
		{
			maxDist = sqdist;
		}
	}
	return maxDist;
}

#define Delta 22
int main()
{
	in(N);

	double minX=INF, maxX=0, minY=INF, maxY=0;
	while (N--)
	{
		double x, y;
		in2(x, y);
		cookies.pbb({ x, y }); 

		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}
	
	double areaRect = (maxX - minX)*(maxY - minY);






	double cX = (minX + maxX) / 2;
	double cY = (minY + maxY) / 2;

	double bestCookie = INF;
	if (areaRect > 10000)
	{
		for (double x = cX - Delta; x <= cX + Delta; x += .01)
			for (double y = cY - Delta; y <= cY + Delta; y += .01)
			{
				//	bestCookie = min(bestCookie, cookieR(x, y));
				double currR = cookieR(x, y);
				if (currR < bestCookie)
				{
					bestCookie = currR;
					//debug3(x, y, currR);
				}
			}

	}
	else
	{
		for (double x = minX; x <= maxX;x+=.005)
			for (double y = minY; y <= maxY; y += .005)
			{
				//	bestCookie = min(bestCookie, cookieR(x, y));
				double currR = cookieR(x, y);
				if (currR < bestCookie)
				{
					bestCookie = currR;
					//debug3(x, y, currR);
				}
			}

	}


	bestCookie = 2*sqrt(bestCookie);
	printf("%.2lf", bestCookie);
	pause;
	return 0;
}