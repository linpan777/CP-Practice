#include<iostream>
#include<cmath>
using namespace std;



int main()
{
	int n, first, second;
	while (cin >> n)
	{
		bool jolly = true;
		bool number[3000] = { false };

		cin >> first >> second;
		number[abs(first - second)] = true;

		for (int i{ 1 }; i < n - 1; i++)
		{
			first = second;
			cin >> second;
			number[abs(first - second)] = true;
		}

		for (int i{ 1 }; i < n; i++)
		{
			if (number[i] == false)
			{
				jolly = false;
				break;
			}
			else
				continue;
		}

		if (jolly)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}
}