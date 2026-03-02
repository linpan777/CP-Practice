#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int character[26] = {};

int main()
{
	int T;
	cin >> T;

	cin.ignore();
	string sentences = {};
	int max{ 0 };
	while (T--)
	{
		getline(cin, sentences);
		for (char c : sentences)
		{
            if(isalpha(c))
            	c = toupper(c);
            else
                continue;
			character[c - 65]++;//ACSII code碼記錯
			if (max < character[c - 65])
				max = character[c - 65];
		}
	}
	for (int i{ max }; i > 0; i--)//本來寫i < 0
		for (int j{ 0 }; j < 26; j++)
			if (character[j] == i)
				cout << static_cast<char>(j + 65)
				<< ' '
				<< character[j]//原本又+65
				<< '\n';
}