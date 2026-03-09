#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, bottle;
	
	while(cin >> n)//初始購買數量
	{
		bottle = n;//直接=初始量
	
		while(n / 3 != 0)//初始量化為手上有的空瓶數，當不足三瓶時出迴圈
		{
			bottle += n/3;//喝的數量都會+=空瓶數/3向下取整
			n = n%3 + n/3;//n%3的就加進手上空瓶數，繼續跑回圈直到條件不成立
		}
	
        //無論再怎麼借，頂多湊到3瓶換1
        //if借了2瓶，換1喝掉之後還不起瓶子給朋友
		if(n % 3 == 1)//空瓶剩1就沒了
			cout << bottle << '\n';
		else//剩2還可以借1還1一次
			cout << bottle + 1 << '\n';
	}
}