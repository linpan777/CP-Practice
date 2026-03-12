#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, day, parties, f;
	
	cin >> T;
	while(T--)
	{	
		bool hartal[3651] = {false};
		int count{0};
		
		cin >> day;
		cin >> parties;
		
		for(int i{0}; i < parties; i++)
		{
			cin >> f;
			for(int j{1}; j <= day/f; j++)
				hartal[f * j] = true;
		}
		
		for(int i{0}; i <= day; i++)
			if(hartal[i] == true && i % 7 != 6 && i % 7 != 0)
				count++;
				
		cout << count << '\n';
	}
}	