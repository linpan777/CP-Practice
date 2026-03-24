#include <iostream>
#include <string>
using namespace std;

// 6 個國家的列表，與下面的 girl 計數陣列一一對應
const string country[6] = {"England", "France", "Germany", "Italy", "Turkey", "Spain"};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	// 統計每個國家出現的次數
	int girl[6] = {0};
	
	int T; 
	cin >> T;
	cin.ignore(); // 關鍵：清除 cin >> T 後緩衝區的換行符，避免 getline 讀取錯誤
	
	// 讀取 T 筆征服記錄
	while(T--)
	{
		string list;
		getline(cin, list); // 讀取一整行記錄 (格式: "國家 ...人名...")
		
		// 根據國家名稱的首字母來計數
		switch(list[0])
		{
			case 'E': // England
				girl[0]++;
				break;
			case 'F': // France
				girl[1]++;
				break;
			case 'G': // Germany
				girl[2]++;
				break;
			case 'I': // Italy
				girl[3]++;
				break;
			case 'T': // Turkey
				girl[4]++;
				break;
			case 'S': // Spain
				girl[5]++;
				break;
		}
	}
	
	// 輸出所有出現過的國家及其征服人數（按照預設的國家順序）
	for(int i{0}; i < 6; i++)
		if(girl[i] != 0)
			cout << country[i] << ' ' << girl[i] << '\n';
}