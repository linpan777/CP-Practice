#include <iostream>
#include <ctime>
using namespace std;

int month_a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string wday[7] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int month, date, day{0};
		cin >> month >> date;
		
		for(int i{0}; i < month; i++)
			day += month_a[i];
			
		cout << wday[(day + date) % 7] << '\n';
	}
}