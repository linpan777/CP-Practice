#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

map<char, char>decode{{'d', 'a'}, {'m', 'b'}, {'b', 'c'}, {'g', 'd'}, {'t', 'e'}, {'h', 'f'}, {'j', 'g'},
					{'k', 'h'}, {'p', 'i'}, {'l', 'j'}, {';', 'k'}, {'\'', 'l'}, {'.', 'm'}, {',', 'n'},
					{'[', 'o'}, {']', 'p'}, {'e', 'q'}, {'y', 'r'}, {'f', 's'}, {'u', 't'}, {'o', 'u'},
					{'n', 'v'},{'r', 'w'}, {'v', 'x'}, {'i', 'y'}, {'c', 'z'}, {' ', ' '}};
						
string sentences;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	
	while(getline(cin, sentences))
	{
		for(char c: sentences)
		{
			if(isupper(c))
				c = tolower(c);
			
			cout << decode[c];
		}
		cout << '\n';
	}
}