class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		for (auto& i : nums) {
			mp[i]++;
		}
		int ans = 0;
		if (k == 0) {
			for (auto& it : mp) {
				if (it.second > 1) ans++;
			}
		} else {
			for (auto& it : mp) {
				if (mp.find(it.first - k) != mp.end()) ans++;
				if (mp.find(it.first + k) != mp.end()) ans++;
			}
			ans /= 2;
		}
		return ans;
	}
};