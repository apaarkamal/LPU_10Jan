#include<bits/stdc++.h>
#define int long long int

using namespace std;

// returns the number of cows if minimum distance is d
int placeCows(int a[], int n, int d) {
	int cow = 1; //a[0]
	int prev_cow = a[0];

	// start placing the cows from second stall if possible
	for (int i = 1; i < n; i++) {
		if (a[i] - prev_cow >= d) {
			cow++;
			prev_cow = a[i];
		}
	}

	return cow;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int n, c;
		cin >> n >> c;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a, a + n);

		// int ans = 0;
		// O(d*n)
		// range of d (0 ..... a[n-1]-a[0])
		// for (int d = 0; d <= a[n - 1] - a[0]; d++) {
		// 	int cows = placeCows(a, n, d);
		// 	if (cows >= c) {
		// 		ans = max(ans, d);
		// 	}
		// 	cout << d << " " << cows << '\n';
		// }
		// cout << ans;

		int left = 0, right = a[n - 1] - a[0];
		while (left < right) {
			int mid = (left + right) / 2;
			if (placeCows(a, n, mid) >= c) {
				// mid cannot be the upper bound
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}

		// left == right
		cout << left - 1 << '\n';
	}


	return 0;
}