#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// bottom up
	int n;
	cin >> n;
	int h[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}

	int dp[n];
	dp[1] = 0;
	dp[2] = abs(h[1] - h[2]);

	for (int i = 3; i <= n; i++) {
		dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]),
		            dp[i - 2] + abs(h[i - 2] - h[i]));
	}

	cout << dp[n];








	return 0;
}