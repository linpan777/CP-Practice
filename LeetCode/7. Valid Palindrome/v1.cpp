#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp, rev;

        for(char c: s)
            if(isalnum(c))
                temp.push_back(tolower(c));

        rev = temp;
        reverse(rev.begin(), rev.end());
        if(temp == rev)
            return true;
        else
            return false;

    }
};