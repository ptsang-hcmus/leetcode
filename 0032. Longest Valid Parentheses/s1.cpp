#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack = {-1};
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                stack.pop_back();
                if (stack.size() != 0)
                    ans = max(ans, i - stack.back());
                else
                    stack.push_back(i);
            }
        }
        return ans;
    }
};