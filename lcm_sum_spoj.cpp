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

const int N = 1e7 + 1;
int tot[N], prime[N], res[N];

// totient function
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
		for (int j = i; j < N; j += i) {
			// i is a divisor of j
			res[j] += (j / i) * tot[j / i];
		}
	}

	for (int i = 0; i < N; i++) {
		res[i]--;
		res[i] *= i;
		res[i] /= 2;
		res[i] += i;
	}

	// db(res[2]);
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	seive();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << res[n] << '\n';
	}


	return 0;
}