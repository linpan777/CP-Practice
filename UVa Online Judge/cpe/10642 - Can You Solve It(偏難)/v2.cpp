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
		
		int answer2{0}, answer1{0};
		
        answer2 = sum2 * (sum2+1) / 2;//由for loop改為等差公式
        answer1 = sum1 * (sum1+1) / 2;
		answer2 += x2 - answer1 - x1;//第二組座標減第一組
		
		cout << "Case " << time++ << ": " << answer2 << '\n';
	}
}