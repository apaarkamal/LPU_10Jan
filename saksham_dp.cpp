#include<bits/stdc++.h>
#define int long long int

using namespace std;


int f(int n, int h[], int memo[]) {
	if (n == 1) return 0;
	if (n == 2) return abs(h[1] - h[2]);

	if (memo[n] != -1) return memo[n];

	// n-1
	int cost1 = f(n - 1, h, memo) + abs(h[n - 1] - h[n]);
	// n-2
	int cost2 = f(n - 2, h, memo) + abs(h[n - 2] - h[n]);

	return memo[n] = min(cost1, cost2);
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int h[n + 1], memo[n + 1];
	h[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	// f[3] -> f[2] (20) + 10
	// f[3] -> f[1] (0) + 30
	// f[2] -> 20
	// f[3] = 30 + 20
	// f[2] = 20 + 10

	memset(memo, -1, sizeof(memo));
	cout << f(n, h, memo);

	return 0;
}