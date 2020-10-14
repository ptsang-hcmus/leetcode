#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i] = max(nums[i] + (i > 1 ? dp[i - 2] : 0), dp[i - 1]);
		}
		return dp[nums.size() - 1];
	}
};