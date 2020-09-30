// NOT OPTIMAL YET
// O(n) space, O(n) time

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.empty()) return 1;
		int max_num = nums[0];
		unordered_set<int> dict;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) dict.insert(nums[i]);
			max_num = max(max_num, nums[i]);
		}
		for (int i = 1; i <= max_num; i++) {
			if (dict.find(i) == dict.end()) {
				return i;
			}
		}
		return max_num > 0 ? max_num + 1 : 1;
	}
};