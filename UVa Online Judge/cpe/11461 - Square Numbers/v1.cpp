#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int first, last;
	
	while(cin >> first >> last)
	{
		int count{0};
		if(first == 0 && last == 0)
			return 0;
			
		for(int i{first}; i <= last; i++)
		{
			int number = sqrt(i);
			if(number * number == i)
				count++;
		}
		cout << count << '\n';
	}
}