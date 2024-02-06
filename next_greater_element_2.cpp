#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	n *= 2;
	vector<int> a(n), next_greater(n);
	for (int i = 0; i < n / 2; i++) {
		cin >> a[i];
		a[i + n / 2] = a[i];
	}

	// O(N)
	// next greater element
	stack<int> St;
	for (int i = 0; i < n; i++) {

		// decreasing stack
		while (!St.empty() && a[St.top()] < a[i]) {
			next_greater[St.top()] = a[i];
			St.pop();
		}

		St.push(i);
	}

	while (!St.empty()) {
		next_greater[St.top()] = -1;
		St.pop();
	}

	for (int i = 0; i < n / 2; i++) {
		cout << next_greater[i] << " ";
	}






	return 0;
}