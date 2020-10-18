/**
 * 188. Best Time to Buy and Sell Stock IV
 * 3
 * [3,2,6,5,0,3,10,11]
 * =========================
 * 0; 0; 4; 4; 4; 4; 10; 11;
 * 0; 0; 4; 4; 4; 7; 14; 15;
 * 0; 0; 4; 4; 4; 7; 14; 15;
 */
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() == 0 || k == 0) return 0;
		if (2 * k >= prices.size()) {
			int res = 0;
			for (int i = 0; i < prices.size() - 1; i++) {
				if (prices[i + 1] > prices[i]) {
					res += prices[i + 1] - prices[i];
				}
			}
			return res;
		}
		vector<int> v(prices.size());
		for (int _ = 0; _ < k; _++) {
			int val = 0;
			for (int i = 1; i < prices.size(); i++) {
				val = max(v[i], val + prices[i] - prices[i - 1]);
				v[i] = max(v[i - 1], val);
			}
		}
		return v.back();
	}
};