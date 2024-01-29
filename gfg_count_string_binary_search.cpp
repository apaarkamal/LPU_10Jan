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

string s;
int k, n;
vector<int> pref[26];

// O(n*26)
void computePref() {
	for (int i = 0; i < 26; i++) {
		pref[i].resize(n + 1, 0);
	}
	for (int i = 0; i < n; i++) {
		pref[s[i] - 'a'][i]++;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= n; j++) {
			pref[i][j] += pref[i][j - 1];
		}
	}
	// for (int i = 0; i < 26; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << pref[i][j];
	// 	} cout << '\n';
	// }
}

// O(26)
int countDistinct(int i, int j) {
	int distinct = 0;
	for (int c = 0; c < 26; c++) {
		int cnt = pref[c][j] - (i == 0 ? 0 : pref[c][i - 1]);
		if (cnt > 0) distinct++;
	}
	return distinct;
}

// O(logn)
// lower bound cntDistinct(>=k)
int getLeftWindow(int i) {
	int left = i, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (countDistinct(i, mid) >= k) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

// lower bound cntDistinct(>k)
int getRightWindow(int i) {
	int left = i + 1, right = n;
	while (left < right) {
		int mid = (left + right) / 2;
		if (countDistinct(i, mid) > k) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> s;
	cin >> k;
	n = s.size();

	computePref();

	int ans = 0;

	// O(nlog*26)
	// Between substr(i->[left...right))
	for (int i = 0; i < n; i++) {
		// O(26*logn)
		int left = getLeftWindow(i);
		// O(26*logn)
		int right = getRightWindow(i);
		// db(i, left, right);
		ans += (right - left);
	}

	cout << ans;

	return 0;
}