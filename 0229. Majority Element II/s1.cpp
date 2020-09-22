#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int* can1 = nullptr;
		int* can2 = nullptr;
		int count1 = 0, count2 = 0;
		for (int& x : nums) {
			if (can1 != nullptr && *can1 == x) {
				count1++;
			} else if (can2 != nullptr && *can2 == x) {
				count2++;
			} else if (count1 == 0) {
				can1 = &x;
				count1 = 1;
			} else if (count2 == 0) {
				can2 = &x;
				count2 = 1;
			} else {
				count1--;
				count2--;
			}
		}
		vector<int> ans;
		count1 = count2 = 0;
		for (int& x : nums) {
			if (x == *can1)
				count1++;
			else if (x == *can2)
				count2++;
		}
		if (count1 > nums.size() / 3) ans.push_back(*can1);
		if (count2 > nums.size() / 3) ans.push_back(*can2);
		return ans;
	}
};