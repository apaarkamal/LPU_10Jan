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

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	int ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int cnt = 0;

	vector<int> left, right;

	// O(n^3)
	for (int aa = 0; aa < n; aa++) {
		for (int bb = 0; bb < n; bb++) {
			for (int cc = 0; cc < n; cc++) {
				int a = ar[aa];
				int b = ar[bb];
				int c = ar[cc];
				left.push_back(a * b + c);
			}
		}
	}

	// O(n^3)
	for (int dd = 0;  dd < n; dd++) {
		for (int  ee = 0; ee < n; ee++) {
			for (int ff = 0; ff < n; ff++) {
				int d = ar[dd];
				int e = ar[ee];
				int f = ar[ff];
				if (d != 0) {
					right.push_back((f + e) * d);
				}
			}
		}
	}

	// O(n^3(log(n^3)))
	sort(right.begin(), right.end());

	// for (auto x : right) cout << x << " ";
	// cout << '\n';
	// O(n^3log(n^3))
	for (auto x : left) {
		// cout << x << " ";
		// O(logn)
		cnt += upper_bound(right.begin(), right.end(), x)
		       - lower_bound(right.begin(), right.end(), x);
	}

	cout << cnt;

// Brute Force
// O(n^6)
// for (int aa = 0; aa < n; aa++) {
// 	for (int bb = 0; bb < n; bb++) {
// 		for (int cc = 0; cc < n; cc++) {
// 			for (int dd = 0;  dd < n; dd++) {
// 				for (int  ee = 0; ee < n; ee++) {
// 					for (int ff = 0; ff < n; ff++) {
// 						int a = ar[aa];
// 						int b = ar[bb];
// 						int c = ar[cc];
// 						int d = ar[dd];
// 						int e = ar[ee];
// 						int f = ar[ff];
// 						if (d != 0 && (a * b + c) == (f + e) * d) {
// 							cnt++;
// 							db(a, b, c, d, e, f);
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// }

	// cout << cnt;

	return 0;
}