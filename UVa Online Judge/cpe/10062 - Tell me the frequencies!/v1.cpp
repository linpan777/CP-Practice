#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct CharFrequence{
	int ASCIIchar = 0;
	int count = 0;
};

bool mycmp(CharFrequence a, CharFrequence b);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string setences;
	
	int T{1};
	while(getline(cin, setences))
	{
		if(T == 1)
			T++;
		else
			cout << '\n';
			
		CharFrequence data[129];
		for(int i{0}; i < setences.size(); i++)
		{
			int temp = (int)setences[i];
			data[temp].ASCIIchar = temp;
			data[temp].count++;
		}
		
		sort(data, data + 129, mycmp);
		for(int i{0}; i < 129; i++)
		{
			if(data[i].count == 0)
				continue;
			cout << data[i].ASCIIchar << ' ' << data[i].count << '\n';
		}
	}	
}

bool mycmp(CharFrequence a, CharFrequence b)
{
	if(a.count < b.count)
		return true;
	else if(a.count > b.count)
		return false;
		
	if(a.ASCIIchar > b.ASCIIchar)
		return true;
	else if(a.ASCIIchar < b.ASCIIchar)
		return false;
		
}