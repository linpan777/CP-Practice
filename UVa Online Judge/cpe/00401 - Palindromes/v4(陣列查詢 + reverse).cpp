#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
    char mirror_map[256] = {0};
    mirror_map['A'] = 'A';
    mirror_map['E'] = '3';
    mirror_map['H'] = 'H';
    mirror_map['I'] = 'I';
    mirror_map['J'] = 'L';
    mirror_map['L'] = 'J';
    mirror_map['M'] = 'M';
    mirror_map['O'] = 'O';
    mirror_map['S'] = '2';
    mirror_map['T'] = 'T';
    mirror_map['U'] = 'U';
    mirror_map['V'] = 'V';
    mirror_map['W'] = 'W';
    mirror_map['X'] = 'X';
    mirror_map['Y'] = 'Y';
    mirror_map['Z'] = '5';
    mirror_map['1'] = '1';
    mirror_map['2'] = 'S';
    mirror_map['3'] = 'E';
    mirror_map['5'] = 'Z';
    mirror_map['8'] = '8';
	string input;
    //string mirror = "AEHIJLMOSTUVWXYZ12358";
	//string mirror2 = "A3HILJMO2TUVWXY51SEZ8";
	//string mirror3 = "AHIMOTUVWXY18";
	while(getline(cin, input))
	{
		bool is_mirror = true;
		bool is_palindromes = true;
		for(int i{0}; i < input.size() / 2; i++)
		{
			//if(mirror.find(input[i]) != mirror2.find(input[input.size() - 1 - i]) && mirror.find(input[i]) != string::npos)
            //if(mirror.find(input[i]) != mirror2.find(input[input.size() - 1 - i]) ||
                //mirror.find(input[i]) == string::npos)
            char temp = mirror_map[input[i]];
            if(temp != input[input.size() - 1 - i] || temp == '\0')
			{
				is_mirror = false;
				break;
			}
		}
		//if(input.size() / 2 == 1)
        if(input.size() % 2 == 1)
			//if(mirror3.find(input[input.size() / 2 + 1]) == string::npos)
            //if(mirror3.find(input[input.size() / 2]) == string::npos)
            {
                char mid_mirror = mirror_map[input[input.size() / 2]];
                if(mid_mirror != input[input.size() / 2])
                    is_mirror = false;
            }
				
				
		string re_input = input;
        reverse(re_input.begin(), re_input.end());
        if(input != re_input)
            is_palindromes = false;
			
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