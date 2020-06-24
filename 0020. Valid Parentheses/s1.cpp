#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string in) {
        if (in.empty()) return true;
        stack<char> s;
        for (auto c : in) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else {
                if (s.empty()) return false;
                auto top = s.top();
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
                s.pop();
            }
        }
        return s.empty();
    }
};