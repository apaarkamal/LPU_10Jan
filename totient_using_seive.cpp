#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 100;
int tot[N], prime[N];

// O(Nlog(N))
void seive() {
	for (int i = 2; i < N; i++) prime[i] = 1;
	for (int i = 1; i < N; i++) tot[i] = i;

	for (int i = 2; i < N; i++) {
		if (prime[i] == 0) continue;
		// only perform the totient calculation for primes
		for (int j = i; j < N; j += i) {
			tot[j] *= (i - 1);
			tot[j] /= i;

			if (j >= i * 2) {
				prime[j] = 0;
			}
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	seive();

	for (int i = 1; i < N; i++) {
		cout << i << " " << prime[i] << " " << tot[i] << '\n';
	}

	return 0;
}