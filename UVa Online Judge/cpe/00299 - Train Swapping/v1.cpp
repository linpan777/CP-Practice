#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> carriages;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, C;
	int times{ 0 }, temp{ 0 };

	cin >> T;
	for (int i{ 0 }; i < T; i++)
	{
		carriages.clear();
		cin >> C;
		for (int k{ 0 }; k < C; k++)
		{

			cin >> temp;
			carriages.push_back(temp);
		}
		carriages.push_back(0);

		times = 0;
		int j{ 0 };
		while (j < C - 1)
		{
			if (carriages[j] > carriages[j + 1])
			{
				swap(carriages[j], carriages[j + 1]);
				times++;
				j = 0;
			}
			else
				j++;
		}
		cout << "Optimal train swapping takes " << times << " swaps.\n" ;
	}
}
