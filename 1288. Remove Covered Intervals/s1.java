class Solution {
	public int removeCoveredIntervals(int[][] intervals) {
		Arrays.sort(intervals, new Comparator<int[]>() {
			@Override
			public int compare(int[] a, int[] b) {
				if (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1])) {
					return -1;
				}
				return 1;
			}
		});
		int ans = 0;
		for (int i = 0; i < intervals.length; i++) {
			ans++;
			int j = i + 1;
			while (j < intervals.length &&
				intervals[i][0] <= intervals[j][0] &&
				intervals[j][1] <= intervals[i][1]) {
				j++;
			}
			i = j - 1;
		}
		return ans;
	}
}