#include<bits/stdc++.h>
#define int long long int

using namespace std;

// O(n)
int GivePainters(int t, int boards[], int n) {
	// t time they will paint  max t units of board
	int painters = 1;
	int units = 0;
	for (int i = 0; i < n; i++) {
		if (units + boards[i] <= t) {
			units += boards[i];
		}
		else {
			painters++;
			units = boards[i];
		}
	}
	return painters;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k, mx = 0, sum = 0;;
	cin >> n >> k;
	int boards[n];

	for (int i = 0; i < n; i++) {
		cin >> boards[i];
		mx = max(mx, boards[i]);
		sum += boards[i];
	}

	// cout << GivePainters(11, boards, n);
	// O(max(boards[i]) ..... sum(boards[i]))
	// O(10^9 ..... 10^14)
	// for (int i = 6; i <= 19; i++) {
	// 	cout << i << " " << GivePainters(i, boards, n) << '\n';
	// }

	int left = mx;
	int right = sum;

	// O(log(10^14) * O(n))
	while (left < right) {
		int mid = (left + right) / 2;

		if (GivePainters(mid, boards, n) <= k) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << left;



	return 0;
}