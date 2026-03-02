#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int character[34] = {};

int main()
{
	int T;
	cin >> T;

	cin.ignore();//剛開始忘記加
	string sentences = {};
	int max{ 0 };
	while (T--)
	{
		getline(cin, sentences);
		for (char c : sentences)
		{
			if (c >= 'A' && c <= 'Z')//忘記加=
			{
				character[c - 65]++;//ACSII code碼記錯
				if (max < character[c - 65])
					max = character[c - 65];
			}
			else if (c >= 'a' && c <= 'z')
			{
				character[c - 97]++;
				if (max < character[c - 97])
					max = character[c - 97];
			}
			else
				continue;
		}
	}
	for (int i{ max }; i > 0; i--)//本來寫i < 0
		for (int j{ 0 }; j < 34; j++)
			if (character[j] == i)
				cout << static_cast<char>(j + 65)
				<< ' '
				<< character[j]//原本又+65
				<< '\n';
}