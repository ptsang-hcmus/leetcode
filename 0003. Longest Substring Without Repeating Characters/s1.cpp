#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(128, -1);
        int ans = 0;
        int start = -1;
        for (int i = 0; i < (int)s.length(); i++) {
            if (vis[s[i]] > start) start = vis[s[i]];
            vis[s[i]] = i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};