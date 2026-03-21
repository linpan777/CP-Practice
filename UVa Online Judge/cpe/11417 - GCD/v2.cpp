#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);
    //直接先建表
	int answer[502] = {0};
	
	//N的答案 = N-1的答案 + gcd(1~N-1, N)
	for(int i{2}; i < 502; i++)//不需要管1, 不會自己跟自己求gcd, 所以從2開始
	{
		answer[i] = answer[i - 1];//每一次都先等於前一個的答案
		for(int j{1}; j < i; j++)
			answer[i] += gcd(j, i);//再做 gcd(1~N-1, N) 的連加
	}
	
	int N;
	while(cin >> N && N != 0)
		cout << answer[N] << '\n';
}

int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);//會利用取餘數的特性自動交換為a > b
}