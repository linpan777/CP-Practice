#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> modulo;
int dividend{ 0 };

bool mycmp(int a, int b);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, temp{ 8787 };
	cin >> T >> dividend;

	while(true)//原本：(temp != 0)
	{
		cin >> temp;
		if (temp == 0)//原本無
			break;
		modulo.push_back(temp);
	}
	sort(modulo.begin(), modulo.end(), mycmp);

	cout << T << ' ' << dividend << '\n';
	for (int i : modulo)
		cout << i << '\n'; 

	cout << "0 0\n";
}

bool mycmp(int a, int b)
{
	if (a % dividend < b % dividend)
		return 1;
	else if (a % dividend > b % dividend)
		return 0;


	if (a % 2 != 0 && b % 2 == 0)
		return 1;
	else if (a % 2 == 0 && b % 2 != 0)
		return 0;

	if (a % 2 != 0 && b % 2 != 0)
		if (a > b)
			return 1;

	if (a % 2 == 0 && b % 2 == 0)
		if (a < b)
			return 1;

	return 0;
}