#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<vector<int>> ans;
	vector<int> out;
	void dfs(vector<int>& candidates, int k, int target) {
		if (target == 0) {
			ans.push_back(out);
			return;
		}
		if (target < 0) return;
		for (int i = k; i < candidates.size(); i++) {
			out.push_back(candidates[i]);
			dfs(candidates, i, target - candidates[i]);
			out.pop_back();
		}
	}

public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(candidates, 0, target);
		return ans;
	}
};