// 最便宜的進位制 - 計算在不同進位制下表示數字的最小成本
#include <iostream>
using namespace std;

int price[37] = {0};  // 存儲 0-9 及 A-Z 各個數字的單位成本（總共 36 個符號）
int Case{1};          // 測試用例編號

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;  // 讀入測試用例數量
	
	while(T--)
	{
		cout << "Case " << Case++ << ":\n";
		
		// 讀入 36 個符號的單位成本（0-9 代表 0-9，A-Z 代表 10-35）
		for(int i{0}; i < 36; i++)
			cin >> price[i];
		
		int numberCase{0}, number{0};
		cin >> numberCase;  // 讀入此測試用例中有多少個要查詢的數字
		
		// 對每個要查詢的數字進行處理
		while(numberCase--)
		{
			int less = 99999999;   // 記錄最小的總成本
			int cost[37] = {0};    // 記錄該數字在各個進位制下的成本
			cin >> number;         // 讀入要轉換的數字
		
			cout << "Cheapest base(s) for number " << number << ':';
			
			// 核心邏輯：嘗試所有進位制（2 到 36）
			for(int i{2}; i <= 36; i++)
			{
				int numberTemp = number;
				
				// 將該數字轉換為進位制 i，並計算總成本
				// 過程：不斷取得 numberTemp 除以 i 的餘數（即該位數字），
				//       然後根據該數字的單位成本累加到 cost[i]
				while(numberTemp != 0)
				{
					cost[i] += price[numberTemp % i];  // 取得該位的數字，加入對應的成本
					numberTemp /= i;                   // 向下移動一位
				}
				
				// 更新目前找到的最小成本
				if(less > cost[i])
					less = cost[i];
			}
			
			// 輸出所有成本最低的進位制
			for(int i{2}; i <= 36; i++)
				if(cost[i] == less)
					cout << ' ' << i;
			cout <<'\n';
		}
		
		// 若還有更多測試用例，輸出空行作為分隔
		if(T != 0)
			cout << '\n';	
	}
}

/*
 * 【方法說明】
 * 此題採用「窮舉法」（Brute Force）：
 * - 對每個查詢的數字，嘗試所有可能的進位制（2 到 36）
 * - 對於每個進位制，使用進位制轉換原理：不斷對該進位制取餘數與商
 *   來取得每一位的數字值，根據該數字的單位成本累加
 * - 找出成本最低的進位制
 * - 時間複雜度：O(log N) 用於單一進位制轉換，O(35 × log N) 用於嘗試所有進位制
 */