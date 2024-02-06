#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5;
vector<int> gr[N], topo, grr[N];
int vis[N], reverse_visited[N];

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

void reversedfs(int cur) {
	cout << cur << " ";
	reverse_visited[cur] = 1;
	for (auto x : grr[cur]) {
		if (!reverse_visited[x]) {
			reversedfs(x);
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
		// reverse graph
		grr[y].push_back(x);
	}

	// O(n)
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
		}
	}

	// O(n)
	reverse(topo.begin(), topo.end());

	for (auto x : topo) {
		cout << x << " ";
	} cout << '\n';


	// source -> sink

	// O(n)
	for (int i = 0; i < topo.size(); i++) {
		if (!reverse_visited[topo[i]]) {
			reversedfs(topo[i]);
			cout << '\n';
		}
	}







	return 0;
}