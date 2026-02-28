#include<iostream>
using namespace std;

int fib[45] = { 1, 2 };

int main()
{
	for (int i{ 2 }; i < 45; i++)//fib數列建立(1 2固定，剩下讓code自己加)
		fib[i] = fib[i - 1] + fib[i - 2];

	int T;//測資數量
	cin >> T;
	while (T--)
	{
		int n;//輸入數字
		cin >> n;
		cout << n << " = ";//提早印出n =

		int i{ 0 };
		while (n >= fib[i])//找出n在fib數列中小於等於n的最大index
			i++;

		for (int j{ i - 1 }; j >= 0; j--)//從最大index開始往下檢查(需從i - 1開始才是<=n的max number)，若fib[j] > n則印0，反之則n減去fib[j]並印1
			if (fib[j] > n)
				cout << 0;
			else
			{
				n -= fib[j];
				cout << 1;
			}

		cout << " (fib)\n";
	}
}
