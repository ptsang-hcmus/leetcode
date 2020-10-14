class Solution {
public:
	bool buddyStrings(string A, string B) {
		if (A.length() != B.length()) {
			return false;
		}
		int count = 0;
		int first = -1, second = -1;
		char chars[26] = {0};
		for (int i = 0; i < A.size(); i++) {
			chars[A[i] - 'a']++;
			if (A[i] != B[i]) {
				count++;
				if (first != -1 && second == -1) {
					second = i;
				}
				if (first == -1) {
					first = i;
				}
			}
		}
		if (count == 0) {
			for (int i = 0; i < 26; i++) {
				if (chars[i] >= 2) return true;
			}
		} else if (count == 2) {
			if (A[first] == B[second] && A[second] == B[first]) {
				return true;
			}
		}
		return false;
	}
};