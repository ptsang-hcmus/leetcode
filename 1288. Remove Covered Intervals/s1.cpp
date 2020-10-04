class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		int ans = 0;
		sort(intervals.begin(), intervals.end(),
			 [](vector<int>& a, vector<int>& b) {
				 return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
			 });
		for (int i = 0; i < intervals.size(); i++) {
			ans++;
			int j = i;
			while (j + 1 < intervals.size() &&
				   intervals[i][0] <= intervals[j + 1][0] &&
				   intervals[j + 1][1] <= intervals[i][1]) {
				j++;
			}
			i = j;
		}
		return ans;
	}
};