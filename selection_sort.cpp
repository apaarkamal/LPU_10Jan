#include<bits/stdc++.h>
#define int long long int

using namespace std;

void selectionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_idx = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		swap(a[i], a[min_idx]);
	}
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

	selectionSort(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	return 0;
}