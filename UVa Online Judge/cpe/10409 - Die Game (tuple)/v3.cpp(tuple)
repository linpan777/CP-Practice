#include <iostream>
#include <string>
#include <tuple>  // 【v3 新增】使用 tuple 進行同步賦值
using namespace std;

// 【v3 改進】存儲所有6個面，避免計算推導，直接進行交換
struct Die{
    int up = 1, down = 6;
    int north = 2, south = 5;
    int west = 3, east = 4;
};

void dieSimulate(const char direction, Die &mydie);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	while(cin >> T)
	{
		if(T == 0)
			return 0;
			
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
    temp = mydie.up;  // 此行在v3中已經不必要，但保留相容性
	switch(direction)
	{
		case 'n':
			// 【v3 改進】使用 tie + make_tuple 同時交換4個相關的面
			// 骰子向北：南→上, 上→北, 北→下, 下→南
			tie(mydie.up, mydie.north, mydie.down, mydie.south) 
            = make_tuple(mydie.south, mydie.up, mydie.north, mydie.down);
			break;
		case 's':
			// 【v3 改進】北→上, 下→北, 南→下, 上→南
			tie(mydie.up, mydie.north, mydie.down, mydie.south) 
            = make_tuple(mydie.north, mydie.down, mydie.south, mydie.up);
			break;
		case 'e':
			// 【v3 改進】西→上, 上→東, 東→下, 下→西
			tie(mydie.up, mydie.east, mydie.down, mydie.west) 
            = make_tuple(mydie.west, mydie.up, mydie.east, mydie.down);
			break;
		case 'w':
			// 【v3 改進】東→上, 下→東, 西→下, 上→西
			tie(mydie.up, mydie.east, mydie.down, mydie.west) 
            = make_tuple(mydie.east, mydie.down, mydie.west, mydie.up);
			break;
	}
}

/*
 * 【方法說明】
 * v3 使用「tuple 同時賦值」的方式：
 * - 存儲所有6個面，避免「7 - value」的計算推導
 * - 使用 tie() = make_tuple() 進行原子性的同時交換
 * - 優點：邏輯清晰直觀，易於理解交換規則，無需心智負擔推導
 * - 缺點：記憶體使用同 v1（6個變數）
 */