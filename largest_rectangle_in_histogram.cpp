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
	int largestRectangleArea(vector<int>& heights) {
		heights.insert(heights.begin(), -1);
		heights.push_back(-1);
		int n = heights.size();

		int next_smaller[n], previous_smaller[n];

		stack<int> St;
		for (int i = 0; i < n; i++) {
			while (!St.empty() && heights[St.top()] > heights[i]) {
				next_smaller[St.top()] = i;
				St.pop();
			}
			St.push(i);
		}

		for (int i = n - 1; i >= 0; i--) {
			while (!St.empty() && heights[St.top()] > heights[i]) {
				previous_smaller[St.top()] = i;
				St.pop();
			}
			St.push(i);
		}

		int ans = 0;

		for (int i = 1; i < n - 1; i++) {
			// cout << next_smaller[i] << " ";
			int length = (next_smaller[i] - previous_smaller[i] - 1);
			int height = heights[i];
			int area = length * height;
			ans = max(ans, area);
			db(i, previous_smaller[i], next_smaller[i], height, ans);
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
	vector<int> heights(n);

	for (int i = 0; i < n; i++) {
		cin >> heights[i];
	}

	Solution H;
	cout << H.largestRectangleArea(heights);


	return 0;
}