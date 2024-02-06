#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5;
vector<int> gr[N], topo;
int vis[N];

void dfs(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			dfs(x);
		}
	}

	// leaving
	topo.push_back(cur);
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// DAG
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	reverse(topo.begin(), topo.end());

	for (auto x : topo) {
		cout << x << " ";
	}

	return 0;
}