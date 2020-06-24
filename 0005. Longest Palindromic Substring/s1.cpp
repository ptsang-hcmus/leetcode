#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, maxStart = 0;
        int l, r, n = s.length();
        for (int i = 0; i <= n - maxLen / 2; i++) {
            l = r = i;
            while (r + 1 < n && s[r] == s[r + 1]) r++;
            i = r;
            while (l - 1 >= 0 && r + 1 < n && s[l - 1] == s[r + 1]) {
                l--;
                r++;
            }
            if (maxLen < r - l + 1) {
                maxLen = r - l + 1;
                maxStart = l;
            }
        }

        return s.substr(maxStart, maxLen);
    }
};