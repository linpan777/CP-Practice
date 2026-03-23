#include <iostream>
using namespace std;

int binary(int M);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int M;
		cin >> M;
		
		// v2 優化: 直接使用 C++ 內建的 __builtin_popcount() 函式計算 b1
		// 這個函式利用硬體指令，效能遠超 v1 的手刻迴圈
		int b1 = __builtin_popcount(M), b2{0};
		
		// v2 優化: 計算 b2 的邏輯完全改變
		// v1 是先把整串數字轉成真實的十進位，再算二進位
		// v2 利用十六進位與二進位的特性，將數字的每一位數拆開，單獨計算該位數的 popcount 再加總
		// 這樣做完全避免了 v1 中危險的 pow() 函式，也更有效率
		while(M != 0)
		{
			b2 += __builtin_popcount(M % 10);
			M /= 10;
		}
		
		cout << b1 << ' ' << b2 << '\n';
	}
}
