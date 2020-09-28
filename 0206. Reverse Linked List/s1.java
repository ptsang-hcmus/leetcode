/**
* Definition for singly-linked list.
* public class ListNode {
*     int val;
*     ListNode next;
*     ListNode() {}
*     ListNode(int val) { this.val = val; }
*     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
* }
*/
class Solution {
	public ListNode reverseList(ListNode head) {
		ListNode next = null, last = null;
		while (head != null) {
			next = head.next;
			head.next = last;
			last = head;
			head = next;
		}
		return last;
	}
}