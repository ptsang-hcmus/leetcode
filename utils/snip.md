## 1. Custom sort array cpp
```cpp
sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
	return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
});
```
## 2. Custom sort array java
```java
Arrays.sort(intervals, new Comparator<int[]>() {
	@Override
	public int compare(int[] a, int[] b) {
		if (a[0] < b[0] || (a[0] == b[0] && a[1] > b[1])) {
			return -1;
		}
		return 1;
	}
});
```