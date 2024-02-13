#include<bits/stdc++.h>
#define int long long int

using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 1e5 + 1;

vector<int> gr[N];
int cnt = 0;

int memo[N][2];

// O(n*2)
int dp(int cur, int par, int take) {
	if (memo[cur][take] != -1) return memo[cur][take];

	cnt++;

	int ans = take;
	for (auto child : gr[cur]) {
		if (child != par) {
			if (take) {
				// cout << child << '\n';
				ans += min(dp(child, cur,  0), dp(child, cur, 1));
			}
			else {
				ans += dp(child, cur, 1);
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

	cout << min(dp(1, 0, 0), dp(1, 0, 1)) << '\n';

	cout << cnt << '\n';


	return 0;
}