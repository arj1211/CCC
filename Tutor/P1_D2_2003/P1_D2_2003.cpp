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
#define printvec2(vec2) for(auto i:vec2)for(auto k: i){ cout<<(k)<<" ";}cout<<endl;
#define printpair(p) cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
#define printmap(m) for (auto i : m){cout<<"{"<<i.first<<", "<<i.second<<"}"<<endl;}
#define vI vector<int>
#define vS vector<string>
#define v(x) vector<x >
#define vVI vector<vector<int> >
#define vV(x) vector<vector<x > >
#define pI pair<int,int>
#define pS pair<string,string>
#define p(x) pair<x,x >
#define vpI vector<pair<int,int> >
#define vp(x) vector<pair<x,x> >
#define lenn length()
#define newln debug("")
#define max(x,y) (x)>(y)?(x):(y)


/*
	n=4, k=3


	(2,3):		9				24
		~~~~~~~~~~~~~~~ --------------------
				1234			1234
				1243			1243
				1423			1324
				4123			1342
				4213			1423
				4231			1432
				2431			2134
				2341			2143
				2314			2314
								2341
								2413
								2431
								3124
								3142
								3214
								3241
								3412
								3421
								4123
								4132
								4213
								4231
								4312
								4312
*/

v(bool) availNums(10,true);

int n, k, numPerms = 0;
vI perm(10); 
int permNum=0;
bool checkPerm();
bool constraints[10][10];
void recurse(int slotIndx)
{
	if (slotIndx==n)
	{
		if (checkPerm()) {
			permNum++;
		//printvec(perm);
	}
		return;
	}

	for (int i=1;i<=n;i++)
	{
		if (availNums[i])
		{
			perm[slotIndx]=i;
			availNums[i]=false;
			recurse(slotIndx+1);
			availNums[i]=true;
		}
	}
}




bool checkPerm()
{
	for (int first=0;first<n;first++)
	{
		for (int second=first+1;second<n;second++)
		{
			int x= perm[first];
			int y= perm[second];
			if (constraints[y][x]) return false;
		}
	}
	return true;
}



int main()
{
	// printvec(availNums);
	// n=5;
	
	cin>>n>>k;

	while (k--)
	{
		int x,y;
		cin>>x>>y;
		constraints[x][y]=true;
	}


	recurse(0);

	print(permNum);

	return 0;
}