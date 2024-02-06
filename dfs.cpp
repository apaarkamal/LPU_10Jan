#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5;
vector<int> gr[N];
int parent[N];
vector<int> tour;
pair<int, int> tour_index[N];
int dis_from_root[N];
int sub_sum[N], min_subtree[N], dep[N];


void dfs(int cur, int par) {
	parent[cur] = par;
	sub_sum[cur] = min_subtree[cur] = cur;

	// dis_from_root[cur] = dis_from_root[par] + 1;

	tour_index[cur].first = tour.size();
	tour.push_back(cur);

	for (auto child : gr[cur]) {
		if (child != par) {

			dis_from_root[child] = dis_from_root[cur] + 1;

			dfs(child, cur);

			sub_sum[cur] += sub_sum[child];
			min_subtree[cur] = min(min_subtree[cur], min_subtree[child]);

		}
	}

	// exit
	tour_index[cur].second = tour.size();
	tour.push_back(cur);
}

// is x ancestor of y
bool isAncestor(int x, int y) {
	return
	    (tour_index[x].first <= tour_index[y].first)
	    && (tour_index[y].second <= tour_index[x].second);
}

int subTreeSum(int cur) {
	int first_index = tour_index[cur].first;
	int second_index = tour_index[cur].second;

	int sum = 0;

	for (int i = first_index; i <= second_index; i++) {
		sum += tour[i];
	}

	return sum / 2;
}

void pathToRoot(int cur) {
	while (cur) {
		cout << cur << " ";
		cur = parent[cur];
	}
}

int LCA(int x, int y) {
	if (x == y) return x;

	// make x above y
	if (dis_from_root[x] > dis_from_root[y]) {
		swap(x, y);
	}

	// y is below x
	while (dis_from_root[y] != dis_from_root[x]) {
		y = parent[y];
	}

	while (x != y) {
		x = parent[x];
		y = parent[y];
	}

	return x;
}

int distanceBetween(int x, int y) {
	int lca = LCA(x, y);
	return dis_from_root[x] + dis_from_root[y] - 2 * dis_from_root[lca];
}

// return the diameter in the subtree of cur
int diameter(int cur, int par) {

	vector<int> dep_child;
	int diameter_from_subtree = 0;

	for (auto x : gr[cur]) {
		if (x != par) {
			diameter_from_subtree = max(diameter(x, cur), diameter_from_subtree);
			dep[cur] = max(dep[cur], dep[x] + 1);
			dep_child.push_back(dep[x]);
		}
	}

	sort(dep_child.begin(), dep_child.end());
	reverse(dep_child.begin(), dep_child.end());

	int max_depth_1 =  (dep_child.size() > 0 ? dep_child[0] + 1 : 0);
	int max_depth_2 = (dep_child.size() > 1 ? dep_child[1] + 1 : 0);

	int max_path_from_cur_node = max_depth_1 + max_depth_2;

	// max of maximum length passing through the cur node
	// or maximum lengthof path not passing through the cur node
	return max(max_path_from_cur_node, diameter_from_subtree);
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

	cout << diameter(2, 0);

	// dis_from_root[1] = 0;
	// dfs(1, 0);


	// cout << LCA(7, 3) << '\n';

	// cout << distanceBetween(8, 5) << '\n';

	// pathToRoot(8);

	// int max_dis_root = *max_element(dis_from_root, dis_from_root + N);
	// for (int i = 1; i <= n; i++) {
	// 	dep[i] = max_dis_root - dis_from_root[i];
	// }



	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " " << parent[i] << '\n';
	// }

	// for (int i = 1; i <= n; i++) {
	// 	cout << i << " " << tour_index[i].first << " " << tour_index[i].second << '\n';
	// }

	// whether x is ancestor of y??
	// tour_index[x].first
	// <= tour_index[y].first
	// <= tour_index[y].second
	// <= tour_index[x].second

	// cout << isAncestor(7, 1);

	// cout << subTreeSum(2);

	return 0;
}