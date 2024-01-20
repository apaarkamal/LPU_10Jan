#include<bits/stdc++.h>
// #define int long long int

using namespace std;

class Solution {
public:
	vector<int> computePrefix(vector<int>& nums) {
		int n = nums.size();
		vector<int> pref(n, 0);
		pref[0] = nums[0];
		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1] + nums[i];
		}
		return pref;
	}
	int sum(vector<int>& pref, int l, int r) {
		int ans = pref[r];
		if (l > 0) ans -= pref[l - 1];
		return ans;
	}
	int maxFrequency(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> pref = computePrefix(nums);

		int res = 1;

		int i = 0, j = 0;

		while (j < n) {

			while ((long long int)((j - i + 1)*nums[j]) - sum(pref, i, j) > k) {
				// reduce the window size
				i++;
			}

			// valid i is found
			res = max(res, j - i + 1);

			j++;
		}

		return res;
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int k;
	cin >> k;

	Solution H;
	cout << H.maxFrequency(nums, k);







	return 0;
}