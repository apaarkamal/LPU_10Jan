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
	struct node {
		node* nxt[2];
		node() {
			nxt[0] = nxt[1] = NULL;
		}
	};

	void insert(node* root, int x) {
		node* cur = root;
		for (int i = 30; i >= 0; i--) {
			int bit = (x >> i) & 1;
			if (cur->nxt[bit] == NULL) {
				// create a new node
				cur->nxt[bit] = new node();
			}
			cur = cur->nxt[bit];
		}
	}

	int getMaxXorNumber(node* root, int num) {
		node* cur = root;
		int ans = 0;
		for (int i = 30; i >= 0; i--) {
			int bit = (num >> i) & 1;
			int need_bit = bit ^ 1;
			if (cur->nxt[need_bit] != NULL) {
				cur = cur->nxt[need_bit];
				ans += (1 << i) * need_bit;
			}
			else {
				cur = cur->nxt[need_bit ^ 1];
				ans += (1 << i) * (need_bit ^ 1);
			}
			// db(ans);
		}
		return ans;
	}

	int findMaximumXOR(vector<int>& nums) {
		node* root = new node();
		for (int i = 0; i < nums.size(); i++) {
			insert(root, nums[i]);
		}

		int ans = 0;

		for (int i = 0; i < nums.size(); i++) {
			int max_xor_num = getMaxXorNumber(root, nums[i]);
			// db(nums[i], max_xor_num, (nums[i]^max_xor_num));
			ans = max(ans, (nums[i] ^ max_xor_num));
		}

		return ans;
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

	cout << H.findMaximumXOR(nums);

	return 0;
}