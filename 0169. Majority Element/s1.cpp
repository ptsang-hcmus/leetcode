#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int candidate, count = 0;
		for (int x : nums) {
			if (count == 0) {
				candidate = x;
			}
			if (x == candidate) {
				count++;
			} else {
				count--;
			}
		}
		return candidate;
	}
};