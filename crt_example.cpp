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

int p = 1e9 + 7;
int addmod(int a, int b) {
	return (a % p + b % p) % p;
}
int submod(int a, int b) {
	return ((a % p - b % p) + p) % p;
}
int mulmod(int a, int b) {
	return (a % p * b % p) % p;
}
int Power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = mulmod(res, a);
		}
		a = mulmod(a, a);
		b >>= 1;
	}
	return res;
}
int inv(int a) {
	return Power(a, p - 2);
}
int divmod(int a, int b) {
	return mulmod(a, inv(b));
}

int findCRT(int n, int primes[], int remainder[]) {
	int lcm = 1, ans = 0;
	for (int i = 0; i < n; i++) {
		lcm *= primes[i];
	}

	for (int i = 0; i < n; i++) {
		int constant = lcm / primes[i];
		p = primes[i];
		int variable = mulmod(remainder[i], inv(constant));

		ans += constant * variable;
	}

	return ans % lcm;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int primes[n], remainder[n];
	for (int i = 0; i < n; i++) {
		cin >> primes[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> remainder[i];
	}

	cout << findCRT(n, primes, remainder);

	return 0;
}