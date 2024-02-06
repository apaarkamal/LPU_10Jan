#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5;
vector<int> gr[N];
int vis[N];
bool is_cycle;

void dfs(int cur, int par) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (!vis[x]) {
			dfs(x, cur);
		}
		else if (x != par) {
			// backedge
			is_cycle = true;
		}
	}
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
		gr[y].push_back(x);
	}

	is_cycle = false;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 0);
		}
	}

	cout << is_cycle;






	return 0;
}