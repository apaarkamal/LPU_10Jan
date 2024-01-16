#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e7;
int p = 1e9 + 7, fact[N];

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

int nCr(int n, int r) {
	if (n < 0 || r < 0) return -1;
	if (r > n) return -1;

	int fac_n = fact[n];
	int fact_r = fact[r];
	int fact_n_r = fact[n - r];

	int res = mulmod(fac_n, inv(fact_r));
	res = mulmod(res, inv(fact_n_r));

	return res;
}

void pre_compute() {
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = mulmod(i, fact[i - 1]);
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	pre_compute();

	int n, r;
	cin >> n >> r;

	cout << nCr(n, r);


	return 0;
}