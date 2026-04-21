#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int L, H, R, maxR{ 0 };
	int builds[10001] = { 0 };
	while (cin >> L >> H >> R)
	{
		if (maxR < R)
			maxR = R;
		for (int i{ L }; i < R; i++)
			builds[i] = max(builds[i], H);
	}

	int currentHeigh{ 0 };
	bool first = true;
	for (int i{ 0 }; i <= maxR; i++)
		if (builds[i] != currentHeigh)
		{
			if (!first)
				cout << ' ';
			cout << i << ' ' << builds[i];
			currentHeigh = builds[i];

			first = false;
		}
	cout << '\n';
}