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

//// internet method
//bool replace(std::string& str, const std::string& from, const std::string& to)
//{
//	size_t start_pos = str.find(from);
//	if (start_pos == std::string::npos)
//		return false;
//	str.replace(start_pos, from.length(), to);
//	return true;
//}
// internet method
void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}


int k;
v(p(string))chars;
string encoded;


int main()
{
	cin >> k;
	

	while (k--)
	{
		string letter, code;
		cin >> letter >> code;
		chars.pbb({ letter, code });
	}

	

	cin >> encoded;
	

	
	for (p(string) p : chars)
		replaceAll(encoded, p.second, p.first);


	cout << encoded << endl;
	pause;

	return 0;
}