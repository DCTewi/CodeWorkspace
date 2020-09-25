// Two sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans (2, -1);
        unordered_map<int, int> hash;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.count(target - nums[i]))
            {
                ans[0] = hash[target - nums[i]];
                ans[1] = i;
                break;
            }
            else
            {
                hash[nums[i]] = i;
            }
        }

        return ans;
    }
};
