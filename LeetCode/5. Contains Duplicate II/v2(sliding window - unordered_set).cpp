#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> table;
        for(int i{0}; i < nums.size(); i++)
        {
            if(table.find(nums[i]) != table.end())
                return true;
            
            table.insert(nums[i]); 

            if(table.size() > k)
                table.erase(nums[i - k]);    
        }

        return false;
    }
};