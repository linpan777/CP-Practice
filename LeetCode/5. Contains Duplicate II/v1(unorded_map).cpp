#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> table;
        for(int i{0}; i < nums.size(); i++)
        {
            if(table.find(nums[i]) != table.end() && i - table[nums[i]] <= k)
                return true;
            else
            {
                if(table.find(nums[i]) != table.end())
                    table[nums[i]] = i;
                else
                    table.insert({nums[i], i});
            }
        }

        return false;
    }
};