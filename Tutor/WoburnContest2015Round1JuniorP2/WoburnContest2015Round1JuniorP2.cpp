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


int Nrecruits, Mgroups;

vI groups;




void grp(int n, int m)
{

	if (n%m == 0)
	{
		cout << m << " group(s) of " << (n / m) << endl;
		return;
	}

	for (int u = 0; n > m; u++)
	{
		groups[u]++;
		n--;
		if (u >= groups.lenn - 1) u = -1;
	}
	sort(groups);
	reverse(groups);

	//printvec(groups);

	for (int t = 101; t >= 0; t--)
	{
		if (count(groups.begin(), groups.end(), t) == 0) continue;

		cout << count(groups.begin(), groups.end(), t) << " group(s) of " << t + 1 << endl;
	}
	return;
}


int main()
{

	cin >> Nrecruits >> Mgroups;

	groups.resize(Mgroups);//exactly M # of groups

	grp(Nrecruits, Mgroups);


	/*
		Alternate solution:

		if (N % M == 0)
		{
		cout << M << " group(s) of " << (N / M) << endl;
		}
		else
		{
		cout << (M - N % M) << " group(s) of " << (N / M) << endl;
		cout << (N % M) << " group(s) of " << (N / M + 1) << endl;
		}

		*/

	/*
		Ex. 7 kids, 3 groups


		groups:

		|||		||		||

		#1		#2		#3


		'type1' groups are the groups with the largest number of students in a group without counting the remainder students
		in the case of 7 kids and 3 groups, the floor-division of 7 and 3's quotient is 2. therefore 'type1' groups will each have 2 kids in them.

		'type2' groups are the groups with 1 extra student in them (the number of remaining students cannot be equalto or larger than the number of groups,
		otherwise we could make larger 'type1' groups.)
		It must be 1 extra student, because we are trying to 'even-out' the group sizes, so each of the remaining kids will go to a different group, so no group is more than +-1 kid from the rest of the groups.



		#of type1:
		total groups - remaining kids = # of type1 groups

		ie. 3 - 7%3 = 2

		therefore 2 groups (each with 7/3 rounded-down #of kids) of type1



		#of type2:
		remaining kids = # of type2 groups (since each remaining kid goes to a different group)

		ie. 7%3 = 1

		therefore 1 group (each with 1 extra kid than the size of a type1 group; so thats 7/3(floored) + 1, or plus 7%3, same thing)
		of type2



		from the solution.....:
		"The first observation is that there are only two possibilities for the answer: either the students are evenly distributed
		(all group sizes are the same) or some groups will have at most 1 more recruit than others (there are exactly two
		group sizes). The reason for this should be intuitive – we know that there definitely exists a way to make M groups
		of equal sizes which are as big as possible, simply by having some students left over. The number of students left
		over must be smaller than M, because otherwise we would create even bigger evenly-sized groups by
		taking M students from the leftovers to distribute one-each amongst the groups (contradicting how we assumed the
		groups were as big as possible). Intuition is an important skill to have during programming contests because we do
		not have to prove anything rigorously in order to implement it. As long as we're intuitively convinced that it is right,
		we can go for the answer.
		With that in mind, we have to actually come up with formulas. Our formulas will require the modulo operation
		(mod) which takes the remainder after division. 5 mod 2 is equal to 1, for example. It is available in nearly all
		programming languages (the operator is the % sign in both C++ and Python). So, let's consider the two cases
		separately:
		• To check if we can evenly divide N students amongst M groups, we just check if the remainder of N divided
		by M is 0. If N mod M is 0, we know that there are M groups of size N/M each.
		• Otherwise, it must be that there are 2 group sizes. Intuitively, we know that some groups will have size N/M,
		rounded down (call these type 1 groups). Since we know that we'll have to distribute the leftover students,
		some groups will have a size that's exactly 1 more than the value of N/M rounded down (call these type 2
		groups).
		How many type 2 groups are there? Well that's exactly the number of leftover students there are (N mod M,
		since we're distributing 1 leftover student to each type 2 group)! However many type 2 groups there are,
		the number of type 1 groups must be be exactly M minus that number since there are M groups total."






		*/





	pause;
	return 0;
}