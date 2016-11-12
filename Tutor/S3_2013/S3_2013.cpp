#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout << #x<<' '<< (x) << endl;
#define debug2(x,y) cout << <<#x<<' '<< (x) << " " << #y << ' '<<(y) << endl;
#define debug3(x,y,z) cout << #x<<' '<<(x) << " " << #y<<' '<<(y) << " " << #z<<' '<<(z) <<  endl;
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

int T, G;
int A, B, Sa, Sb;
int games[5][5];

/*
	0: unplayed
	1: first team win
	2: second team win
	3: tie
*/

int totalWins=0;

void recurse()
{

	for (int i=1;i<=4;i++)
		for (int j=i+1;j<=4;j++)
		{
			if (games[i][j]==0)
			{
				games[i][j]=1;
				recurse();
				games[i][j]=2;
				recurse();
				games[i][j]=3;
				recurse();

				games[i][j]=0;
				return;
			}
		}



	vI scores(5,0);
	for (int i=1;i<=4;i++)
		for (int j=i+1;j<=4;j++)
		{


			if (games[i][j]==1) scores[i]+=3;
			else if (games[i][j]==2) scores[j]+=3;
			else 
			{
				scores[i]++;
				scores[j]++;
			}


		}

		int teamTscore=scores[T];
		sort(scores.begin(),scores.end());
		reverse(scores.begin(),scores.end());

		if (teamTscore==scores[0] && teamTscore>scores[1])
			totalWins++;


}

int main()
{
	cin >> T >> G;
	
	while (G--)
	{
		cin >> A >> B >> Sa >> Sb;

		if (Sa>Sb) games[A][B]=1;
		else if (Sa<Sb) games[A][B]=2;
		else games[A][B]=3;

	}
	recurse();
	cout<<totalWins<<endl;

	return 0;
}