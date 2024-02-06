#include<bits/stdc++.h>
#define int long long int

using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

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

	// cout << H.components << '\n';

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " " << H.getMin(i) << " " << H.getMax(i) << '\n';
	// }

	int cnt = 0;

	int l = 1;
	while (l <= n) {
		// minimum node in the component
		int r = l;
		while (H.sizeComponent(l) != (H.getMax(l) - H.getMin(l) + 1)) {
			cnt += H.unite(l, r);
			// db(l, r, H.getMin(l), H.getMax(l));
			r++;
		}
		// db(l, r);
		l = r + 1;
	}

	cout << cnt << '\n';


	return 0;
}