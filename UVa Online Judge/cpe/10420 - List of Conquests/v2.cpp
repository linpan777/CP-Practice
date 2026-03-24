#include <iostream>
#include <string>
#include <map>
// v2 優化：使用 map 來自動儲存和排序國家計數，而不是預先定義的陣列
using namespace std;

// v2 優化：使用 map<string, int> 來動態儲存所有國家及其計數
// key = 國家名稱 (string)，value = 征服人數 (int)
// map 會自動根據 key 進行字母順序排序
map<string, int> list;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	int T; 
	cin >> T;
	cin.ignore(); // 清除換行符
	
	while(T--)
	{
		string country, girl;
		
		// v2 優化：直接用 cin >> country 讀取國家名稱（第一個單字）
		// 相比 v1 的 getline 和 switch 判斷，這樣更直接且避免首字母判斷的問題
		cin >> country;
		
		// 讀取剩餘部分（人名等）但不使用，只為了清除該行輸入
		getline(cin, girl);
		
		// v2 優化：直接用 map 的 [] 運算子自動計數
		// 如果 country 是第一次出現，map 會自動為它建立值 0 並遞增到 1
		// 無需 switch 判斷和陣列對應
		list[country]++;
	}
	
	// v2 優化：直接遍歷 map，輸出所有國家及其計數
	// map 自動按字母順序排序，符合題目輸出要求
	for(auto it: list)
		cout << it.first << ' ' << it.second << '\n';
}

/*
### v2 作法說明

**優化核心：使用 std::map 取代預定義陣列**

相比 v1 的問題：
1. v1 只能判斷國家的首字母，若有多個國家首字母相同則會混淆（如 Spain 和 Sweden）
2. v1 使用 switch 和預定義陣列，擴充性差、容易出錯

v2 的改進：
1. **直接讀取國家名稱**：使用 `cin >> country` 讀取第一個單字，精確獲得完整國家名稱
2. **動態儲存**：使用 `map<string, int>` 自動建立和計數，無需預先定義所有國家
3. **自動排序**：map 會自動按照字母順序排序鍵值，輸出時無需額外排序
4. **簡潔計數**：`list[country]++` 一行完成計數，語法清晰簡潔

時間複雜度：$O(n \log k)$，其中 $n$ 是記錄筆數，$k$ 是不同國家的個數
空間複雜度：$O(k)$，其中 $k$ 是不同國家的個數
*/