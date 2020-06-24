#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexOf;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (indexOf.count(target - nums[i])) {
                return {indexOf[target - nums[i]], i};
            }
            indexOf[nums[i]] = i;
        }
        return {};
    }
};