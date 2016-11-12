// TIMUS JUDGE ID: 189234ZA
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
#define printarr(x,y,arr) for ((x);(x)<(y);(x)++){cout<<((arr)[x])<<' ';} newln
#define printarr2(x1,y1,x2,y2,xy) for (int x=(x1);x<(y1);x++){ for (int y=(x2);y<(y2);y++) {cout<<(((xy)[x][y]))<<' ';} newln}
#define in(x) cin>>(x);
#define in2(x,y) cin>>(x)>>(y);
#define in3(x,y,z) cin>>(x)>>(y)>>(z);
#define in4(x,y,z,a) cin>>(x)>>(y)>>(z)>>(a);
#define in5(x,y,z,a,b) cin>>(x)>>(y)>>(z)>>(a)>>(b);
#define INF 9999999

int N, K;
int horses[501], prefB[501], prefW[501];

vVI best(501, vI(501,-1) );

int coUnhap(int i, int j) //the unhappiness from horse 'i' to horse 'j' in line
{
	int wh=0,bl=0;
	wh=prefW[j]-prefW[i-1];//number of white horses in the range
	bl=prefB[j]-prefB[i-1];//number of black horses in the range
	return bl*wh;
}

// 01100010011100110001001110011000100111001100010011100110001001110011000100111001100010011100110001001110
int getBest(int i, int k)//starting horse of this group, stables left
{
	
	if (k<0) return INF; //if there are no more stables left, backtrack
	if (i==N+1) //if past the last horse...
	{
		if (k>0) return INF; //... and more stables left, backtrack
		return 0; 
	} 

	if (best[i][k]!=-1) return best[i][k];//if already found, return

	int minTotal=INF;//sentinal for minimum coeff
	for (int j =i; j<=N-k+1; j++) //for all horses from 'i' to 'j', (i,j) being the group at each loop
	{
		int totalCo = coUnhap(i,j)+getBest(j+1,k-1); //calculate the unhappiness coefficient from this current potential stable (horse group containing horses 'i' to 'j'), to the rest to follow
		if (totalCo<minTotal) minTotal=totalCo; // if its smaller than our current minimum, make a new minimum unhappiness coeff
	}
//	debug3(i,k,minTotal);
	return best[i][k]=minTotal;
}

int main()
{
	in2(N,K);

	prefW[0]=0,prefB[0]=0;
	for (int w=1;w<=N;w++)
	{
		in(horses[w]);
		if (horses[w]==0)//if inputted horse is white
		{
			prefW[w]=prefW[w-1]+1;//increment number of white horses up till this point
			prefB[w]=prefB[w-1];//keep number of black horses up till this point the same

		}
		else //vice-versa..
		{
			prefW[w]=prefW[w-1];
			prefB[w]=prefB[w-1]+1;
		}
	}

	print(getBest(1,K));//get minimum coeff unhappiness by grouping horses starting at horse 1, with all available stables initially

	return 0;
}

// 2 5 1 6 8 4 5 9 7
// 2 7 8 

//1167. Bicolored Horses
//Time limit : 1.0 second
//Memory limit : 64 MB
//Every day, farmer Ion(this is a Romanian name) takes out all his horses, so they may run and play.When they are done, farmer Ion has to take all the horses back to the stables.In order to do this, he places them in a straight line and they follow him to the stables.Because they are very tired, farmer Ion decides that he doesn't want to make the horses move more than they should. So he develops this algorithm: he places the 1st P1 horses in the first stable, the next P2 in the 2nd stable and so on. Moreover, he doesn't want any of the K stables he owns to be empty, and no horse must be left outside.Now you should know that farmer Ion only has black or white horses, which don't really get along too well. If there are i black horses and j white horses in one stable, then the coefficient of unhappiness of that stable is i*j. The total coefficient of unhappiness is the sum of the coefficients of unhappiness of every of the K stables.
//Determine a way to place the N horses into the K stables, so that the total coefficient of unhappiness is minimized.
//Input
//On the 1st line there are 2 numbers : N(1 ≤ N ≤ 500) and K(1 ≤ K ≤ N).On the next N lines there are N numbers.The i - th of these lines contains the color of the i - th horse in the sequence : 1 means that the horse is black, 0 means that the horse is white.
//Output
//You should only output a single number, which is the minimum possible value for the total coefficient of unhappiness.
//Sample
//input	output
//6 3
//1
//1
//0
//1
//0
//1
//2
//Notes
//Place the first 2 horses in the first stable, the next 3 horses in the 2nd stable and the last horse in the 3rd stable.