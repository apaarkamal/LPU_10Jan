#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e6 + 1;

// initially 0
int smallest_prime_divisor[N];

void seive() {
	for (int i = 2; i < N; i++) {
		for (int j = i; j < N; j += i) {
			if (smallest_prime_divisor[j] == 0) {
				smallest_prime_divisor[j] = i;
			}
		}
	}
}

// log(n)
vector<pair<int, int>> factorise(int n) {
	vector<pair<int, int>> res;
	while (n != 1) {
		int sp = smallest_prime_divisor[n];
		int cnt = 0;
		while (n % sp == 0) {
			n /= sp;
			cnt++;
		}
		res.push_back({sp, cnt});
	}
	return res;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	seive();

	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		auto prime_factors = factorise(n);
		for (auto x : prime_factors) {
			cout << x.first << " " << x.second << '\n';
		}
		cout << '\n';
	}

	// cout << pow(3, 7);

	return 0;
}