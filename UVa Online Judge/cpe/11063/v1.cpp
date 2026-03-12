#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	int number, temp, Case{1};
	
	while(cin >> number)
	{
		bool B2 = true;
		int stores[100] = {0};
		int answer[20000] = {0};
		for(int i{0}; i < number; i++)
		{
			cin >> temp;
			stores[i] = temp;
		}
		
		for(int i{0}; i < number; i++)
			for(int j{i}; j < number; j++)
				if(answer[stores[i] + stores[j]] > 0)
					B2 = false;
				else
				{
					answer[stores[i] + stores[j]]++;
					continue;
				}
					
		if(B2)
			cout << "Case #" << Case++ << ": It is a B2-Sequence.\n\n";
		else
			cout << "Case #" << Case++ << ": It is not a B2-Sequence.\n\n";
	}
	
}