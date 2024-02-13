#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5;

vector<int> gr[N];
int cnt = 0;

// sum of the subtree of cur
int dp(int cur, int par) {
	cnt++;
	int ans = cur;
	for (auto child : gr[cur]) {
		if (child != par) {
			ans += dp(child, cur);
		}
	}
	return ans;
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

	cout << dp(1, 0) << '\n';

	cout << cnt << '\n';

	return 0;
}