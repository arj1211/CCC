#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;

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
#define pI pair<int,int>
#define p(x) pair<x,x>
#define vpI vector<pair<int,int> >

void printvecpair(v(p(string)) vp)
{
	for (auto p : vp)
		printpair(p);
}


map<string,char> letters;
int k;
string encoded;
int main()
{
	cin>>k;
	cin.ignore();

	while (k--)
	{
		char c;
		string s;
		cin >> c>>s;
		letters[s]=c;
		//debug2(c,s);
	}

	cin >> encoded;

	while (encoded.length())
	{
		string cand="";
		for (int i=0;i<encoded.length();i++)
		{
			cand+=encoded[i];
			if (letters.count(cand)!=0)
			{
				cout<<letters[cand];
				encoded.erase(0, i+1);
				break;
			}
		}
	}
	return 0;
}

/*
5
A 00
B 01
C 10
D 110
E 111
00000101111
Sample Output

AABBE
*/
