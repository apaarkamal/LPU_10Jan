#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5 + 1;

int prime[N], prime_sum[N];
vector<int> prime_list[N];

void seive() {
	for (int i = 2; i < N; i++) prime[i] = 1, prime_sum[i] = 0;


	for (int i = 2; i < N; i++) {
		if (prime[i] == 0) continue;
		// i is a prime
		prime_sum[i] = i;
		prime_list[i].push_back(i);
		for (int j = i * 2; j < N; j += i) {
			prime[j] = 0;
			prime_sum[j] += i;
			prime_list[j].push_back(i);
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	seive();

	// for (int i = 2; i < 100; i++) {
	// 	cout << i << " -> ";
	// 	for (auto x : prime_list[i]) {
	// 		cout << x << " ";
	// 	} cout << '\n';
	// }

	for (int i = 2; i < 1000; i++) {
		cout << i << " sum of primes of i ->" << prime_sum[i] << '\n';
	}



	return 0;
}