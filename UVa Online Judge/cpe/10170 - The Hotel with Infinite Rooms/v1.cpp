#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	long long int people, day;
	while(cin >> people >> day)
	{
		while(true)
		{
			day -= people;
			if(day <= 0)
				break;
			else
				people++;
		}
		cout << people << '\n';
	}
}