#include<bits/stdc++.h>
#define int long long int

using namespace std;

struct DSU {
	vector<int> par, sz;
	int components;
	DSU(int n) {
		components = n;
		par.resize(n + 1);
		sz.resize(n + 1, 1);
		for (int i = 0; i <= n; i++) par[i] = i;
	}

	int getSuperPar(int n) {
		if (n == par[n]) return n;
		return par[n] = getSuperPar(par[n]);
	}

	void unite(int x, int y) {
		x = getSuperPar(x);
		y = getSuperPar(y);
		if (x != y) {
			par[x] = par[y];
			sz[y] += sz[x];
			sz[x] = 0;
			components--;
		}
	}

	bool isConnected(int x, int y) {
		return getSuperPar(x) == getSuperPar(y);
	}

	int sizeComponent(int n) {
		return sz[getSuperPar(n)];
	}

	int TotalComponents() {
		return components;
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	DSU H(n);

	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		H.unite(x, y);
	}










	return 0;
}