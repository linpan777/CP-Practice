#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	
	while(T--)
	{
		int total, difference, a, b;
		cin >> total >> difference;
		a = ((total + difference) % 2 == 1)? 0:(total + difference) / 2;
		b = a - difference;
		
		if(b < 0)
		{
			cout << "impossible\n";
			continue;
		}
		
		if(a < b)
			swap(a, b);
		cout << a << ' ' << b << '\n';
	}
}