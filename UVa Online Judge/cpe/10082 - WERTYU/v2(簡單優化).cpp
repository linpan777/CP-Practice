#include <iostream>
#include <string>
using namespace std;

string origin = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string input;
	while(getline(cin, input))
	{
		for(char c: input)
		{
			if(c == ' ')
			{
				cout << ' ';
				continue;
			}
			
			cout << origin[origin.find(c) - 1];
		}
		cout << '\n';
	}
	
}