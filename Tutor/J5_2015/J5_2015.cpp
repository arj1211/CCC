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
#define in(x) cin>>(x);

/*
For example, if you have 8 pieces of pie and 4 people in line, you could give out pieces of pie in the following five ways (with the first person in line being the first number in the list):
 [1, 1, 1, 5], [1, 1, 2, 4], [1, 1, 3, 3], [1, 2, 2, 3], [2, 2, 2, 2].

*/

int dp[251][251][251];
bool vis[251][251][251];

int getWays(int n, int k, int s)
{
	if (n<0)return 0;
	if (k==0)return n==0;
	if (s*k > n) return 0;

	if (vis[n][k][s]) return dp[n][k][s];

	int total=0;
	for (int i=s;i<=n;i++)
	{
		total+=getWays(n-i,k-1,i);
	}	
	//debug4(n,k,s,total);
	vis[n][k][s]=true;
	return dp[n][k][s]=total;


}


int ways[256][256];
int recurse(int pieces, int people)
{
	if (pieces < people)
	{
		ways[pieces][people] = 0;
		return 0;
	}
	if (people == 1 || pieces == people)
	{
		ways[pieces][people] = 1;
		return 1;
	}
	if (ways[pieces][people] != -1) return ways[pieces][people];
	/*
		either:
			give the first person 1 piece, and find how many ways are possible for (pieces-1,people-1)

			or

			give everyone 1 piece of pie, so you are left with (pieces-people) pieces of pie, and still the same number of people
				from here, you try to do the same thing, until you either have 1 person left, and some number of pies, in which case theres 1 way (which will be added to 1 level up the stack, so will have a compounding additive effect on the final result (adding 1 several times) )
				or, you run out of pies to give, and you still have people left, in which case theres 0 ways, which will be ignored in the #ofWays for 1 level up the stack


			Ex. 8 pieces, 4 people:

			*everyone a piece : (if first person takes >1 piece, 
			 everyone must get atleast that many, therefore they all get 1 more)



					8 pieces, 4 people
						give 1 piece to first person
							7 pieces, 3 people
								give 1 piece to first person
									6 pieces, 2 people
										give 1 piece to first person
											5 pieces, 1 person
												Only 1 way														(+1)
										Give everyone a piece 
											4 pieces, 2 people
												give 1 piece to first person
													3 pieces, 2 people
														give 1 piece to first person
															2 pieces, 2 people
																Only 1 way						(+1)
														give everyone a piece			
															1 piece, 2 people
																No way
														Therefore, +1+0= (1 way) for 3 pieces, 2 people	(+1)
												give everyone a piece
													2 pieces, 2 people
														Only 1 way										(+1)
												Therefore, +1+1= (2 ways) for 4 pieces, 2 people				(+2)
										Therefore, +1+2 = (3 ways) for 6 pieces, 2 people								(+3)
								give everyone a piece
									4 pieces, 3 people
										give first person a piece
											3 pieces, 2 people
												==already computed: 1 way==										(+1)
										give everyone a piece
											1 piece, 3 people
												no way
										therefore, +1+0 = (1 way) for 4 pieces, 3 people								(+1)
								therefore, +3+1 = (4 ways)	for 7 pieces, 3 people												(+4)
						give everyone a piece
							4 pieces, 4 people
								Only 1 way																						(+1)
					therefore, +4+1 = (5 ways) for 8 pieces, 4 people																		(+5)


		Therefore, ans= 5

				


	*/
	return ways[pieces][people] = recurse(pieces - 1, people - 1) + recurse(pieces - people, people);

}

int main()
{
	for (int i = 0; i <= 255; i++)
		for (int j = 0; j <= 255; j++)
			ways[i][j] = -1;

	int people, pieces;
	in(pieces);
	in(people);
	print(getWays(pieces, people,1));
	//printarr(pieces-7,pieces+1,people-3,people+1,ways);
	//print(ways[pieces][people]);
	pause;
	return 0;
}