class Solution {
public:
	vector<vector<int>> gr;
	vector<int> vis, topo;
	bool is_cycle = false;
	void dfs(int cur) {
		vis[cur] = 1;
		for (auto x : gr[cur]) {
			if (vis[x] == 0) {
				dfs(x);
			}
			else if (vis[x] == 1) {
				// backedge
				is_cycle = true;
			}
		}
		topo.push_back(cur);
		vis[cur] = 2;
	}
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		gr.resize(numCourses);
		for (int i = 0; i < prerequisites.size(); i++) {
			int a = prerequisites[i][0];
			int b = prerequisites[i][1];
			gr[b].push_back(a);
		}
		vis.resize(numCourses, 0);
		for (int i = 0; i < numCourses; i++) {
			if (!vis[i]) {
				dfs(i);
			}
		}
		reverse(topo.begin(), topo.end());
		if (is_cycle) {
			return {};
		}
		else {
			return topo;
		}
	}
};