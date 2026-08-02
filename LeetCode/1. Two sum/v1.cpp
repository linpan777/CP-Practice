#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> answer;
        unordered_map<int, int> table;
        for(int i{0}; i < nums.size(); i++)
        {
            if(table.find(target - nums[i]) != table.end())
            {
                answer.push_back(table[target - nums[i]]);
                answer.push_back(i);
                return answer;
            }
            else
                table.insert({nums[i], i});
        }

        return answer;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;
    solution.twoSum(nums, 6);
}