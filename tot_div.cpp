#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e6 + 1;
int sum_div[N];
int sum_odd_even[N];
int total_div[N];

// seive
void seive() {
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			// {i,j} -> j is a multiple of i
			// {i,j} -> i is a divisor of j
			sum_div[j] += i;
			total_div[j]++;
			if (i % 2 == 0) {
				// i was an even divisor of j
				sum_odd_even[j] -= i;
			}
			else {
				// i was odd divisor of j
				sum_odd_even[j] += i;
			}

		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	seive();

	// for (int i = 1; i < 100; i++) {
	// 	cout << i << " " << total_div[i] << '\n';
	// }

	for (int i = 1; i < N; i++) {
		if (total_div[i] == 2) {
			// i is a prime number
			cout << i << '\n';
		}
	}

	return 0;
}