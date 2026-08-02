#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        //unordered_map<int, int> appear;
        unordered_set<int> appear;
        for(int i{0}; i < nums.size(); i++)
        {
            if(appear.find(nums[i]) == appear.end())
                //appear[nums[i]] = 1;
                appear.insert(nums[i]);
            else
                return true;
        }
        return false;
    }
};