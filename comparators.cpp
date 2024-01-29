#include<bits/stdc++.h>
#define int long long int

using namespace std;


// if I want x to come before then y then return true
// if I want y to come before then x then return false
// bool comparator(int x, int y) {
// return abs(x) < abs(y);
// return x > y;
// }

// compare ascending for first
// descending for second
bool comparator(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

// asce -> size
// lexicographical order if size is same
bool compareString(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	pair<int, int> a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	sort(a, a + n);
	sort(a, a + n, comparator);

	for (int i = 0; i < n; i++) {
		cout << a[i].first << " " << a[i].second << '\n';
	}

	return 0;
}