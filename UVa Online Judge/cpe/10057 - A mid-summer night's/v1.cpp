#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n{0};
	
	while(cin >> n)
	{
		int number[1000001] = {0};
		for(int i{1}; i <= n; i++)
			cin >> number[i]; 
			
		sort(number, number + n);//先用sort由小排到大方便接下來找中位數
		
		int secondOutput{0};
        //積偶有不同需要注意的地方
		if(n % 2 == 1)
		{
			cout << number[n / 2 + 1] << ' ';//最中間那個就是中位數
			for(int i{1}; i <= n; i++)
				if(number[i] == number[n / 2 + 1])
					secondOutput++;//array中有幾個與中位數同數字的數
			cout << secondOutput << ' ' << 1 << '\n';//因為有一個具體的數，只可能有一個數字輩包含在中位數中
		}
		else
		{
			cout << number[n / 2] << ' ';//中間-1的數
			for(int i{1}; i <= n; i++)
				if(number[i] == number[n / 2] || number[i] == number[n / 2 + 1])
					secondOutput++;//中間與n/2+1都屬於output2的要求
                    //中間與n/2+1(包含)中的所有數有幾個
			cout << secondOutput << ' ' << number[n / 2 + 1] - number[n / 2] + 1 << '\n';
		}
	}
}