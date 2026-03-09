#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string number_sy;
	
	while(cin >> number_sy)
	{	
		bool value = false;
		int max{0};
		int total{0};
        
        //找出數字相加總合 & 最低從哪個進制開始猜
		for(int i{0}; i < number_sy.size(); i++)
		{
			int temp{0};
			
            //數字換算
			if(number_sy[i] >= 'A' && number_sy[i] <= 'Z')
				temp = number_sy[i] - 'A' + 10;
			else if(number_sy[i] >= 'a' && number_sy[i] <= 'z')
				temp = number_sy[i] - 'a' + 36;
			else if(number_sy[i] >= '0' && number_sy[i] <= '9')
				temp = number_sy[i] - '0';
				
			if(max < temp)//決定最少從哪個數字開始猜
				max = temp;
				
			total += temp;//全部相加之後用來判斷
		}
		
        //預先排除0
		if(max == 0)
		{
			cout << 2 << '\n';
			continue;
		}
		
        //core algorithm
		for(int n{max + 1}; n <= 62; n++)
			if(total % (n - 1) == 0)
			{
				cout << n << '\n';
				value = true;
				break;
			}
		
		if(!value)
			cout << "such number is impossible!\n";
		
	}
}