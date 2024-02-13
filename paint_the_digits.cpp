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

// 0...digit-1 -> 1
// digit+1 ..9 -> 2
string paintZeroAndOne(string s, int digit) {
	string res = s;
	int last_occurence = -1, first_occurence = s.size();
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] - '0') < digit) {
			res[i] = '1';
			last_occurence = max(last_occurence, i);
		}
		else if ((s[i] - '0') > digit) {
			res[i] = '2';
			first_occurence = min(first_occurence, i);
		}
	}
	// db(res);
	for (int i = 0; i < s.size(); i++) {
		if (i > last_occurence && (s[i] - '0') == digit) {
			res[i] = '1';
		}
		if (i < first_occurence && (s[i] - '0') == digit) {
			res[i] = '2';
		}
	}
	return res;
}

bool check(string s, string paint) {
	string bucket;
	for (int i = 0; i < s.size(); i++) {
		if (paint[i] == '1') {
			bucket += s[i];
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (paint[i] == '2') {
			bucket += s[i];
		}
	}
	// db(s, paint, bucket);
	sort(s.begin(), s.end());
	return bucket == s;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	for (int digit = 0; digit <= 9; digit++) {
		string painted = paintZeroAndOne(s, digit);
		// db(digit, painted);
		if (check(s, painted)) {
			cout << painted << '\n';
			return;
		}
	}
	cout << "-\n";
}

int32_t main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}