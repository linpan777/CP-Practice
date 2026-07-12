#include <iostream>
#include <string>
using namespace std;

string origin = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
string Switch = "=`1234567890-\\QWERTYUIOP[]'ASDFGHJKL;/ZXCVBNM,.";
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string input;
	getline(cin, input);
	for(char c: input)
	{
		if(c == ' ')
		{
			cout << ' ';
			continue;
		}
		
		cout << Switch[origin.find(c)];
	}
	cout << '\n';
}