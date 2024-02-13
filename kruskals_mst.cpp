#include<bits/stdc++.h>
#define int long long int

using namespace std;

struct DSU {
	vector<int> par, sz, mx, mn;
	int components;
	DSU(int n) {
		components = n;
		par.resize(n + 1);
		mx.resize(n + 1);
		mn.resize(n + 1);
		sz.resize(n + 1, 1);
		for (int i = 0; i <= n; i++) {
			par[i] = mx[i] = mn[i] = i;
		}
	}

	int getSuperPar(int n) {
		if (n == par[n]) return n;
		return par[n] = getSuperPar(par[n]);
	}

	int unite(int x, int y) {
		x = getSuperPar(x);
		y = getSuperPar(y);
		if (x != y) {
			par[x] = par[y];
			sz[y] += sz[x];
			sz[x] = 0;
			// min. and max
			mn[y] = min(mn[y], mn[x]);
			mx[y] = max(mx[y], mx[x]);
			// mn[x] = mx[x] = x;

			components--;

			return 1;
		}
		return 0;
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

	int getMin(int x) {
		return mn[getSuperPar(x)];
	}

	int getMax(int x) {
		return mx[getSuperPar(x)];
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges;
	// {w, x, y};
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edges.push_back({w, x, y});
	}

	sort(edges.begin(), edges.end());

	DSU H(n);

	int mst = 0;

	for (auto edge : edges) {
		// cout << edge[0] << " " << edge[1] << " " << edge[2] << '\n';
		int w = edge[0];
		int x = edge[1];
		int y = edge[2];
		if (!H.isConnected(x, y)) {
			mst += w;
			H.unite(x, y);
		}
	}

	cout << mst << '\n';


	return 0;
}