#include<bits/stdc++.h>
#define int long long int

using namespace std;

// O((n/2)^2*2^(n/2))
class Solution {
public:

	// O(2^(n/2))
	void generateBucketsWithSubsetSum(vector<int> bucket[], vector<int> a) {
		int n = a.size();
		// contains all subset sums
		for (int mask = 0; mask < (1 << n); mask++) {
			int subset_sum = 0, cnt = 0;
			for (int i = 0; i < n; i++) {
				if ((mask >> i) & 1) {
					subset_sum += a[i];
					cnt++;
				}
			}
			bucket[cnt].push_back(subset_sum);
		}
	}

	bool splitArraySameAverage(vector<int>& nums) {
		vector<int> left, right;
		int total_sum = 0, n = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			if (i < nums.size() / 2) left.push_back(nums[i]);
			else right.push_back(nums[i]);
			total_sum += nums[i];
		}

		vector<int> left_bucket[left.size() + 1];
		vector<int> right_bucket[right.size() + 1];

		// O(2^(n/2))
		generateBucketsWithSubsetSum(left_bucket, left);
		generateBucketsWithSubsetSum(right_bucket, right);

		// O(n/2(log(n/2)))
		for (int i = 0; i < right.size() + 1; i++) {
			sort(right_bucket[i].begin(), right_bucket[i].end());
		}

		// 2^(n/2) * n/2 * n/2
		for (int len_x = 0; len_x < left.size() + 1; len_x++) {

			for (int sum_x : left_bucket[len_x]) {

				for (int len_y = 0; len_y < right.size() + 1; len_y++) {
					// because A -> (x+y) should be non empty
					if (len_x + len_y == 0) continue;
					// B should not be empty i.e. length(A) should be < n
					if (len_x + len_y == n) continue;

					if ((total_sum * (len_x + len_y)) % n != 0) continue;

					int sum_y = (total_sum * (len_x + len_y)) / n - sum_x;

					if (binary_search(right_bucket[len_y].begin(), right_bucket[len_y].end(), sum_y)) {
						return true;
					}
				}
			}
		}
		return false;
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
	cout << H.splitArraySameAverage(nums);

	// 32768 * 15 * 15

	return 0;
}