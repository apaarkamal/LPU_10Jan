#include<bits/stdc++.h>
#define int long long int

using namespace std;

string s, t;
int memo[3001][3001];

// O(n*m)
int dp(int i, int j) {
	if (i == s.size()) return 0;
	if (j == t.size()) return 0;

	if (memo[i][j] != -1) return memo[i][j];

	if (s[i] == t[j]) {
		return memo[i][j] = 1 + dp(i + 1, j + 1);
	}
	else {
		return memo[i][j] = max(dp(i + 1, j), dp(i, j + 1));
	}
}

// length of LCS
void trace_back(int i, int j) {
	if (i == s.size() || j == t.size()) return;

	if (dp(i, j) == 1 + dp(i + 1, j + 1)) {
		cout << s[i];
		trace_back(i + 1, j + 1);
	}
	else {
		if (dp(i, j) == dp(i + 1, j)) {
			trace_back(i + 1, j);
		}
		else {
			trace_back(i, j + 1);
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> s >> t;

	memset(memo, -1, sizeof(memo));

	// cout << dp(0, 0);

	trace_back(0, 0);

	return 0;
}