#include<bits/stdc++.h>
#define int long long int
#define double long double

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

	double n;
	cin >> n;

	double left = 1, right = n;
	cout << setprecision(7) << fixed;

	while (right - left > 0.00000001) {
		double mid = (left + right) / 2;
		db(left, right, mid);
		if (mid * mid <= n) {
			// search on the right half
			left = mid;
		}
		else {
			// search
			right = mid;
		}
	}

	cout << left << " " << right << '\n';

	return 0;
}