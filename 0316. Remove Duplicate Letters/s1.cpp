class Solution {
public:
	string removeDuplicateLetters(string s) {
		char chars[26] = {0};
		for (char& c : s) chars[c - 'a']++;
		unordered_set<char> is_exists;
		string ans;
		for (char& c : s) {
			chars[c - 'a']--;
			if (is_exists.find(c) == is_exists.end()) {
				while (!ans.empty() && ans.back() > c &&
					   chars[ans.back() - 'a'] > 0) {
					is_exists.erase(ans.back());
					ans.pop_back();
				}
				ans.push_back(c);
				is_exists.insert(c);
			}
		}
		return ans;
	}
};