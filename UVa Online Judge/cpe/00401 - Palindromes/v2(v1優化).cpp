#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string input;
	string mirror = "AEHIJLMOSTUVWXYZ12358";
	string mirror2 = "A3HILJMO2TUVWXY51SEZ8";
	string mirror3 = "AHIMOTUVWXY18";
	while(getline(cin, input))
	{
		bool is_mirror = true;
		bool is_palindromes = true;
		for(int i{0}; i < input.size() / 2; i++)
		{
			//if(mirror.find(input[i]) != mirror2.find(input[input.size() - 1 - i]) && mirror.find(input[i]) != string::npos)
            if(mirror.find(input[i]) != mirror2.find(input[input.size() - 1 - i]) ||
                mirror.find(input[i]) == string::npos)
			{
				is_mirror = false;
				break;
			}
		}
		//if(input.size() / 2 == 1)
        if(input.size() % 2 == 1)
			//if(mirror3.find(input[input.size() / 2 + 1]) == string::npos)
            if(mirror3.find(input[input.size() / 2]) == string::npos)
				is_mirror = false;
				
		for(int i{0}; i < input.size() / 2; i++)
		{
			if(input[i] != input[input.size() - 1 - i])
			{
				is_palindromes = false;
				break;
			}
		}
			
		if(is_mirror == 1 && is_palindromes == 1)
			cout << input << " -- is a mirrored palindrome.\n" << '\n';
		else if(is_mirror == 1 && is_palindromes == 0)
			cout << input << " -- is a mirrored string.\n" << '\n';
		else if(is_mirror == 0 && is_palindromes == 1)
			cout << input << " -- is a regular palindrome.\n" << '\n';
		else
			cout << input << " -- is not a palindrome.\n" << '\n';
	}
}