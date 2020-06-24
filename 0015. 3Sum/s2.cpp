#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < n - 2; i++) {
            int L = i + 1, R = n - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    vector<int> v{nums[i], nums[L++], nums[R--]};
                    ret.push_back(v);
                    while (L < R && nums[L] == nums[L - 1]) L++;
                    while (L < R && nums[R] == nums[R + 1]) R--;
                } else if (sum > 0)
                    R--;
                else
                    L++;
            }
            while (i + 1 < n - 2 && nums[i] == nums[i + 1]) i++;
        }
        return ret;
    }
};