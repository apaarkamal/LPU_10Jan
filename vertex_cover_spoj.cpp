#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int memo[N][2];

// O(n)
int dp(int cur, int take, int par) {
	if (memo[cur][take] != -1) return memo[cur][take];
	int ans = take;
	for (auto child : gr[cur]) {
		if (child != par) {
			if (take) {
				ans += min(dp(child, 0, cur), dp(child, 1, cur));
			}
			else {
				ans += dp(child, 1, cur);
			}
		}
	}
	return memo[cur][take] = ans;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	memset(memo, -1, sizeof(memo));

	cout << min(dp(1, 0, 0), dp(1, 1, 0));


	return 0;
}