#include<bits/stdc++.h>
#define int long long int

using namespace std;

class Solution {
public:
	int minJumps(vector<int>& arr) {
		int n = arr.size();

		vector<int> gr[n];
		for (int i = 0; i < n - 1; i++) {
			gr[i].push_back(i + 1);
			gr[i + 1].push_back(i);
		}

		map<int, vector<int>> mp;
		for (int i = 0; i < n; i++) {
			mp[arr[i]].push_back(i);
		}

		map<int, int> vis;

		int cur = n - 1;
		int mindis[n];
		for (int i = 0; i < n; i++) mindis[i] = INT_MAX;
		// mindis, cur
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

		// mindis, index
		Q.push({0, n - 1});
		while (!Q.empty()) {
			pair<int, int> top = Q.top();
			Q.pop();

			int cur = top.second;
			int dis = top.first;

			if (mindis[cur] != INT_MAX) continue;
			mindis[cur] = dis;

			// iterate in the graph
			for (auto x : gr[cur]) {
				Q.push({dis + 1, x});
			}
			// arr[x] == arr[cur]
			if (!vis[arr[cur]]) {
				vis[arr[cur]]++;
				for (auto x : mp[arr[cur]]) {
					if (x != cur) {
						Q.push({dis + 1, x});
					}
				}
			}
		}

		return mindis[0];
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Solution H;
	cout << H.minJumps(arr);


	return 0;
}