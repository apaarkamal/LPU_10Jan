#include<bits/stdc++.h>
#define int long long int

using namespace std;

class Solution {
public:
	int mod = 1e9 + 7;

	// O(1)
	int lcm(int a, int b) {
		int lcm = a * b;
		lcm /= gcd(a, b);
		return lcm;
	}

	// O(1)
	int giveDivisorsTillM(int a, int b, int m) {
		int div_a = m / a;
		int div_b = m / b;
		int div_a_b = m / lcm(a, b);
		return div_a + div_b - div_a_b;
	}

	// O(log(n*min(a,b)))
	int nthMagicalNumber(int n, int a, int b) {

		// [2....{(4*10^4)*10^9}]
		int left = min(a, b), right = n * min(a, b);

		// lower bound
		while (left < right) {
			int mid = (left + right) / 2;
			if (giveDivisorsTillM(a, b, mid) >= n) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}

		return left % mod;
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solution H;
	int n, a, b;
	cin >> n >> a >> b;
	cout << H.nthMagicalNumber(n, a, b);
	// cout << H.giveDivisorsTillM(2, 3, 20);

	return 0;
}