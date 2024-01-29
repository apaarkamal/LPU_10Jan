#include<bits/stdc++.h>
#define int long long int

using namespace std;

bool binarySearch(int a[], int n, int x) {
	sort(a, a + n);

	int left = 0, right = n - 1;
	int index = 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			index = mid;
			return true;
		}
		if (a[mid] < x) {
			left = mid + 1;
		}
		if (a[mid] > x) {
			right = mid - 1;
		}
	}

	return false;
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

	if (binarySearch(a, n, x)) {
		cout << "yes found";
	}
	else {
		cout << "not found";
	}

	// sort(a, a + n);

	// if (binary_search(a, a + n, x)) {
	// 	cout << "yes found";
	// }
	// else {
	// 	cout << "not found";
	// }


	return 0;
}