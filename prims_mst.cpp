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

const int N = 1e5 + 1;
vector<pair<int, int>> gr[N];

int prims_mst(int source, int n) {
	vector<int> vis(n + 1, 0);
	int mst = 0;

	// min heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	// push the source node initially to start
	Q.push({0, source});

	while (!Q.empty()) {
		int cur = Q.top().second;
		int edge = Q.top().first;
		Q.pop();

		if (vis[cur]) continue;
		// otherwise visit it and mark the edge
		vis[cur] = 1;
		mst += edge;
		// add all new discovered esges with their paths into
		// the heap
		for (auto adj : gr[cur]) {
			Q.push({adj.second, adj.first});
		}
	}
	return mst;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, w});
	}

	cout << prims_mst(0, n);




	return 0;
}