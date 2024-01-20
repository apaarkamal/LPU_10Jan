#include<bits/stdc++.h>
#define int long long int
#define P pair<int,int>
#define pb push_back

using namespace std;

vector<P> factorisation(int n) {
	vector<P> fac;
	int cnt = 0;
	while (n % 2 == 0) {
		n /= 2;
		cnt++;
	}
	if (cnt) fac.pb({2, cnt});
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			cnt = 0;
			while (n % i == 0) {
				n /= i;
				cnt++;
			}
			fac.pb({i, cnt});
		}
	}
	if (n > 1) {
		fac.pb({n, 1});
	}
	return fac;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<P> pf = factorisation(n);

		if (pf.size() == 1) {
			if (pf[0].second >= 6) {
				int first = pf[0].first;
				int second = pf[0].first * pf[0].first;
				int third = n / (first * second);
				cout << first << " " << second << " " << third << '\n';
			}
			else {
				cout << "NO\n";
			}
		}
		else if (pf.size() == 2) {
			int first = pf[0].first;
			int second = pf[1].first;
			int third = n / (first * second);
			if (third != first && third != second) {
				cout << first << " " << second << " " << third << '\n';
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			int first = pf[0].first;
			int second = pf[1].first;
			int third = n / (first * second);

			cout << first << " " << second << " " << third << '\n';
		}

	}


	return 0;
}