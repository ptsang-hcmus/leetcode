#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, diff = INT_MAX, n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = n - 1;
            int MAX = nums[i] + nums[r - 1] + nums[r];
            int MIN = nums[i] + nums[l] + nums[l + 1];

            if (MAX <= target) {
                if (MAX == target) return target;
                if (target - MAX < diff) {
                    diff = target - MAX;
                    ans = MAX;
                    continue;
                }
            }
            if (MIN >= target) {
                if (MIN == target) return target;
                if (MIN - target < diff) {
                    diff = MIN - target;
                    ans = MIN;
                    continue;
                }
            }

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int currentDiff;
                if (sum == target) return target;
                if (sum < target) {
                    l++;
                    currentDiff = target - sum;
                } else {
                    r--;
                    currentDiff = sum - target;
                }
                if (currentDiff < diff) {
                    diff = currentDiff;
                    ans = sum;
                }
            }
        }

        return ans;
    }
};