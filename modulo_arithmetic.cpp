#include<bits/stdc++.h>
#define int long long int

using namespace std;

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

// (a^b)%p
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

// a^(p-2) from fermat's little theorem
int inv(int a) {
	return Power(a, p - 2);
}

// (a/b)%p
int divmod(int a, int b) {
	return mulmod(a, inv(b));
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cout << addmod(2, 3) << '\n';

	cout << submod(4, 8) << '\n';

	cout << mulmod(4, 8) << '\n';

	cout << divmod(10, 2) << '\n';


	return 0;
}