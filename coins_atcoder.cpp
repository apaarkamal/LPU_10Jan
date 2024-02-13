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

const int N = 3001;
double prob[N];
double memo[N][N];

// independent variable? - 2
// O(N*N)
double dp(int i, int heads) {
	if (i == 0) return 1;

	if (memo[i][heads] != -1) return memo[i][heads];

	int tails = i - heads;
	double res = 0;
	if (heads) {
		res += prob[i] * dp(i - 1, heads - 1);
	}
	if (tails) {
		res += (1 - prob[i]) * dp(i - 1, heads);
	}
	return memo[i][heads] = res;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> prob[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			memo[i][j] = -1;
		}
	}

	double ans = 0;
	for (int heads = (n / 2) + 1; heads <= n; heads++) {
		ans += dp(n, heads);
	}


	cout << setprecision(10) << fixed;

	cout << ans;





	return 0;
}