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

int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};

int getDivisorsOfFirstKPrimes(int n, int k) {
	int result = 0;
	for (int num = 1; num < (1 << k); num++) {
		int lcm = 1, parity = 0;
		for (int bit = 0; bit < k; bit++) {
			if ((num >> bit) & 1) {
				lcm *= primes[bit];
				parity++;
			}
		}
		// cout << lcm << '\n';
		int divisible = n / lcm;

		// db(lcm, n, divisible, parity);

		// inclusion - exclusion principle
		if (parity % 2 == 0) {
			// even
			result -= divisible;
		}
		else {
			result += divisible;
		}
	}
	return result;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;

	cout << getDivisorsOfFirstKPrimes(n, k);

	return 0;
}