#include <iostream>
using namespace std;

char sweeper[102][102] = {'0'};
int Case{1};
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int m, n;
	char c; 
	
	while(cin >> m >> n)
	{
		if(m == 0 && n == 0)
			return 0;
			
		if(Case > 1)
			cout << '\n';
			
		for(int i{1}; i <= m; i++)
			for(int j{1}; j <= n; j++)
			{
				cin >> c;
				if(c == '.')
					sweeper[i][j] = '0';
				else if(c == '*')
					sweeper[i][j] = '*';				
			}
			
		for(int i{1}; i <= m; i++)
			for(int j{1}; j <= n; j++)
			{
				if(sweeper[i][j] == '*')
					for(int k{i - 1}; k <= i + 1; k++)
						for(int l{j - 1}; l <= j + 1; l++)
							if(sweeper[k][l] == '*')
								continue;
							else
								sweeper[k][l] = sweeper[k][l] + 1;
			}
		
		cout << "Field #" << Case++ << ":\n";
		for(int i{1}; i <= m; i++)
		{
			for(int j{1}; j <= n; j++)
				cout << sweeper[i][j];
			cout << '\n';
		}
	}
}