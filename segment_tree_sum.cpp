#include<bits/stdc++.h>
#define int long long int

using namespace std;

struct segmentTree {
	vector<int> st;
	segmentTree(int n) {
		st.resize(4 * n, 0);
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
		st[node] = st[left_node] + st[right_node];
	}

	// logn nodes to update
	void update(int start, int end, int node, vector<int> &v, int index, int value) {
		if (start == end) {
			v[index] = value;
			st[node] = value;
			return;
		}

		int mid = (start + end) / 2;
		// if index is in the left subtree
		if (index <= mid) {
			update(start, mid, 2 * node + 1, v, index, value);
		}
		else {
			update(mid + 1, end, 2 * node + 2, v, index, value);
		}
		// coming back update the cur node
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	// Average log(n)
	int query(int start, int end, int node, int l, int r) {
		// complete overlap
		if (start >= l && end <= r) {
			return st[node];
		}
		// no overlap
		if (start > r || end < l) {
			return 0;
		}
		// partial overlap
		int mid = (start + end) / 2;
		int left_query = query(start, mid, 2 * node + 1, l, r);
		int right_query = query(mid + 1, end, 2 * node + 2, l, r);
		return left_query + right_query;
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	segmentTree St(n);
	St.build(0, n - 1, 0, v);


	cout << St.query(0, n - 1, 0, 3, 5) << '\n';

	int index = 4, value = 3;
	St.update(0, n - 1, 0, v, index, value);

	cout << St.query(0, n - 1, 0, 3, 5) << '\n';
	// for (auto x : St.st) {
	// 	cout << x << " ";
	// }


	// cout << St.query(0, n - 1, 0, 1, 7) << '\n';

	return 0;
}