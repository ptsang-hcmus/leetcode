#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& v, int target) {
        vector<vector<int> > result;
        size_t n = v.size();
        if (n < 4) return result;

        sort(v.begin(), v.end());
        for (int i = 0; i < n - 3; ++i) {
            if (target <= 0 && v[i] > 0) break;

            if (v[i] + v[i + 1] + v[i + 2] + v[i + 3] > target) break;
            if (v[i] + v[n - 3] + v[n - 2] + v[n - 1] < target) continue;
            if (i > 0 && v[i] == v[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (v[i] + v[j] + v[j + 1] + v[j + 2] > target) break;
                if (v[i] + v[j] + v[n - 2] + v[n - 1] < target) continue;
                if (j > i + 1 && v[j] == v[j - 1]) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    int sum = v[i] + v[j] + v[left] + v[right];
                    if (sum == target) {
                        result.push_back({v[i], v[j], v[left], v[right]});
                        int last_left = v[left], last_right = v[right];
                        while (left < right && v[left] == last_left) ++left;
                        while (left < right && v[right] == last_right) --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return result;
    }
};