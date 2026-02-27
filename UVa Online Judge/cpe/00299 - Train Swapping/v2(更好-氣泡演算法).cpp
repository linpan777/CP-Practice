#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int T;
	cin >> T;

	while(T--)
	{
		vector<int> carriages;//優化-將vector宣告進每一次測資迴圈
		int C, temp, times{ 0 };//times也要放在迴圈裡面，每一次測資都要重置次數
		cin >> C;//input車廂數
		for(int i{0}; i < C; i++)//input車廂初始排序
		{
			cin >> temp;
			carriages.push_back(temp);
		}

        //core code，氣泡排序法
		for(int i{0}; i < C - 1; i++)
			for (int j{ 0 }; j < C - 1; j++)
				if (carriages[j] > carriages[j + 1])
				{
					swap(carriages[j], carriages[j + 1]);
					times++;
				}
		cout << "Optimal train swapping takes " << times << " swaps.\n";//output
	}
}