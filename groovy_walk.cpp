#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int mod = 1000000007, N =  1e5 + 1;
int fact[N], invfact[N];
inline int add(int x, int y) { x += y; return x % mod;}
inline int sub(int x, int y) { x -= y; x %= mod; x += mod; return x % mod;}
inline int mul(int x, int y) { return  (x * y) % mod;}
inline int powr(int a, int b) {
	int x = 1 % mod;
	b %= (mod - 1);
	while (b) {
		if (b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a) { return powr(a, mod - 2);}
void pre() {
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for (int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}

inline int C(int n, int k) {
	if (n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int numberofways(int x1, int y1, int x2, int y2) {
	return C(x2 - x1 + y2 - y1, x2 - x1);
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// O(a)
	pre();

	int a, b;
	cin >> a >> b;

	int ans = 0;

	// O(a)
	int i = a, j = 1;
	while (i >= 0 && j <= a) {
		int centre = (a + 1) / 2;
		// centre, centre
		if (abs(centre - i) > b) {
			ans += numberofways(1, 1, i, j) * numberofways(i, j, a, a);
			ans %= mod;
			// cout << i << " " << j << '\n';
		}
		i--; j++;
	}

	cout << ans << '\n';


	return 0;
}