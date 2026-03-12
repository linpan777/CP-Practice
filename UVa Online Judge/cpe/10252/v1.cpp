#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string first, second;
	while(getline(cin, first) && getline(cin, second))//？？？？？？？？？?
	{	
		int letter1[26] = {0};
		int letter2[26] = {0};
		int less{0};
		
		if(first == " " && second == " ")
		{
			cout << '\n';
			continue;
		}
		
		for(char c: first)
			letter1[c - 'a']++;
		
		for(char c: second)
			letter2[c - 'a']++;
			
		for(int i{0}; i < 26; i++)
			if(letter1[i] >= 1 && letter2[i] >= 1)
			{
				less = min(letter1[i], letter2[i]);
				for(int j{0}; j < less; j++)
					cout << (char)(i + 'a');
			}
				
		cout << '\n';
	}
}