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

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector<vector<char>> mat =
	{
		{'O', 'M', 'O', 'O', 'X'},
		{'O', 'X', 'X', 'O', 'M'},
		{'O', 'O', 'O', 'O', 'O'},
		{'O', 'X', 'X', 'X', 'O'},
		{'O', 'O', 'M', 'O', 'O'},
		{'O', 'X', 'X', 'M', 'O'}
	};

	int n = mat.size(), m = mat[0].size();

	int dis[n][m], vis[n][m];
	memset(dis, -1, sizeof(dis));
	memset(vis, 0, sizeof(vis));

	// x, y
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'M') {
				Q.push({i, j});
				dis[i][j] = 0;
				vis[i][j] = 1;
				// db(i, j);
			}
		}
	}

	int dx[4] = { -1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		int x = cur.first, y = cur.second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x >= 0 && new_x < n
			        && new_y >= 0 && new_y < m
			        && !vis[new_x][new_y]
			        && mat[new_x][new_y] != 'X') {

				vis[new_x][new_y] = 1;
				dis[new_x][new_y] = dis[x][y] + 1;
				Q.push({new_x, new_y});
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dis[i][j] << '\t';
		} cout << '\n';
	}






	return 0;
}