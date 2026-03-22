#include <iostream>
#include <cmath>
using namespace std;

int binary(int M);
int hex(int M);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int M;
		cin >> M;
		
		int b1 = binary(M);
		
		int b2 = binary(hex(M));
		
		cout << b1 << ' ' << b2 << '\n';
	}
}

int binary(int M)
{
	int b1{0};
	while(M != 0)
	{
		if(M % 2 == 1)
			b1++;
		M /= 2;
	}
	return b1;
}

int hex(int M)
{
	int dec{0}, i{0};
	while(M != 0)
	{
		dec += (M % 10) * pow(16, i++);
		M /= 10;
	}
		
	return dec;
}