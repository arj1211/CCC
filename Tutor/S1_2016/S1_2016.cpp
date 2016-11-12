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
#define debug5(x,y,z,a,b) cout << #x << ' ' << (x) << ' ' << #y << ' ' << (y) << ' ' << #z << ' ' << (z) << ' ' << #a << ' ' << (a) << ' ' << #b << ' ' << (b) << endl;
#define print4(x,y,z,a) cout << (x) << ' ' << (y) << ' ' << (z) << ' ' << (a) << endl;
#define print5(x,y,z,a,b) cout << (x) << ' ' << (y) << ' ' << (z) << ' ' << (a) <<' '<<(b)<< endl;
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
#define MAX 1000001
#define INF 99999999
#define vFill(v,f) fill((v).begin(),(v).end(),(f))
#define sqrdist(x,y) ((x)*(x)+(y)*(y))
#define arrFill(a,filler) memset((a),(filler),sizeof (a))


//LIKELY SOLVED



bool anagram(string a, string b)
{
	//arrays to hold # of times each letter in a string occurs, init to 0
	//int freq_A[26] = { 0 };
	//int freq_B[26] = { 0 };
	vector <int> freq_A(256, 0);
	vector <int> freq_B(256, 0);
	vector <int> differenceInFreq(256, 0);


	/*
	fills up the first char array;
	adding 1 for each occurance of a letter to
	that letter count, stored in the index of
	the array associated with that
	letter. ( 'a'==0, 'z'==25; indicies)
	*/
	for (int count = 0; count < a.size(); ++count)
	{
		freq_A[a[count]]++;
	}

	//same with the second char array...

	for (int count = 0; count < b.size(); ++count)
	{
		freq_B[b[count]]++;
	}

	for (int count = 0; count < a.size(); count++)
	{
		differenceInFreq[a[count]] = freq_A[a[count]] - freq_B[b[count]]; //diff in freq of 'this' letter...
	}



	int stars = freq_B['*'];

	for (int i = 0; i < a.size(); i++)
	{
		if (stars <= 0) break;
		if (freq_A[a[i]] == freq_B[a[i]]) continue; //freq of letter same in both strings
		freq_B[a[i]]++;
		stars--;
	}

	if (stars) return false; //if theres stars left, then its not same length

	for (int i = 0; i < a.size(); i++)
	{
		if (freq_A[a[i]] != freq_B[a[i]]) return false;
	}

	/*
	now, for each letter in the english alphabet,
	see if the number of occurances of each
	letter in either string is the same.
	if even 1 letter count is not the same, return false and stop.
	*/
	/*
		for (int count = 'a'; count <= 'z'; count++)
		{
		if (freq_A[count] != freq_B[count])
		return false;
		}
		*/
	return true;

}

int main()
{
	string line1, line2;
	getline(cin, line1);
	getline(cin, line2);


	if (anagram(line1, line2)) print("A")
	else print("N");
	
	return 0;
}