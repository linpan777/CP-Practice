#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, day, parties, f;
	
	cin >> T;
	while(T--)
	{	
		bool hartal[3651] = {false};//提前宣告好，利用boolen最終有多少true來做計算，避免重複紀錄
		int count{0};
		
		cin >> day;
		cin >> parties;
		
		for(int i{0}; i < parties; i++)
		{
			cin >> f;
			for(int j{1}; j <= day/f; j++)//關鍵在天數/罷工週期=該團體總共的罷工天數，由於題目必從1號開始，因此*變化的j就是日期
				hartal[f * j] = true;
		}
		
		for(int i{0}; i <= day; i++)
			if(hartal[i] == true && i % 7 != 6 && i % 7 != 0)//排除週五以及周六
				count++;
				
		cout << count << '\n';
	}
}	