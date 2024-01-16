#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	int a[n + 1][m + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	int pref[n + 1][m + 1];
	memset(pref, 0, sizeof(pref));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] = pref[i - 1][j]
			             + pref[i][j - 1]
			             - pref[i - 1][j - 1]
			             + a[i][j];
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		cout << pref[x][y] -
		     pref[a - 1][y] -
		     pref[x][b - 1] +
		     pref[a - 1][b - 1] << '\n';
	}













	return 0;
}