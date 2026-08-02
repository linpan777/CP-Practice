#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_multiset<char> compare;
        for(char c: s)
            compare.insert(c);
        
        for(char c: t)
        {
            if(compare.find(c) != compare.end())
                compare.erase(compare.find(c));
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