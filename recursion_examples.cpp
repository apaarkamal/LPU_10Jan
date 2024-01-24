#include<bits/stdc++.h>
#define int long long int

using namespace std;

int Power(int a, int b) {
	if (b == 0) return 1;
	return Power(a * a, b / 2) * (b & 1 ? a : 1);
}

bool isPalindromic(string s, int i, int j) {
	// string of length 1
	if (i == j) return true;
	// string of length 2
	if (i == j - 1) return true;
	return (s[i] == s[j]) && isPalindromic(s, i + 1, j - 1);
}

void generateSubsets(string res, string s) {
	if (s.empty()) {
		cout << res << '\n';
		return;
	}
	// dont take s[0]
	generateSubsets(res, s.substr(1));
	// take s[0]
	generateSubsets(res + s[0], s.substr(1));
}

void printValidParanthesis(string res, int open, int close, int n) {
	if (close == n) {
		cout << res << '\n';
		return;
	}
	// open
	if (open < n) {
		printValidParanthesis(res + "(", open + 1, close, n);
	}
	// close
	if (close < open) {
		printValidParanthesis(res + ")", open, close + 1, n);
	}
	return;
}

void printPermutations(string s, int index) {
	if (index == s.size() - 1) {
		cout << s << '\n';
		return;
	}
	for (int i = index; i < s.size(); i++) {
		swap(s[i], s[index]);
		printPermutations(s, index + 1);
		swap(s[i], s[index]);
	}
}

void towerOfHanoi(int n, string source, string helper, string destination) {
	if (n == 0) return;
	towerOfHanoi(n - 1, source, destination, helper);
	cout << n << " disc from " << source << " -> " << destination << '\n';
	towerOfHanoi(n - 1, helper, source , destination);
}

// pure recursive solution
// changing  arg -> index, remainingW
// 0 <= index <= n-1
// 0 <= remainingW <= W
// Brute force O(2^n)
// With memoisation O(n*W)
int knapSack(int index, int n, int reminaingW, int profit[], int weight[]) {
	if (index == n) return 0;

	int maxProfit = 0;

	// take
	if (weight[index] <= reminaingW) {
		maxProfit = max(maxProfit,
		                profit[index] +
		                knapSack(index + 1, n, reminaingW - weight[index], profit, weight));
	}

	// not take
	maxProfit = max(maxProfit, knapSack(index + 1, n, reminaingW, profit, weight));

	return maxProfit;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// cout << Power(3, 5);

	// string s;
	// cin >> s;
	// cout << isPalindromic(s, 0, s.size() - 1);


	// string s;
	// cin >> s;
	// generateSubsets("", s);

	// 1, 2, 5, 14, 42 .....
	// int n;
	// cin >> n;
	// printValidParanthesis("(", 1, 0, n);


	// string s;
	// cin >> s;
	// printPermutations(s, 0);

	// int n;
	// cin >> n;
	// towerOfHanoi(n, "A", "B", "C");

	int n, W;
	cin >> n >> W;
	int profit[n], weight[n];
	for (int i = 0; i < n; i++) {
		cin >> profit[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	cout << knapSack(0, n, W, profit, weight);





	return 0;
}