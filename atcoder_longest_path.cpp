#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int memo[N];

// O(n)
int dp(int cur) {
	if (memo[cur] != -1) return memo[cur];
	int ans = 0;
	for (auto child : gr[cur]) {
		ans = max(ans, dp(child) + 1);
	}
	return memo[cur] = ans;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		// gr[y].push_back(x);
	}

	memset(memo, -1, sizeof(memo));

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp(i));
	}

	cout << ans;




	return 0;
}