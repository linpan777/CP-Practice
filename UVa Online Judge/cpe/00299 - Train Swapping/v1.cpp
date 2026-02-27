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

	cin >> T;//測資數
	for (int i{ 0 }; i < T; i++)
	{
		carriages.clear();//每一次測資都要清空車廂vector
		times = 0;//每一次測資要清空次數
		
		cin >> C;//車廂數
		for (int k{ 0 }; k < C; k++)//cin車廂初始排序
		{

			cin >> temp;
			carriages.push_back(temp);
		}

		int j{ 0 };
		while (j < C - 1)//core code(類氣泡排序法，但是每次偵測到條件內容就從頭檢測)
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
