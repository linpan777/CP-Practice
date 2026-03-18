#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string N;
	while(cin >> N)
	{
		if(N == "0")
			return 0;
		
		cout << N;
		
		int can_nine{0};
		for(char c: N)
			can_nine += c - '0';
			
		if(can_nine % 9 != 0)
		{
			cout << " is not a multiple of 9.\n";
			continue;
		}
		
		int degree{1};
		while(true)
		{
			N.clear();
			while(can_nine != 0)
			{
				N += (can_nine % 10) + '0';
				can_nine /= 10;
			}
			for(char c: N)
				can_nine += c - '0';
			
			if(N == "9") break;
			else degree++;
		}
		cout << " is a multiple of 9 and has 9-degree " << degree << ".\n";
	}
}