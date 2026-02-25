#include<iostream>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string sentence;
	char now = ' ';

	while (getline(cin, sentence))
	{
		for(int i{0}; i < sentence.size(); i++)
			if (sentence[i] == '"')
			{
				if(now == '`')
				{
						sentence[i] = '\'';
						sentence.insert(i + 1, "\'");
						now = '\'';
				}
				else
				{
					sentence[i] = '`';
					sentence.insert(i + 1, "`");
					now = '`';
					for (int j{ i + 1 }; j < sentence.size(); j++)
						if (sentence[j] == '"')
						{
							sentence[j] = '\'';
							sentence.insert(j + 1, "\'");
							now = '\'';
							i = j;
							break;
						}
				}
			}
		cout << sentence << '\n';
	}
}
