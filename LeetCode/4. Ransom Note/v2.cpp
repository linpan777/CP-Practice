#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> compare(26, 0);
        for(char c: magazine)
            compare[c - 'a']++;

        for(char c: ransomNote)
            if(--compare[c - 'a'] < 0)
                return false;

        return true;
    }
};