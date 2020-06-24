#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";

        int maxLength = 0;
        for (auto s : strs) {
            if (maxLength < s.length()) {
                maxLength = s.length();
            }
        }
        if (maxLength == 0) return "";

        int end = 0;
        while (end <= maxLength) {
            for (int i = 0; i < strs.size() - 1; i++) {
                if (strs[i][end] != strs[i + 1][end]) {
                    return strs[0].substr(0, end);
                }
            }
            end++;
        }

        return strs[0].substr(0, end);
    }
};