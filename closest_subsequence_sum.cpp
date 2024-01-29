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

class Solution {
public:

	// O(2^(sizeof(a)))
	vector<int> generateSubsetSums(vector<int> a) {
		int n = a.size();
		// contains all subset sums
		vector<int> res;
		for (int mask = 0; mask < (1 << n); mask++) {
			int subset_sum = 0;
			for (int i = 0; i < n; i++) {
				if ((mask >> i) & 1) {
					subset_sum += a[i];
				}
			}
			res.push_back(subset_sum);
		}
		return res;
	}

	int minAbsDifference(vector<int>& nums, int goal) {
		vector<int> left;
		vector<int> right;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (i < n / 2) {
				left.push_back(nums[i]);
			}
			else {
				right.push_back(nums[i]);
			}
		}

		// O(2^(n/2))
		vector<int> left_subset_sum = generateSubsetSums(left);
		// O(2^(n/2))
		vector<int> right_subset_sum = generateSubsetSums(right);

		sort(right_subset_sum.begin(), right_subset_sum.end());

		// for (auto y : right_subset_sum) db(y);

		int ans = 1e9;

		for (auto x : left_subset_sum) {
			// x+y close to goal
			// y close to goal-x
			int index  = lower_bound(right_subset_sum.begin(), right_subset_sum.end(), goal - x)
			             - right_subset_sum.begin();


			if (index < right_subset_sum.size()) {
				ans = min(ans, abs((goal - x) - right_subset_sum[index]));
			}
			if (index - 1 >= 0) {
				ans = min(ans, abs((goal - x) - right_subset_sum[index - 1]));
			}

			// db(x, index);
		}

		return ans;
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, goal;
	cin >> n >> goal;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	Solution H;
	cout << H.minAbsDifference(nums, goal);

	return 0;
}