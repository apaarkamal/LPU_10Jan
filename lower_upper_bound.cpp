#include<bits/stdc++.h>
#define int long long int

using namespace std;

int lowerBound(int a[], int n, int x) {
	sort(a, a + n);

	int left = 0, right = n;
	// if left == right
	// -> that means I got the lower_bound
	while (left < right) {
		int mid = (left + right) / 2;
		if (x <= a[mid]) {
			right = mid;
		}
		else {
			// x > a[mid]
			left = mid + 1;
		}
	}

	// left == right == lower_bound
	return left;
}

int upperBound(int a[], int n, int x) {
	sort(a, a + n);

	int left = 0, right = n;
	// if left == right
	// -> that means I got the lower_bound
	while (left < right) {
		int mid = (left + right) / 2;
		if (a[mid] <= x) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	// left == right == upper bound
	return left;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int x;
	cin >> x;

	cout << lowerBound(a, n, x) << '\n';
	// in-built function
	// cout << lower_bound(a, a + n, x) - a;

	cout << upperBound(a, n, x) << '\n';
	// in - built function
	// cout << upper_bound(a, a + n, x) - a;

	// count of X without using extra memory
	cout << upperBound(a, n, x) - lowerBound(a, n, x);








	return 0;
}