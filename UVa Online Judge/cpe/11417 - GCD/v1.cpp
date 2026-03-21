#include <iostream>
#include <numeric>
using namespace std;

int gcd(int a, int b);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	while(cin >> N)
	{
		if(N == 0)
			return 0;
			
		int G=0;
		for(int i{1}; i < N; i++)
			for(int j{i + 1}; j <= N; j++)
                G += gcd(i,j);
        cout << G << '\n';
	}
}

int gcd(int a, int b)
{
	int gcd{0};
	for(int i{1}; i <= a; i++)
		if(a % i == 0 && b % i == 0)
			gcd = i;
			
	return gcd;
}