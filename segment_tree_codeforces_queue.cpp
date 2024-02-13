#include<bits/stdc++.h>
#define int long long int

using namespace std;

struct segmentTree {
	vector<int> st;
	int default_value = -1, n;
	segmentTree(int n) {
		st.resize(4 * n, default_value);
		this->n = n;
	}
	int operation(int left, int right) {
		return max(left, right);
	}

	// [start...end]
	void build(int start, int end, int node, vector<int> &v) {
		if (start == end) {
			st[node] = v[start];
			return;
		}
		int left_node = 2 * node + 1, right_node = 2 * node + 2;
		int mid = (start + end) / 2;
		// left subtree
		build(start, mid, left_node, v);
		// right subtree
		build(mid + 1, end, right_node, v);
		st[node] = operation(st[left_node], st[right_node]);
	}

	// logn nodes to update
	void update(int start, int end, int node, int index, int value) {
		if (start == end) {
			st[node] = value;
			return;
		}

		int mid = (start + end) / 2;
		// if index is in the left subtree
		if (index <= mid) {
			update(start, mid, 2 * node + 1, index, value);
		}
		else {
			update(mid + 1, end, 2 * node + 2, index, value);
		}
		// coming back update the cur node
		st[node] = operation(st[2 * node + 1], st[2 * node + 2]);
	}

	// Average log(n)
	int query(int start, int end, int node, int l, int r) {
		// complete overlap
		if (start >= l && end <= r) {
			return st[node];
		}
		// no overlap
		if (start > r || end < l || r < l) {
			return default_value;
		}
		// partial overlap
		int mid = (start + end) / 2;
		int left_query = query(start, mid, 2 * node + 1, l, r);
		int right_query = query(mid + 1, end, 2 * node + 2, l, r);
		return operation(left_query, right_query);
	}

	int query(int l, int r) {
		return query(0, n - 1, 0, l, r);
	}

	void update(int index, int val) {
		update(0, n - 1, 0, index, val);
	}

	void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}

	segmentTree St(n);
	int res[n];

	// O(nlogn)
	sort(v.begin(), v.end());

	// O(nlogn)
	for (auto x : v) {
		int val = x.first;
		int index = x.second;

		// O(logn)
		int max_index = St.query(index + 1, n - 1);
		int ans = (max_index == -1 ? -1 : max_index - index - 1);
		res[index] = ans;

		// O(logn)
		St.update(index, index);
	}


	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}



	return 0;
}