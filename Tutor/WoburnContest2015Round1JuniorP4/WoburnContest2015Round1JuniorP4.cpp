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
#define newln debug("")
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)>(y)?(y):(x)
typedef set<int> sI;
#define reverse(x) reverse(begin((x)),end((x)));
#define sort(x) sort(begin((x)),end((x)));
//UNSOLVED, LOOK BACK FOR ANALYSIS

/*
Transportation:

- total transCost = Tbase + Ti of each attraction

- "the overall transportation cost is the sum of the base transportation
cost and the transportation costs incurred across all of the attractions
they decide to visit."
*/
/*
Hotels:

- total hotelCost = maxValue(hotel costs of all attractions, including the base cost)

- "Since the team will not be attending more than one hotel, we have to
prepare for the worst and assume that the overall hotel cost for the
entire trip will be the maximum of Hbase and Hi across all of the attractions
that the team eventually decides to attend."
*/
/*
Food:

- total foodCost = Fbase - Fi(1) - Fi(2) - Fi(3) - .... - Fi(n)

after above calculation...

if foodCost < 0: foodCost = 0

- "the overall food cost will be the base food cost Fbase subtract the Fi for
each attraction i that was attended. The base food cost cannot go
below zero – after Fbase has been reduced to zero, attending"
*/




int exL;
int Em, Tb, Hb, Fb, N;

vVI attractions;
vVI attractionsPicked;

int totalTransCost, totalHotelCost, totalFoodCost;

void choose(int attractionIndex, int transCost, int hotelCost, int foodCost, int excitementVal)
{
	if (excitementVal >= Em) return;

	
}


int main()
{
	cin >> Em >> Tb >> Hb >> Fb;
	totalTransCost += Tb;
	totalHotelCost += Hb;
	totalFoodCost += Fb;
	cin >> N;

	while (N--)
	{
		int e, t, h, f;
		cin >> e >> t >> h >> f;

		vI thisone = { e, t, h, f };
		attractions.pbb(thisone);
	}

	sort(attractions);
	reverse(attractions);
	print("\n");
	printvec2(attractions);

	pause;

	return 0;
}