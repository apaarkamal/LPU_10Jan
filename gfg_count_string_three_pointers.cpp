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

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> s;
	cin >> k;
	n = s.size();

	// O(n*26)
	computePref();

	int ans = 0, left = 0, right = 0;

	// three pointer
	// O(n*26)
	for (int i = 0; i < n; i++) {
		while (left < n && countDistinct(i, left) < k) {
			left++;
		}
		while (right < n && countDistinct(i, right) <= k) {
			right++;
		}
		// db(i, left, right);
		ans += (right - left);
	}

	cout << ans;

	return 0;
}