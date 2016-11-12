#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
using namespace std;
//WORKING
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
#define vp(x) vector<pair<x,x > >

vpI planets; // {fuel consumption amount, fuel refill amount}
int N,P,maxFuel,maxPlanets;
/*
	'N' : number of planets
	'P' : initial planet; the one team star fox starts on
	'maxFuel' : the maximum amount of fuel the team has ever held in their tank
	'maxPlanets' : the maximum number of planets the team visited
*/

int main()
{
	cin >> N >> P;

	for (int j=1;j<=N;j++) // for all planets from #1 to #N inclusive (no #0 planet, thats why 'j' starts at 1)
	{
		int a,b; //'a': fuel cells a planet contains. 'b': the fuel that will be consumed to get to the planet
		cin >> a>>b;
		if (j==P) //if this current planet is the one we're starting on (ie. already on)...
		{
			b=0; // set the consumptin amount to 0; it takes no fuel to get to this planet, we're already on it
		}
		if (a-b < 0 && j!=P) continue; // if the planet is not worth going to, skip it (if it has a negative 
										//fuel profit; costs more fuel to get there than the fuel it gives us. if it has 
										//a 0 fuel profit, we can still visit it to maximize the # of planets we can go to in total)
		planets.pbb({b,-a}); // if the planet IS worth going to, add it to the list of planets. 
								//Add the planet's {fuel consumption to get there, fuel amount that it gives us} as a 
								//pair IN THAT ORDER, so we can later sort the planets by how much fuel it takes 
								//to get there in increasing order. Add the 'fuel cells' as a negative, so later in the sorting of
								//of the 'planets' list, if there is a tie between two planets with the same fuel consumption, it will pick the 
								//planet with the larger amount of fuel cells will be picked first (ie. the larger 'a' value, 
								//instead of the smaller 'a' value). the 'a' value will be re-negated later, so it will go back to a positive value
	}

	sort(begin(planets),end(planets));//sort the planets. first, in increasing order of fuel consumption (ie. planets that consume less fuel
										// to get to first), and the tie-breaking based on decreasing order of '#of fuel cells' 
										//(ie. planets with more fuel to offer first)

	int currFuel=0,currPlanets=0;//temporary vars to hold the amount of current fuel and planets visited
	for (int i=0;i<planets.size();i++)//for all planets that made it to the list...
	{
		int currA=-planets[i].second,currB=planets[i].first;
		//'currA': the amount of fuel cells the current planet has (re-negated, so we get |a| back, due to the sorting earlier)
		//'currB': the fuel consumption amount for the current planet
		
		//debug3("contains,usesUp: ",currA,currB);
		if (currB>currFuel) break; //if the planet's fuel consumption amount is more than the current amount of fuel we have, we can no longer 
									//visit any more planets
		currFuel+=currA-currB; //if we got here, add the net fuel-profit to the current amount of fuel we have (signifying travelling to the planet)
		currPlanets++;//we just got to another planet
		if (currFuel>=maxFuel)//if we have more/equal amount of fuel than the last recorded max amount of fuel...('equal' because we have likely 
								//visited more planets, even if we have the same amount of fuel now as the max-fuel ever recorded)
		{
			maxFuel=currFuel;//update the maximum amount of fuel we've ever had
			maxPlanets=currPlanets;//update the maximum number of planets we've ever gone to
			//debug3("maxF, maxP: ",maxFuel,maxPlanets);
		}
	}

	debug(maxFuel);
	debug(maxPlanets);

	return 0;
}