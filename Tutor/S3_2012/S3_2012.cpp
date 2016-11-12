#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

//*   <--- My own comments

#define debug(x) cout << (x) << endl;
#define debug2(x,y) cout << (x) << " " << (y) << endl;
#define debug3(x,y,z) cout << (x) << " " << (y) << " " << (z) <<  endl;
#define debug4(x,y,z,q) cout << (x) << " " << (y) << " " << (z) << " " << (q) <<  endl;

#define fast_input ios::sync_with_stdio(0);cin.tie(0)
//MAKE INPUT WAY FASTER, BUT ONLY IF YOURE USING C++ I/O ONLY --> ios::sync_with_stdio(false);
//TIME clock_t start = clock(); cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;

int n, temp, cases;
vector< pair<int, int> > nums;

int main()
{
	//* for all possible readings (1-1000), 
	//*initialize the freq to 0, and add this pair to vector
	for (int i = 1; i <= 1000; i++)
	{
		pair<int, int> p;
		p.first = 0; p.second = i;
		nums.push_back(p);
	}
	//ifstream in("acidic.txt");

	//*take in the number of sensors
	cin >> n; cases = n;
	while (cases--) //*=while(cases>0){...........cases--;}
	{//*for each sensor reading inputted, increase teh freq of it in the vector by 1
		cin >> temp;
		nums[temp - 1].first++;
	}
	//*sort the vvector by freq, then reverse so the greatest freq is at index 0
	sort(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	//for (int i = 0; i < 10;i++)
	// cout << nums[i].first << " " << nums[i].second << endl;
	
	//More than 2 most frequent reading
	if (nums[0].first == nums[1].first) //*if there are 2 readings with highest freq...
	{
		int maxi = nums[0].second, mini = nums[0].second, j = 1;//*init variables. 'maxi' will be larger of the two readings, and variable j is set to 1; will be used as an index
		while (j < nums.size() && nums[j].first == nums[0].first)//*in the bounds of the vector, and while the 'current' reading's freq is the same as the largest freq (readings at index 0)...
		{//*trying to find the largest difference possible between readings...
			if (nums[j].second > maxi) maxi = nums[j].second;//*if the 'current' reading is greater than the current 'maximum reading', re-assign the maximum to the 'current' reading
			if (nums[j].second < mini) mini = nums[j].second;//*if the 'current' reading is less than the current 'minimum reading', re-assign the current minimum to the 'current' reading
			j++;
		}//* at the end of this while loop, maxi is the greatest reading with the highest freq, and mini is the smallest reading with the highest freq; ensuring the greatest possible difference between readings.
		cout << maxi - mini << endl; //*output the difference; end of problem.
	}
	else //*if there ARENT 2 readings with the highest freq...
	{
		int maxi = nums[0].second, best_d = 0, j = 1;//*variable maxi is the reading with the highest freq. best_d is the best difference (greatest difference we can find), initiallized to 0. variable j is set to 1, and will be used for indexing
		while (nums[j].first == nums[1].first)//*while the 'current' reading has the same freq as the first second-highest reading...
		{
			if (abs(maxi - nums[j].second) > best_d)//*if the absolute difference between the reading with the highest freq (maxi) and the 'current' reading, is GREATER than the 'best difference' (largest difference possible between two readings),
				best_d = abs(maxi - nums[j].second);//*re-assign the 'best difference' to this difference
			j++;
		}//*at the end of the while loop, 'best_d' is the greatest possible difference between the reading with the highest freqency, and a reading with the second-highest frequency (i.e. the difference between the reading with highest freq, and smallest value reading with the second-highest freq).
		cout << best_d << endl;//*output the difference; end of problem.
	}

}

