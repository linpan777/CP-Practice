#include<iostream>
using namespace std;

int fib[501] = {1, 2};

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		cout << n << " = ";
		
		if(n == 1)
		{
			cout << 1 << " (fib)\n";
			continue;
		}
		else if(n == 2)
		{
			cout << 10 << " (fib)\n";
			continue;
		}
			
		int i{0};
		while(n >= fib[i + 1])
		{
			fib[i + 2] = fib[i] + fib[i + 1];
			i++;
		}
		n -= fib[i];
		cout << 1;
		
		for(int j{i - 1}; j >= 0; j--)
			if(fib[j] > n)
				cout << 0;
			else
			{
				n -= fib[j];
				cout << 1;
			}
				
		cout << " (fib)\n";
	}
}
