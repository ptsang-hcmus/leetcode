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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr) return head;
		ListNode* dummy = head;
		int size = 0;
		while (dummy != nullptr) {
			size++;
			dummy = dummy->next;
		}
		k = k % size;
		if (k == 0 || size == 1) return head;
		dummy = head;
		int i = 1;
		while (i < size - k) dummy = dummy->next, i++;
		ListNode* next = dummy->next;
		dummy->next = nullptr;
		dummy = next;
		while (dummy->next != nullptr) {
			dummy = dummy->next;
		}
		dummy->next = head;
		return next;
	}
};