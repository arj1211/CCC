#include <iostream>
#include <set>
#include <vector>

// WORKING (used to use map, now uses set)

using namespace std;

int main(void)
{
	char direction;
	int length;


	set< pair<int, int> > spot;



	// {x, y} = t/f
	// init pre-existing plan
	spot.insert({ 0, -1 });
	spot.insert({ 0, -2 });
	spot.insert({ 0, -3 });
	spot.insert({ 1, -3 });
	spot.insert({ 2, -3 });
	spot.insert({ 3, -3 });
	spot.insert({ 3, -4 });
	spot.insert({ 3, -5 });
	spot.insert({ 4, -5 });
	spot.insert({ 5, -5 });
	spot.insert({ 5, -4 });
	spot.insert({ 5, -3 });
	spot.insert({ 6, -3 });
	spot.insert({ 7, -3 });
	spot.insert({ 7, -4 });
	spot.insert({ 7, -5 });
	spot.insert({ 7, -6 });
	spot.insert({ 7, -7 });
	spot.insert({ 6, -7 });
	spot.insert({ 5, -7 });
	spot.insert({ 4, -7 });
	spot.insert({ 3, -7 });
	spot.insert({ 2, -7 });
	spot.insert({ 1, -7 });
	spot.insert({ 0, -7 });
	spot.insert({ -1, -7 });
	spot.insert({ -1, -6 });
	spot.insert({ -1, -5 });


	pair<char, int> line;

	bool check = false;
	int x = -1, y = -5;


	while (cin >> line.first && line.first != 'q')
	{
		cin >> line.second;
		int dirX = 0, dirY = 0;

		if (line.first == 'l')
		{
			//x -= line.second;
			dirX = -1;
		}
		else if (line.first == 'r')
		{
			//x += line.second;
			dirX = 1;
		}
		else if (line.first == 'd')
		{
			//y -= line.second;
			dirY = -1;
		}
		else if (line.first == 'u')
		{

			dirY = 1;
		}

		//x,y is the spot in question

		int dist = line.second;

		while (dist--)
		{
			x += dirX;
			y += dirY;

			if (spot.count({ x, y }) == 1) check = true;
			else spot.insert({ x, y });
		}

		if (check)
		{
			cout << x << ' ' << y << ' ' << "DANGER" << endl;
			break;
		}
		else
			cout << x << ' ' << y << ' ' << "safe" << endl;




	}
}