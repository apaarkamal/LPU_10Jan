#include<bits/stdc++.h>
#define int long long int

using namespace std;

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

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, L, R;
	cin >> n >> L >> R;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> left;
	vector<int> right;
	for (int i = 0; i < n; i++) {
		if (i < n / 2) {
			left.push_back(a[i]);
		}
		else {
			right.push_back(a[i]);
		}
	}

	vector<int> left_subset_sum = generateSubsetSums(left);
	vector<int> right_subset_sum = generateSubsetSums(right);

	sort(right_subset_sum.begin(), right_subset_sum.end());

	int ans = 0;

	// iterate over all subset sums of the left array
	// and find how many such y exists which satisfied the given eq
	for (auto x : left_subset_sum) {
		// L <= x + y <=R
		// L - x <= y <= R - x
		// UB(R-x) - LB(L-x)
		ans += upper_bound(right_subset_sum.begin(), right_subset_sum.end(), R - x)
		       - lower_bound(right_subset_sum.begin(), right_subset_sum.end(), L - x);
	}

	cout << ans;





	return 0;
}