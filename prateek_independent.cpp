#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];

int memo[N][2];
int mod = 1e9 + 7;

// 1 -> white
// 0 -> black
int dp(int cur, int par, int white) {
	if (memo[cur][white] != -1) return memo[cur][white];

	int ans = 1;
	for (auto child : gr[cur]) {
		if (child != par) {
			if (white) {
				ans *= (dp(child, cur, 0) + dp(child, cur, 1));
				ans %= mod;
			}
			else {
				ans *= dp(child, cur, 1);
				ans %= mod;
			}
		}
	}
	return memo[cur][white] = ans;
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

	cout << (dp(1, 0, 0) + dp(1, 0, 1)) % mod;


	return 0;
}