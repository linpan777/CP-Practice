#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string number;
	while(cin >> number)
	{
		if(number[0] == '0')//問題在這裡
			return 0;
		
		int temp1{0}, temp2{0};
		
		for(int i = number.size() - 1; i >= 0; i-=2)
			temp1 += number[i] - '0';
		for(int i = number.size() - 2; i >= 0; i-=2)
			temp2 += number[i] - '0';
		
		if(abs(temp1 - temp2) % 11 == 0)
			cout << number << " is a multiple of 11.\n";
		else
			cout << number << " is not a multiple of 11.\n";
	}
}