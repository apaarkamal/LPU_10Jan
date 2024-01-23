#include<bits/stdc++.h>
#define int long long int

using namespace std;

class Solution {
public:
	// O(n)
	int cntLessThanX(int x, vector<int>& nums) {
		int cnt = 0;
		for (auto num : nums) {
			if (num <= x) cnt++;
		}
		return cnt;
	}
	// Time Complexity (n*log(n))
	// Space Complexity (k)
	// Are we modifying the array nums? -> NO
	int findDuplicate(vector<int>& nums) {
		int left = 1, right = nums.size();
		// LB (cnt(<=x) > x)
		while (left < right) {
			int mid = (left + right) / 2;
			if (cntLessThanX(mid, nums) > mid) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
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
	Solution H;
	cout << H.findDuplicate(nums);

	return 0;
}