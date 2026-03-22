#include <iostream>
using namespace std;

int binary(int M);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int M;
		cin >> M;
		
		int b1 = __builtin_popcount(M), b2{0};
		
		while(M != 0)
		{
			b2 += __builtin_popcount(M % 10);
			M /= 10;
		}
		
		cout << b1 << ' ' << b2 << '\n';
	}
}
