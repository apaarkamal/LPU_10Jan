class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		// decreasing nature
		deque<int> Q;
		for (int i = 0; i < k; i++) {
			while (!Q.empty() && nums[i] >= nums[Q.back()]) {
				Q.pop_back();
			}
			Q.push_back(i);
		}
		vector<int> res;
		res.push_back(nums[Q.front()]);
		for (int i = k; i < nums.size(); i++) {
			if (Q.front() == i - k) Q.pop_front();
			while (!Q.empty() && nums[i] >= nums[Q.back()]) {
				Q.pop_back();
			}
			Q.push_back(i);
			res.push_back(nums[Q.front()]);
		}
		return res;
	}
};