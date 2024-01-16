#include<bits/stdc++.h>
#define int long long int

using namespace std;

void printAllDivisors(int n) {
	// O(n)
	// for (int i = 1; i <= n; i++) {
	// 	if (n % i == 0) {
	// 		cout << i << '\n';
	// 	}
	// }

	// O(sqrt(n))
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			cout << i << " " << n / i << '\n';
		}
	}

}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	printAllDivisors(n);


	return 0;
}