#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string sentences;
	while(cin >> sentences)
	{
		if(sentences == "0")
			return 0;
			
		int answer{0};
		while(true)
		{
			for(char c: sentences)	
				answer += c - '0';
			
			if(answer >= 10)
			{
				sentences.clear();
				while(answer != 0)
				{
					sentences += (answer % 10) + '0';
					answer /= 10;
				}
			}
			else
				break;
		}
		cout << answer << '\n';
	}
}