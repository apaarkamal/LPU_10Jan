#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n, [](string a, string b) {
		return a + b < b + a;
	});

	for (int i = 0; i < n; i++) {
		cout << s[i];
	}

	return 0;
}