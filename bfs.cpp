#include<bits/stdc++.h>
#define int long long int

using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " |"; __f(comma + 1, args...);
}

const int N = 1e5;

vector<int> gr[N];
int vis[N], dis[N];
int subtree_sum[N];

// O(n)
void bfs(int source) {
	queue<int> Q;

	Q.push(source);
	dis[source] = 0;
	vis[source] = 1;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		db(cur, dis[cur]);

		for (auto child : gr[cur]) {
			if (!vis[child]) {

				dis[child] = dis[cur] + 1;
				vis[child] = 1;
				Q.push(child);
			}
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	// O(n)
	bfs(1);
	// O(n)
	bfs(8);

	return 0;
}