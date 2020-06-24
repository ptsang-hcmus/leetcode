#include <bits/stdc++.h>
using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(), *head = ans;

        int s = 0, c = 0;
        while (l1 != NULL || l2 != NULL) {
            s = c;

            if (l1 != NULL) {
                s += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                s += l2->val;
                l2 = l2->next;
            }

            if (s > 9) {
                c = 1;
                s = s - 10;
            } else {
                c = 0;
            }

            ans->next = new ListNode(s);
            ans = ans->next;
        }

        if (c > 0) ans->next = new ListNode(c);

        return head->next;
    }
};