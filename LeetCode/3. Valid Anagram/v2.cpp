#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> compare;
        for(char c: s)
            compare[c]++;
        
        for(char c: t)
        {
            if(compare.find(c) != compare.end())
            {
                compare[c]--;
                if(compare[c] < 0)
                    return false;
            }
            else
                return false;

        }

        return true;
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
}