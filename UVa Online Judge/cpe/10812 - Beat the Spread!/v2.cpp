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

        if(total < difference || (total + difference) % 2 == 1)//先排除所有impossible的可能
        {
            cout << "impossible\n";
			continue;
        }

		a = (total + difference) / 2;//二元聯立方程式
		b = a - difference;

		cout << a << ' ' << b << '\n';
	}
}