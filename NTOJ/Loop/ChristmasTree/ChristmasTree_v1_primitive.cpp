#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int input;//列數input
	cin >> input;

	for (int i{ 1 }; i <= input; i++)
	{
		for (int j{ 1 }; j <= input - i; j++)//空格
			cout << " ";
		for (int k{ 1 }; k <= 2*i - 1; k++)//星星
			cout << '*';
		cout << '\n';//每一次都要換行
	}
}
