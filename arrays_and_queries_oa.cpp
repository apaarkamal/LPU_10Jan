#include<bits/stdc++.h>
#define int long long int

using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

struct segmentTree {
	vector<int> st;
	segmentTree(int n) {
		st.resize(4 * n, INT_MAX);
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
		st[node] = min(st[left_node], st[right_node]);
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
		st[node] = min(st[2 * node + 1], st[2 * node + 2]);
	}

	// Average log(n)
	int min_query(int start, int end, int node, int l, int r) {
		// complete overlap
		if (start >= l && end <= r) {
			// db(start, end, st[node]);
			return st[node];
		}
		// no overlap
		if (start > r || end < l) {
			return INT_MAX;
		}
		// partial overlap
		int mid = (start + end) / 2;
		int left_query = min_query(start, mid, 2 * node + 1, l, r);
		int right_query = min_query(mid + 1, end, 2 * node + 2, l, r);
		return min(left_query, right_query);
	}

	// log(n)
	int find_min_index(int start, int end, int node, int x) {
		if (start == end) {
			return start;
		}
		int mid = (start + end) / 2;
		if (st[2 * node + 1] <= x) {
			return find_min_index(start, mid, 2 * node + 1, x);
		}
		else {
			return find_min_index(mid + 1, end, 2 * node + 2, x);
		}
	}

	// log(n) + log(n)
	// index
	int query(int start, int end, int node, int l, int r, int x) {
		// complete overlap
		if (start >= l && end <= r) {
			if (st[node] <= x) {
				return find_min_index(start, end, node, x);
			}
			else {
				return INT_MAX;
			}
		}
		// no overlap
		if (start > r || end < l) {
			return INT_MAX;
		}
		// partial overlap
		int mid = (start + end) / 2;
		int left_query = query(start, mid, 2 * node + 1, l, r, x);
		int right_query = query(mid + 1, end, 2 * node + 2, l, r, x);
		return min(left_query, right_query);
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

	// nlog(n)
	St.build(0, n - 1, 0, v);

	// cout << St.query(0, n - 1, 0, 1, 6) << '\n';
	int m;
	cin >> m;
	// m * log(n)
	while (m--) {
		int q;
		cin >> q;
		if (q == 1) {
			int l, x;
			cin >> l >> x;
			l--;
			// log(n)
			St.update(0, n - 1, 0, l, x);
		}
		else {
			int l, r, x;
			cin >> l >> r >> x;
			l--; r--;
			// log(n)
			if (St.min_query(0, n - 1, 0, l, r) > x) {
				cout << -1 << '\n';
			}
			else {
				// 2*log(n)
				cout << St.query(0, n - 1, 0, l, r, x) + 1 << '\n';
			}
		}





	}


	return 0;
}