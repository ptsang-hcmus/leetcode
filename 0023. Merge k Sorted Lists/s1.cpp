/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* ans = new ListNode();
		ListNode* dummy = ans;
		auto comparer = [](ListNode* a, ListNode* b) {
			return a->val > b->val;
		};
		priority_queue<ListNode*, vector<ListNode*>, decltype(comparer)> pq(
			comparer);
		int n = lists.size();
		for (int i = 0; i < n; i++) {
			if (lists[i]) pq.push(lists[i]);
		}
		while (!pq.empty()) {
			ans->next = pq.top();
			pq.pop();
			if (ans->next->next) {
				pq.push(ans->next->next);
			}
			ans = ans->next;
		}
		return dummy->next;
	}
};