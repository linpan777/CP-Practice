#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int input;
	cin >> input;

	for (int i{ 1 }; i <= input; i++)
	{
		for (int j{ 1 }; j <= input - i; j++)
			cout << " ";
		for (int k{ 1 }; k <= 2*i - 1; k++)
			cout << '*';
		for (int l{ 1 }; l <= input - i; l++)
			cout << " ";
		cout << '\n';
	}
}
