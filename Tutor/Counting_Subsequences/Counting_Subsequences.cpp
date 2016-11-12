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
#define s(x) set<x >;
#define reverse(x) reverse(begin((x)),end((x)));
#define sort(x) sort(begin((x)),end((x)));
#define printarr(x1,y1,x2,y2,xy) for (int x=(x1);x<(y1);x++){ for (int y=(x2);y<(y2);y++) {cout<<(((xy)[x][y]))<<' ';} newln}
#define in(x) cin>>(x);
#define in2(x,y) cin>>(x)>>(y);
#define in3(x,y,z) cin>>(x)>>(y)>>(z);
#define in4(x,y,z,a) cin>>(x)>>(y)>>(z)>>(a);
#define in5(x,y,z,a,b) cin>>(x)>>(y)>>(z)>>(a)>>(b);
/*
this problem requires a clever recurrence relation, think about special cases:
-if all letters are different, then the answer has to be 2^N - 1  (N is the length of the whole string)
-if a certain letter repeats, then how do we properly count the # of subseqs ?

let ways(n) be the number of subseqs of the the first n letters only, now analyze 2 possible cases:
-the n'th letter hasn't occurred before in the string
-the n'th letter occurred already (ie. repeated at least once)

how can we define ways(n) in terms of ways(n-1) and other ways(k) where k<n ?

test="aba"

ways(1) = {NULL, a}
ways(2) = {a,b,ab,NULL}
ways(3) = {a,b,ab,NULL,    aa,ba,aba}

ways(n-1) = {
	w[1],
	w[2],
	w[3],
	...
	w[t]  }

-----------------------------------

w[1]+'a'
w[2]+'a'
w[3]+'a'
...
w[t]+'a'



*/
string seq;
set<string> seqset;
/*
	ACSII

	A: 97
	B: 98
	...
	Y: 121
	Z: 122
*/
//int dp[91]; //dp[i]: number of subsequences ending with letter l[i]
void getSeq(int ind, string subseq)
{
	if (ind >= seq.lenn)
	{
		seqset.insert(subseq);
		return;
	}

	getSeq(ind + 1, subseq + seq[ind]);
	getSeq(ind + 1, subseq);


}


int main()
{
	in(seq);

	getSeq(0, "");
	print((seqset.size() - 1)%10007);
	pause;
	return 0;
}