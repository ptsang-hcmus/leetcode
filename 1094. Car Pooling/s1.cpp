#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		int maxVal = 0;
		for (auto& trip : trips) {
			maxVal = max(maxVal, trip[2]);
		}
		vector<int> dp(maxVal + 1);
		for (auto& trip : trips) {
			dp[trip[1]] += trip[0];
			dp[trip[2]] -= trip[0];
		}
		int current_cap = 0;
		for (int i = 0; i <= maxVal; i++) {
			current_cap += dp[i];
			if (current_cap > capacity) return false;
		}
		return true;
	}
};