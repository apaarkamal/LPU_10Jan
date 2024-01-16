#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n + 1];

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int pref[n + 1];
	pref[0] = 0;

	// O(n)
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] ^ a[i];
	}

	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		// O(1)
		cout << (pref[r] ^ pref[l - 1]) << '\n';
	}

	return 0;
}