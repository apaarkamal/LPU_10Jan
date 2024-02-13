#include<bits/stdc++.h>
#define int long long int

using namespace std;

vector<int> findSub(int a, int b, int c) {
	vector<int> res;
	res.push_back(a);
	res.push_back(b);
	res.push_back(c);
	res.push_back(a + b);
	res.push_back(a + c);
	res.push_back(b + c);
	res.push_back(a + b + c);
	sort(res.begin(), res.end());
	return res;
}

void solve() {
	vector<int> b(7);
	for (int i = 0; i < 7; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 7; j++) {
			for (int k = j + 1; k < 7; k++) {
				vector<int> c = findSub(b[i], b[j], b[k]);
				if (b == c) {
					cout << b[i] << " " << b[j] << " " << b[k] << '\n';
					return;
				}
			}
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}