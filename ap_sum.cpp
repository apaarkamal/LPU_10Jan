#include<bits/stdc++.h>
#define int long long int

using namespace std;

void prinAP(int a, int k, int n) {
	while (n--) {
		cout << a << " ";
		a += k;
	}
	cout << '\n';
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int sum, k;
	cin >> sum >> k;

	for (int n = 1; n <= 2 * sum; n++) {
		// i*j=n;
		if ((2 * sum) % n == 0) {
			// cout << i << " " << n / i << '\n';

			// i->lengt of ap
			// what is first term? a
			int j = (2 * sum) / n;
			if ((j - (n - 1)*k) % 2 == 0) {
				prinAP((j - (n - 1)*k) / 2, k, n);
				// cout << n << " " << (j - (n - 1)*k) / 2 << '\n';
			}

		}
	}


	return 0;
}