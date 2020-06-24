#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto x : nums) map[x]++;

        vector<int> arr;
        for (auto x : map) arr.push_back(x.first);

        sort(arr.begin(), arr.end());

        vector<vector<int>> ret;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                if (map[0] > 2) {
                    ret.push_back({0, 0, 0});
                }
            } else if (map[arr[i]] > 1 && map.count(-2 * arr[i])) {
                ret.push_back({arr[i], arr[i], -2 * arr[i]});
            }
            if (arr[i] < 0) {
                int L = i + 1, R = arr.size() - 1;
                while (L < R) {
                    int sum = arr[i] + arr[L] + arr[R];
                    if (sum == 0) {
                        ret.push_back({arr[i], arr[L], arr[R]});
                        L++;
                        R--;
                    } else if (sum < 0) {
                        L++;
                    } else {
                        R--;
                    }
                }
            }
        }
        return ret;
    }
};