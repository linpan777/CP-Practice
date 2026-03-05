#include <iostream>
using namespace std;

int main()
{
	int time = 1;
	int T;
	cin >> T;
	
	while(T--)
	{
		int x1, y1, x2, y2, sum1, sum2;
		cin >> x1 >> y1 >> x2 >> y2;
		sum1 = x1 + y1; sum2 = x2 + y2;
		
		int answer{0};
		for(int i{2}; i <= sum2; i++)
			answer += i;
		answer += (x2 + 1);
		
		for(int i{2}; i <= sum1; i++)
			answer -= i;
			
		if(x1 == 0 && y1 == 0)
			;
		else
			answer = answer - x1 - 1;
		
		cout << "Case " << time++ << ": " << answer << '\n';
	}
}