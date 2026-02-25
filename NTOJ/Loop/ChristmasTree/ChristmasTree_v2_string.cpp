#include<iostream>
#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int input;
	cin >> input;

	for (int i{ 1 }; i <= input; i++)
		cout << string(input - i, ' ') <<  string(i * 2 - 1, '*') << '\n';
}
