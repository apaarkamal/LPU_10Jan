#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5;

vector<int> gr[N], components[N];
int vis[N], col[N];

void dfs(int cur, int component) {
	vis[cur] = 1;
	components[component].push_back(cur);
	col[cur] = component;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			dfs(x, component);
		}
	}
}

int connectedComponents(int n) {
	int component = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			component++;
			dfs(i, component);
		}
	}
	return component;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	cout << connectedComponents(n) << '\n';


	for (int i = 1; i <= n; i++) {
		cout << i << " " << col[i] << '\n';
	}

	return 0;
}