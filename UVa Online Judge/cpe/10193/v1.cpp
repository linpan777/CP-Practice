#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int Case{1};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, a{0}, b{0};
	string first, second;
	
	
	cin >> T;
	while(T--)
	{
		cin >> first >> second;
		a = stoi(first, nullptr, 2);
		b = stoi(second, nullptr, 2);
		
		if(a < b)
				swap(a, b);
				
		while(b != 0)//a b搞錯
		{				
			a %= b;
			if(a < b)
				swap(a, b);
		}
		
		if(a > 1)
			cout << "Pair #" << Case++ << ": All you need is love!\n";
		else
			cout << "Pair #" << Case++ << ": Love is not all you need!\n";
	}
}
