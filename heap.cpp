#include<bits/stdc++.h>
#define int long long int

using namespace std;


class Heap {
	vector<int> v;
public:
	Heap(vector<int> arr) {
		v = arr;
	}

	// compare returns true for a valid (par, child)
	bool compare(int a, int b) {
		// > for max heap
		// < for min heap
		return a > b;
	}

	// O(logn)
	void heapify(int cur) {
		int left = 2 * cur + 1;
		int right = 2 * cur + 2;

		int min_idx = cur;

		if (left < v.size() && compare(v[left], v[min_idx])) {
			min_idx = left;
		}
		if (right < v.size() && compare(v[right], v[min_idx])) {
			min_idx = right;
		}

		if (min_idx != cur) {
			// heapify
			swap(v[min_idx], v[cur]);
			heapify(min_idx);
		}
	}

	// O(n/2*(logn))
	void build() {
		int last_par = ((v.size() - 1) - 1) / 2;
		for (int i = last_par; i >= 0; i--) {
			heapify(i);
		}
	}

	// O(1)
	int top() {
		return v[0];
	}

	// O(logn)
	void pop() {
		swap(v[0], v.back());
		v.pop_back();
		heapify(0);
	}

	// log(n)
	void push(int x) {
		v.push_back(x);

		int cur = v.size() - 1;
		int par = (cur - 1) / 2;

		while (!compare(v[par], v[cur]) && cur > 0) {
			swap(v[cur],  v[par]);

			cur = par;
			par = (cur - 1) / 2;
		}

	}

	// O(n)
	void print() {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		} cout << '\n';
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

	Heap H(v);

	H.build();
	// H.print();

	H.pop();

	cout << H.top() << '\n';

	H.push(8);

	// H.print();
	cout << H.top() << '\n';

	return 0;
}