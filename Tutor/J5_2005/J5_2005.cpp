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

//	Mathematical Definition of problem:
/*
	(1)		<monkey-word> ::= <a-word> | <a-word> "N" <monkey-word>
	(2)		<a-word> ::= A | "B" <monkey-word> "S" 
*/
// (1) a 'monkey word' is an 'a-word' OR an 'a-word' followed by a 'monkey word', seperated by a single 'N'
// (2) an 'a-word' is an 'A' OR a 'B' followed by a 'monkey word' followed by an 'S' to match the 'B'

bool monkey(string word); // pre-declare 'monkey' function, 
							// because 'a-word' function uses it, and can't if the
							// declaration is AFTER the 'a-word' declaration

bool aword(string word)	// function that returns 'true' if string 'word' is a valid 'a-word'
{
	if (word == "A") return true; // if 'word' is 'A', its a monkey word
	
	if (word[0] == 'B') // if 'word' starts with 'B'...
		if (word[word.lenn - 1] == 'S') // and if 'word' ends with 'S'...
			return monkey(word.substr(1,word.lenn-2)); // test if the letters in between 'B' and 'S' form a valid monkey word

	return false; // if 'word' isn't 'A' or 'B'+<valid monkey word>+'S', its not a monkey word
}

bool monkey(string word)	// function that returns 'true' if 'word' is a valid 'monkey word'
{
	if (aword(word)) return true; // if 'word' is an 'a-word', its a valid 'monkey word'

	for (int i=0;i<word.lenn;i++) // linear search all current characters in 'word'...
	{
		if (word[i]=='N') // if the current letter in 'word' is 'N'...
		{
			// 012345
			// BANAN
			if (aword(word.substr(0,i))) // if everything preceding this letter ('N') is an 'a-word'...
			{
				if (monkey(word.substr(i+1))) return true; // and if everything after this letter is 
															//a 'monkey-word', then 'word' is a valid 'monkey word'
			}
		}
	}
	return false; // if 'word' is not an 'a-word' and contains no 'a-word's or 'monkey word's separated by 'N's, 'word' is not a monkey word

}



int main()
{
	string word;

	while (cin >> word && word != "X")
	{
		if (monkey(word))
		{
			debug("YES");
		}
		else
		{
			debug("NO");
		}
	}


	return 0;
}