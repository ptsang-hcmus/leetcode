/**
 * 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
 *
 * Prove:
 * https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/discuss/585632/JavaC%2B%2BPython-Easy-Prove
 *
 */

class Solution {
public:
	int findMinFibonacciNumbers(int k) {
		int ans = 0, f1 = 1, f2 = 1;
		while (f2 < k) {
			swap(f1, f2);
			f2 += f1;
		}
		while (k > 0) {
			if (f2 <= k) {
				ans++;
				k -= f2;
			}
			swap(f1, f2);
			f1 -= f2;
		}
		return ans;
	}
};