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

const int N = 1e6 + 1;
int tot[N], prime[N], res[N], sum[N];

// O(nlog(n))
void seive() {
	for (int i = 2; i < N; i++) prime[i] = 1;
	for (int i = 1; i < N; i++) tot[i] = i;

	for (int i = 2; i < N; i++) {
		if (prime[i] == 0) continue;
		// only perform the totient calculation for primes
		for (int j = i; j < N; j += i) {
			tot[j] *= (i - 1);
			tot[j] /= i;

			if (j >= i * 2) {
				prime[j] = 0;
			}
		}
	}

	// computed the totient
	for (int i = 1; i < N; i++) {
		for (int j = i * 2; j < N; j += i) {
			// i is a divisor of j
			res[j] += i * tot[j / i];
		}
	}


	for (int i = 2; i < N; i++) {
		sum[i] = sum[i - 1] + res[i];
	}

	// db(sum[10]);
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	seive();

	int n;
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		cout << sum[n] << '\n';
	}


	return 0;
}