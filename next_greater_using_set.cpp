#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	pair<int, int> b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = {a[i], i};
	}

	sort(b, b + n);
	reverse(b, b + n);
	int next_greater[n];

	set<int> st;

	// O(n/logn)
	for (int i = 0; i < n; i++) {
		// cout << b[i].first << " " << b[i].second << '\n';
		auto it = st.upper_bound(b[i].second);
		if (it == st.end()) {
			// doesnt exist
			next_greater[b[i].second] = -1;
		}
		else {
			next_greater[b[i].second] = a[*it];
		}
		st.insert(b[i].second);
	}

	for (int i = 0; i < n; i++) {
		cout << next_greater[i] << " ";
	}







	return 0;
}