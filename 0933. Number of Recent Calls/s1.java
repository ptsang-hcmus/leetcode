class RecentCounter {
	private Queue<Integer> q;
	public RecentCounter() {
		this.q = new LinkedList<>();
	}
	
	public int ping(int t) {
		while (!q.isEmpty() && q.peek() < t - 3000) q.remove();
		q.add(t);
		return q.size();
	}
}

/**
* Your RecentCounter object will be instantiated and called as such:
* RecentCounter obj = new RecentCounter();
* int param_1 = obj.ping(t);
*/