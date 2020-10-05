class Solution {
public:
	int bitwiseComplement(int N) {
		if (N == 0) return 1;
		int x = N;
		int full = 0;
		while (x > 0) {
			full = (full << 1) + 1;
			x = x >> 1;
		}
		return full - N;
	}
};