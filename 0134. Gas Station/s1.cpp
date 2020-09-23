#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total = 0, start = 0, sum_gas = 0, sum_cost = 0;
		for (int i = 0; i < gas.size(); i++) {
			sum_gas += gas[i];
			sum_cost += cost[i];
			total += gas[i] - cost[i];
			if (total < 0) {
				start = i + 1;
				total = 0;
			}
		}
		return sum_gas < sum_cost ? -1 : start;
	}
};