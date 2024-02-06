class Solution {
public:
	int largestRectangleArea(vector<int> heights) {
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
		}
		return ans;
	}
	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector<int> continousOnes(m, 0);
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == '1') {
					// equal to one
					continousOnes[j]++;
				}
				else {
					continousOnes[j] = 0;
				}
			}
			// continousOnes -> histogram
			// for(int j=0;j<m;j++){
			//     cout<<continousOnes[j]<<" ";
			// }cout<<'\n';
			int maxAreaHistogram = largestRectangleArea(continousOnes);
			res = max(res, maxAreaHistogram);
		}
		return res;
	}
};