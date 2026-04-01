#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int Case; cin >> Case; cin.ignore(); cin.ignore();
	
	while(Case--)
	{
		map<string, double> treeAndSpecies;
		string tree;
		int count{0};
		
		while(getline(cin, tree) && tree != "")
		{
			count++;
			treeAndSpecies[tree]++;
		}
		
		for(auto it: treeAndSpecies)
			cout << it.first << ' ' << setprecision(4) << fixed << it.second / count * 100 << '\n';
		
		if(Case != 0)
			cout << '\n';
	}
}