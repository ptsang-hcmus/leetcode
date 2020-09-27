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
	public ListNode mergeKLists(ListNode[] lists) {
		if (lists.length == 0) return null;
		Comparator<ListNode> comparator = new ListNodeComparator();
		PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(lists.length, comparator);
		for (ListNode i : lists) {
			if (i != null) pq.add(i);
		}
		ListNode ans = new ListNode();
		ListNode dummy = ans;
		while (!pq.isEmpty()) {
			ans.next = pq.peek();
			pq.remove();
			if (ans.next.next != null) {
				pq.add(ans.next.next);
			}
			ans = ans.next;
		}
		return dummy.next;
	}
}

public class ListNodeComparator implements Comparator<ListNode> {
	@Override
	public int compare(ListNode a, ListNode b) {
		if (a.val < b.val) return -1;
		return 1;
	}
}