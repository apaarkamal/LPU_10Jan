#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 2e5 + 1;

vector<int> gr[N];
int parent[N], bfs[N], idx[N];

void dfs(int cur, int par) {
	parent[cur] = par;
	for (auto x : gr[cur]) {
		if (x != par) {
			dfs(x, cur);
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		cin >> bfs[i];
		idx[bfs[i]] = i;
	}

	dfs(1, 0);

	for (int i = 1; i < n - 1; i++) {
		if (idx[parent[bfs[i]]]
		        > idx[parent[bfs[i + 1]]]) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";










	return 0;
}