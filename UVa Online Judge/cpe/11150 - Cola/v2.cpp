#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, bottle;
	
	while(cin >> n)
		cout << n + n / 2 << '\n';
}