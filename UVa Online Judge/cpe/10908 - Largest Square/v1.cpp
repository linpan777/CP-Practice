#include <iostream>
#include <string>
using namespace std;

void processQuery(const char square[101][101]);

int M, N;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int Q;
		cin >> M >> N >> Q;
		cout << M << ' ' << N << ' ' << Q << '\n';//預先輸出題目要求的M N Q
		
		char square[101][101];
		for(int i{0}; i < M; i++)//建表
			cin >> square[i];
		
		for(int i{0}; i < Q; i++)  // 處理 Q 次查詢
			processQuery(square);
		
	}
}

// 查詢以 (r, c) 為中心的最大同色正方形邊長
void processQuery(const char square[101][101])
{
	int r, c;
	cin >> r >> c;
	
	char goalChar = square[r][c];  // 中心點的字元
	int d{1};  // 距離中心的距離，邊長 = 2*d-1

	// 逐層向外擴大正方形，直到觸及邊界或發現不同字元
	while((r-d) >= 0 && (c-d) >= 0 && (r+d) < M && (c+d) < N)
	{
		// 檢查邊長為 2*d+1 的正方形所有格子是否都相同
		for(int i{r - d}; i <= r + d; i++)
			for(int j{c - d}; j <= c + d; j++)
				// 發現不同字元，輸出上一層的邊長並終止
				if(square[i][j] != goalChar)
				{
					cout << 2*d-1 <<'\n';
					return;
				}
		d++;  // 繼續擴大距離
	}
	// 若超出邊界，輸出最後有效的正方形邊長
	cout << 2*d-1 <<'\n';
}