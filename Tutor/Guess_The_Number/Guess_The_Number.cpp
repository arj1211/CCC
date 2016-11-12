#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

#define debug(x) cout << (x) << endl;
#define debug2(x,y) cout << (x) << " " << (y) << endl;
#define debug3(x,y,z) cout << (x) << " " << (y) << " " << (z) <<  endl;
#define debug4(x,y,z,q) cout << (x) << " " << (y) << " " << (z) << " " << (q) <<  endl;
#define fast_input ios::sync_with_stdio(0);cin.tie(0)
#define pause system("pause")
#define pbb push_back
#define printvec(vec) for(auto i:vec){ cout<<i<<" ";}cout<<endl;
#define printvec2(vec2) for(auto i:vec2)for(auto k: i){ cout<<k<<" ";}cout<<endl;

#define MAX 2*pow(10,9)

//SEEMS TO BE WORKING (cant submit)
int main()
{
	unsigned long guess;
	string response;
	int max = MAX, min = 1;
	while (1)
	{
		guess = (max + min) / 2;
		cout << guess << endl; // endl automatically flushes in C++ 
		cin >> response;
		if (response == "Lower")
		{
			max = guess - 1;
		}
		else if (response == "Higher")
		{
			min = guess + 1;
		}
		else if (response == "OK")
		{
			break;
		}
	}
	return 0;
}