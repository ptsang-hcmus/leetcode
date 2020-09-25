#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [&](int a, int b) {
			if (a == 0) return false;
			if (b == 0) return true;
			long x = a, y = b, t = b;
			while (t > 0) {
				x *= 10;
				t /= 10;
			}
			t = a;
			while (t > 0) {
				y *= 10;
				t /= 10;
			}
			x += b;
			y += a;
			return x > y;
		});
		string ans = "";
		if (nums[0] == 0) return "0";
		for (int x : nums) {
			ans += to_string(x);
		}
		return ans;
	}
};