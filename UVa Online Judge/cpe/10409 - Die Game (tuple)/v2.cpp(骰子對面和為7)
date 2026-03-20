#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 【v2 改進】用結構體取代全域變數，更好的資料組織
struct Die{
    int up = 1;      // 朝上的面
    int north = 2;   // 朝北的面
    int west = 3;    // 朝西的面
    // 注意：只存3個面，其他3個面利用對面和為7推導（下=7-up, 南=7-north, 東=7-west）
};

// 【v2 改進】改為結構體參數，而非單個整數參數
void dieSimulate(const char direction, Die &mydie);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	while(cin >> T)
	{
		if(T == 0)
			return 0;
		
		// 【v2 改進】用結構體實例取代全域變數重置，更清晰
        Die mydie;
		string direction;
		
		for(int i{0}; i < T; i++)
		{	
			cin >> direction;
			dieSimulate(direction[0], mydie);
		}
		cout << mydie.up << '\n';
	}
}

void dieSimulate(const char direction, Die &mydie)
{
	int temp = 0;
    temp = mydie.up;
	switch(direction)
	{
		case 'n':
			// 【v2 改進】利用對面和為7：下面(7-north)變朝上，原朝上變朝北
			mydie.up = 7 - mydie.north;
			mydie.north = temp;
			break;
		case 's':
			// 【v2 改進】北面變朝上，原朝上的對面(7-up=下面)變朝北
			mydie.up = mydie.north;
			mydie.north = 7 - temp;
			break;
		case 'e':
			// 【v2 改進】西面變朝上，原朝上的對面(下面)變朝西
			mydie.up = mydie.west;
			mydie.west = 7 - temp;
			break;
		case 'w':
			// 【v2 改進】東面(7-west)變朝上，原朝上變朝西
			mydie.up = 7 - mydie.west;
			mydie.west = temp;
			break;
	}
}

/*
  【方法說明】
  v2 使用「骰子對面和為7」的性質：
  - 只維護3個面（up, north, west）
  - 其他3個面可推導：down=7-up, south=7-north, east=7-west
  - 優點：記憶體更少、程式碼更簡潔
 */