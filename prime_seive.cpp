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
int prime[N];

// O(n log(log(n)))
void seive() {
	for (int i = 2; i < N; i++) prime[i] = 1;
	// cancel out multiples of every number
	for (int i = 2; i * i < N; i++) {
		// don't cancel multiples of composite
		if (prime[i] == 0) continue;

		// iterate over multiples of i
		// not needed for i > sqrt(N)
		for (int j = i * i; j < N; j += i) {
			// j is a multiple of i except (i)
			prime[j] = 0;
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	seive();

	for (int i = 2; i < N; i++) {
		if (prime[i]) {
			// db(i);
		}
	}

	int m;
	cin >> m;

	cout << prime[m];

	return 0;
}