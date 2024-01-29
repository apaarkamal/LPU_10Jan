#include<bits/stdc++.h>
#define int long long int

using namespace std;

class Solution {
public:

	// 1 d
	// O(mlog(m))
	int findSubarraySumEqualToTarget(int c[], int m, int target) {
		map<int, int> mp;
		int pref = 0, ans = 0;
		mp[pref]++;
		for (int i = 0; i < m; i++) {
			pref += c[i];
			ans += mp[target - pref];
			mp[pref]++;
		}
		return ans;
	}

	// O(n*n*(m+mlog(m)))
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int n = matrix.size(), m = matrix[0].size(), ans = 0;

		// iterate over all pairs of rows
		for (int l1 = 0; l1 < n; l1++) {
			int c[m];
			memset(c, 0, sizeof(c));
			for (int l2 = l1; l2 < n; l2++) {
				// prepare the c array
				for (int j = 0; j < m; j++) {
					c[j] += matrix[l2][j];
				}

				// O(mlog(m))
				ans += findSubarraySumEqualToTarget(c, m, target);

			}
		}

		return ans;
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k;
	cin >> k;

	vector<vector<int>> matrix;
	matrix = {
		{1, -1},
		{ -1, 1}
	};

	Solution H;
	cout << H.numSubmatrixSumTarget(matrix, k);


	return 0;
}