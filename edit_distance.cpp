class Solution {
public:
	int n, m;
	int dp(int i, int j, string &word1, string &word2, vector<vector<int>> &memo) {
		if (i == word1.size() && j == word2.size()) return 0;
		if (i == word1.size()) return word2.size() - j;
		if (j == word2.size()) return word1.size() - i;

		if (memo[i][j] != -1) return memo[i][j];

		int ans = 1e9;
		if (word1[i] == word2[j]) {
			ans = dp(i + 1, j + 1, word1, word2, memo);
		}
		// insert
		ans = min(ans, 1 + dp(i, j + 1, word1, word2, memo));
		// replace
		ans = min(ans, 1 + dp(i + 1, j + 1, word1, word2, memo));
		// remove
		ans = min(ans, 1 + dp(i + 1, j, word1, word2, memo));
		return memo[i][j] = ans;
	}
	int minDistance(string word1, string word2) {
		n = word1.size(), m = word2.size();
		vector<vector<int>> memo(n, vector<int>(m, -1));
		return dp(0, 0, word1, word2, memo);
	}
};