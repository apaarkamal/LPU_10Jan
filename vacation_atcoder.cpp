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

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int h[n][3];

	for (int i = 0; i < n; i++) {
		cin >> h[i][0] >> h[i][1] >> h[i][2];
	}

	int dp[n][3];
	dp[0][0] = h[0][0];
	dp[0][1] = h[0][1];
	dp[0][2] = h[0][2];


	for (int i = 1; i < n; i++) {
		for (int act = 0; act < 3; act++) {
			dp[i][act] = -1;
			for (int prev_act = 0; prev_act < 3; prev_act++) {
				if (act != prev_act) {
					dp[i][act] = max(dp[i - 1][prev_act], dp[i][act]);
				}
			}
			dp[i][act] += h[i][act];
		}
	}

	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});









	return 0;
}