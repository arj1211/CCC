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
#define INF (1000000000-1)
//dont know how to implement DP, 0/50 WA on judge

int clubs[33];
int ClubCount;
int Distance;
int counter = INF;
bool found = false;

void rec(int clubInd, int distLeft)
{
	//debug4(clubInd,clubs[clubInd],distLeft,counter);
	if (found) return;
	if (distLeft == 0)
	{
		found = true;
		return;
	}
	if (clubs[clubInd] > distLeft) return;

	counter++;
	//if the current club is within the distance left bound

	//cycle through all clubs in decending order, and choose the next greatest that fits

	for (int i = clubInd; i < ClubCount; i++)
		rec(i, distLeft - clubs[clubInd]);
	return;


}

void rec2(int currDist, int strokes)
{

	if (currDist > Distance || strokes > counter) return;
	//debug2(currDist, strokes);
	if (currDist == Distance)
	{
		counter = min(counter, strokes);
		//debug(counter);
		return;
	}

	for (int j = 0; j < ClubCount; j++)
		rec2(currDist + clubs[j], strokes + 1);
}

vI best(5281, -1);
vI choice(5281, -1);

int getBest(int dist)
{
	if (dist > Distance) return INF;
	if (dist == Distance) return 0;
	if (best[dist] != -1) return best[dist];

	int opt = INF;

	for (int u = 0; u < ClubCount; u++)
	{
		int currStrokes = 1 + getBest(dist + clubs[u]);
		if (currStrokes < opt) { 
			choice[dist] = clubs[u];
			opt = currStrokes; 
		}
	}

	return best[dist] = opt;

}




int main()
{
	in2(Distance, ClubCount);

	for (int u = 0; u < ClubCount; u++)
		in(clubs[u]);
	/*for (int u = 0; u < ClubCount; u++)
		cout << clubs[u] << ' ';
		newln;*/
	/*sort(clubs);
	reverse(clubs)*/
	/*for (int u = 0; u < ClubCount; u++)
		cout << clubs[u] << ' ';
		newln;*/
	//rec2(0, 0);
	counter = getBest(0);
	if (counter != INF)
	{
		cout << "Roberta wins in " << counter << " strokes." << endl;
	}
	else
	{
		print("Roberta acknowledges defeat.");
	}
	/*for (int i = 0; i <= Distance; i++)
	{
		debug3(i, best[i], choice[i]);
	}*/
	int dis = 0;
	while (dis < Distance)
	{
		int currClub = choice[dis];
		cout << currClub << ' ';
		dis += currClub;
	}
	pause;
	return 0;
}