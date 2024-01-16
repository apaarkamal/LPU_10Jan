#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int n;
	cin >> n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			cout << i << '\n';
			// i is a divisor
			// first i will be a prime
			while (n % i == 0) {
				n = n / i;
			}
		}
	}

	// if the number is prime then print it
	if (n > 1) {
		cout << n;
	}

	return 0;
}