#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		double p{0}; int people{0}, x{0};
		cin >> people >> p >> x;
		double q = 1 - p;
		
		double ans{0};
		if(p != 0)
			ans = (pow(q, x-1) * p) / (1 - pow(q, people));
			
		cout << setprecision(4) << fixed << ans << '\n'; 
	}
}