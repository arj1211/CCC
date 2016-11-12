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
#define lenn size()
#define newln debug("")
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)>(y)?(y):(x)


////Stone Pile
//vI stones, pile1, pile2;
//int N, sum=999999;
//
//int sumOf(vI vec)
//{
//	int sum;
//	for (int i:vec)
//		sum+=i;
//	return sum;
//}
//
//void subsets(vI pile1, vI pile2, int stoneInd, int prevSum=9999)
//{
//	if (pile1.lenn + pile2.lenn == N)
//	{
//		prevSum=min(sumOf(pile1),sumOf(pile2));
//		if (prevSum<sum) sum=prevSum;
//		return;
//	}
//	pile1.pbb(stones[stoneInd+1]);
//	subsets(pile1,pile2,stoneInd+1,prevSum);
//	pile1.pop_back();
//	pile2.pbb(stones[stoneInd+1]);
//	subsets(pile1,pile2,stoneInd+1,prevSum);
//	pile2.pop_back();
//
//}
//
//
//
//// int stoneDiff(vI pile1, vI pile2)
//// {
//// 	// if (pile1.lenn<1) return pile2[0];
//// 	// if (pile2.lenn<1) return pile1[0];
//
//// 	sort(begin(pile1),end(pile2));
//// 	return (abs(pile1[0]-pile2[0]));
//// }
//// void pile(int stoneInd, int weightDiff=0)
//// {
//// 	if ( (pile1.lenn + pile2.lenn ) == N)
//// 		{
//// 			weightDiff=stoneDiff(pile1,pile2);
//// 			weights.pbb(weightDiff);
//// 			return;
//// 		}
//	
//// 	pile1.pbb(stones[stoneInd]);
//
//// }
//
//


int arr[22];//larger size for '1' natural indexing
set<int> diff;
int totalWeight, pile1weight = 0, pile2weight = 0, N;

void pile(int stoneInd, int pile1weight, int pile2weight)
{
	if (stoneInd == N + 1)//if we've reached one-past last stone...
	{
		diff.insert(abs(pile1weight - pile2weight));//insert the difference between the two groups into the difference set
		return;
	}
	//if we haven't used up all the stones...
	pile(stoneInd + 1, pile1weight + arr[stoneInd], pile2weight);//either stone goes in pile 1
	pile(stoneInd + 1, pile1weight, pile2weight + arr[stoneInd]);//or in pile 2
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int inp;
		cin >> inp;
		arr[i] = inp;
	}
	pile(1, 0, 0);
	//sort(diff.begin(), diff.end());

	print(*diff.begin());//first elem in set is least difference
	pause;
	return 0;
}