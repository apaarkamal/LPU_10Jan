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

const int N = 1e5;
vector<int> primes;
int composite[N];

// O(1e5log(1e5))
void seive() {
	for (int i = 2; i < N; i++) {
		if (composite[i] == 0) primes.push_back(i);
		for (int j = i * i; j < N; j += i) {
			composite[j] = 1;
		}
	}
}


int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	seive();

	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;

		// n-m+1 <= 1e5
		int is_prime[n - m + 1];
		for (int i = 0; i < n - m + 1; i++) is_prime[i] = 1;
		// is_prime[i] -> whether i+m is prime or not


		// cancel all the multiples of prime starting from [2..sqrt(n)]
		for (auto prime : primes) {
			// only cancel multiples of prime <= sqrt(n)
			if (prime * prime > n) break;

			// db(prime);

			int start;
			// if prime is in the range from m...n, then start
			// cancelling from prime*2
			if (prime >= m && prime <= n) start = prime * 2;
			else start = (m / prime) * prime;

			for (int i = start; i <= n; i += prime) {
				if (i >= m) {
					// mapping of i-m -> m
					is_prime[i - m] = 0;
				}
			}
		}

		for (int i = m; i <= n; i++) {
			if (is_prime[i - m] && i != 1) {
				cout << i << '\n';
			}
		}
		cout << '\n';
	}


	return 0;
}