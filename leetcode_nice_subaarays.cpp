class Solution {
public:
	// O(n)
	int numberOfSubarrays(vector<int>& nums, int k) {
		int i = 0, j = 0, l = 0, ans = 0;
		int odd_j = 0, odd_l = 0;
		// O(n)
		while (i < nums.size()) {
			// j should stop when odd_j=k
			// O(n)
			while (j < nums.size() && odd_j + (nums[j] % 2) < k) {
				odd_j += (nums[j] % 2);
				j++;
			}
			// l is fine
			// O(n)
			while (l < nums.size() && odd_l + (nums[l] % 2) <= k) {
				odd_l += (nums[l] % 2);
				l++;
			}

			// cout<<i<<" "<<j<<" "<<l<<'\n';
			ans += (l - j);

			odd_j -= (nums[i] % 2);
			odd_l -= (nums[i] % 2);
			i++;
		}
		return ans;
	}
};