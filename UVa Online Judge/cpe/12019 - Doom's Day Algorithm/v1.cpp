#include <iostream>
#include <ctime>
using namespace std;

string wday[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int month, date;
		cin >> month >> date;
		
		tm time_info = {0};
		time_info.tm_year = 2011 - 1900;
		time_info.tm_mon = month - 1;
		time_info.tm_mday = date;
		
		mktime(&time_info);
		
		cout << wday[time_info.tm_wday] << '\n';
		
	}
	
}