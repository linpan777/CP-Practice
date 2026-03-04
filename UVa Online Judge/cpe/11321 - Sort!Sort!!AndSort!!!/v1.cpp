#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dividend{ 0 };

bool mycmp(int a, int b);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, temp{ 8787 };

	while(cin >> T >> dividend && (T != 0 && dividend != 0))//多筆測資時用
	{
		vector<int> modulo;//每一次都要重製vector，避免殘留上一次測資

		for(int i{0}; i < T; i++)
		{	
			cin >> temp;
			modulo.push_back(temp);
		}
		sort(modulo.begin(), modulo.end(), mycmp);//用sort排序

		cout << T << ' ' << dividend << '\n';
		for (int i : modulo)
			cout << i << '\n'; 
	}
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