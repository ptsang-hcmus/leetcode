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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;
        ListNode* dummy = slow;
        ListNode* next = nullptr, * last = nullptr;
        while (dummy) {
            next = dummy->next;
            dummy->next = last;
            last = dummy;
            dummy = next;
        }
        dummy = last;
        while (dummy) {
            if (dummy->val != head->val) return false;
            dummy = dummy->next;
            head = head->next;
        }
        return true;
    }
};