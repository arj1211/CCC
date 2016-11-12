#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//WORKING NOW


int n, m;

vector< vector<int> > sizes, boxes;

bool v_sort(vector<int> a, vector<int> b)
{
	int av = a[0] * a[1] * a[2];
	int bv = b[0] * b[1] * b[2];
	return av < bv;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, w, h;
		cin >> l;
		cin >> w;
		cin >> h;
		vector<int> thismyvec = { l, w, h };
		sort(thismyvec.begin(), thismyvec.end());
		sizes.push_back(thismyvec);
	}

	/*

	DEBUG PURPOSES:

	cout << "sizes: " << endl;
	for (vector<int> i : sizes)
	{
	cout << "[";
	for (int j : i)
	cout << j << ' ';
	cout << "]";
	}
	cout << endl;

	*/

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int l, w, h;
		cin >> l;
		cin >> w;
		cin >> h;
		vector<int> thismyvec = { l, w, h };
		sort(thismyvec.begin(), thismyvec.end());
		boxes.push_back(thismyvec);
	}


	/*

	DEBUG PURPOSES:

	cout << "boxes: " << endl;
	for (vector<int> i : boxes)
	{

	cout << "[";
	for (int j : i)
	cout << j << ' ';
	cout << "]";
	cout << endl;
	}

	*/



	//sort the presets, so we look at smallest first later...
	sort(sizes.begin(), sizes.end(), v_sort);
	// DONT SORT THE ACTUAL BOXES, THEIR ORDER IS IMPORTANT

	for (int count = 0; count < m; count++) // 'count' is the current box
	{// current box in question...
		for (int cc = 0; cc < n; cc++) // 'cc' is the current box size preset
		{// checking if this box adheres to any of the preset sizes available
			if (boxes[count][0] <= sizes[cc][0]
				&& boxes[count][1] <= sizes[cc][1]
				&& boxes[count][2] <= sizes[cc][2]
				&& (boxes[count][0] * boxes[count][1] * boxes[count][2])
				<= (sizes[cc][0] * sizes[cc][1] * sizes[cc][2]))
			{
				cout << sizes[cc][0] * sizes[cc][1] * sizes[cc][2] << endl;
				break;
			}
			if (cc == n - 1)
				cout << "Item does not fit." << endl;
		}
	}
	system("pause");
}