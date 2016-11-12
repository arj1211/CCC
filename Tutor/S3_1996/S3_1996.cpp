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

int n,k,cases;


void recurse(string s, int nOnes) //'s' is the string that keeps changing. 'nOnes' is the number of '1's present in the string
{
	
	if (nOnes>k) // if theres too many '1's in the current string, go back up a level
		return;

	//string tmp( "  ", s.size() );
	//debug2( tmp, "recurse: ["+s+']');

	if (s.lenn == n) // if the string is currently at its max length...
	{
		if (nOnes==k) // and it contains the right number of '1's...
			debug(s); // print it, and go back up a level
	}
	else // otherwise if its not long enough...
	{
		recurse(s+'1', nOnes+1); // call the function with the same string + '1' concatenated at the end, and increment the number of '1's present
		recurse(s+'0',nOnes);// also call the function with the same string + '0' concatenated at the end
	}
}

/*


		n=2, no k param:


					    ''					level 1
				    /        \
				  '0'        '1'			level 2
				/    \     /    \     
			 '00'   '01' '10'  '11'			level 3



	Every time a leaf is reached on this binary tree, it returns (or prints) 
	the string, and then backtracks up 1 level, and continues 
	to the right (-->) branch. When the branches are over, it backtracks a level 
	higher (since it stops recursivly calling itself, so the last call has a chance to continue). 






*/



int main()
{

	cin >> cases;
	while (cases--)
	{
		cin >> n >> k;
		debug("The bit patterns are");
		recurse("",0); // start off with an empty string, and it initially has 0 '1's
		newln;
	}
	pause;
	return 0;
}