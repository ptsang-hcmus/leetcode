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
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* mid = getMid(head);
		ListNode* L = sortList(head);
		ListNode* R = sortList(mid);
		return merge(L, R);
	}

private:
	ListNode* getMid(ListNode* head) {
		ListNode* prevMid = nullptr;
		while (head && head->next) {
			prevMid = (prevMid == nullptr) ? head : prevMid->next;
			head = head->next->next;
		}
		ListNode* mid = prevMid->next;
		prevMid->next = nullptr;
		return mid;
	}
	ListNode* merge(ListNode* L, ListNode* R) {
		ListNode* dummyHead = new ListNode(0);
		ListNode* ptr = dummyHead;
		while (L && R) {
			if (L->val < R->val) {
				ptr->next = L;
				L = L->next;
			} else {
				ptr->next = R;
				R = R->next;
			}
			ptr = ptr->next;
			ptr->next = nullptr;
		}
		if (L)
			ptr->next = L;
		else
			ptr->next = R;
		return dummyHead->next;
	}
};