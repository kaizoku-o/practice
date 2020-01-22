// Problem: Two Sum
// Given an array of integers, return indices of the two numbers such that
// they add up to a specific target. You may assume that each input would
// have exactly one solution, and you may not use the same element twice.

#include "config.h"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tracker;

        for (int i = 0; i < nums.size(); i++)
        {
            if (tracker.find(target - nums[i]) == tracker.end())
            {
                tracker.insert({nums[i], i});
            }
            else
            {
                return vector<int> {tracker[target - nums[i]], i};
            }
        }

        return vector<int> {};
    }
};


int main()
{
    Solution s;
    vector<int> input = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = s.twoSum(input, target);
    cout << "Result: " << endl;

    for (auto index: result)
    {
        cout << index << endl;
    }
    return 0;
}
