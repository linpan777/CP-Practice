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

		cin >> first;

		for (int i{ 1 }; i < n; i++)
		{
			cin >> second;
			number[abs(first - second)] = true;
			first = second;
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