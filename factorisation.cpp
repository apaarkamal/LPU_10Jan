#include<bits/stdc++.h>
#define int long long int

using namespace std;

// O(sqrt(n))
vector<pair<int, int>> factorisation(int n) {
	vector<pair<int, int>> res;

	if (n % 2 == 0) {
		int cnt = 0;
		while (n % 2 == 0) n /= 2, cnt++;
		res.push_back({2, cnt});
	}

	for (int i = 3; i * i <= n; i += 2) {

		if (n % i == 0) {
			int cnt = 0;
			// count number of times i dividing
			while (n % i == 0) {
				n /= i;
				cnt++;
			}

			res.push_back({i, cnt});
		}
	}
	// prime number case
	if (n > 1) {
		res.push_back({n, 1});
	}

	return res;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<pair<int, int>> res = factorisation(n);

	for (auto x : res) {
		cout << x.first << " " << x.second << '\n';
	}

	return 0;
}