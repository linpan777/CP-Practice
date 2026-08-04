#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> compare;
        for(char c: magazine)
            compare[c]++;

        for(char c: ransomNote)
        {
            if(compare.find(c) == compare.end())
                return false;
            else
            {
                compare[c]--;
                if(compare[c] < 0)
                    return false;
            }  
        }
        return true;
    }
};