// 骰子遊戲 - 根據方向旋轉骰子並輸出最終朝上的數字
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 函數聲明：根據方向旋轉骰子
void dieSimulate(const char direction, int &up);

// 全域變數：骰子的六個面（初始狀態：1朝上，6朝下，2朝北，5朝南，4朝東，3朝西）
int up{1}, down{6}, north{2}, south{5}, east{4}, west{3};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	
	// 外層迴圈：不斷讀取測試用例
	while(cin >> T)
	{
		if(T == 0)  // 當T為0時，表示測試結束
			return 0;
		
		// 重置骰子的初始狀態
		up = 1; down = 6; north = 2; south = 5; east = 4; west = 3;
		string direction;
		
		// 內層迴圈：執行T次操作
		for(int i{0}; i < T; i++)
		{	
			cin >> direction;
			// 根據輸入的方向字元旋轉骰子
			dieSimulate(direction[0], up);
		}
		// 輸出最終朝上的面的數字
		cout << up << '\n';
	}
}

// 骰子旋轉模擬函數
// 參數說明：direction - 旋轉方向（'n'北、's'南、'e'東、'w'西），up - 當前朝上的面（參考傳遞）
void dieSimulate(const char direction, int &up)
{
	int temp = 0;  // 臨時變數，用於交換骰子各面的值
	
	switch(direction)
	{
		case 'n':  // 骰子向北翻滾
			temp = up;
			up = south;      // 南面變成朝上
			south = down;    // 下面變成朝南
			down = north;    // 北面變成朝下
			north = temp;    // 原朝上面變成朝北
			break;
			
		case 's':  // 骰子向南翻滾
			temp = up;
			up = north;      // 北面變成朝上
			north = down;    // 下面變成朝北
			down = south;    // 南面變成朝下
			south = temp;    // 原朝上面變成朝南
			break;
			
		case 'e':  // 骰子向東翻滾
			temp = up;
			up = west;       // 西面變成朝上
			west = down;     // 下面變成朝西
			down = east;     // 東面變成朝下
			east = temp;     // 原朝上面變成朝東
			break;
			
		case 'w':  // 骰子向西翻滾
			temp = up;
			up = east;       // 東面變成朝上
			east = down;     // 下面變成朝東
			down = west;     // 西面變成朝下
			west = temp;     // 原朝上面變成朝西
			break;
	}
}
