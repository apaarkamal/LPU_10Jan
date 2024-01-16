#include<bits/stdc++.h>
#include<algorithm>
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

// O(k)
int findGcd(int a, int b) {
	if (a == 0 || b == 0) return a + b;
	return findGcd(b % a, a);
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	cout << findGcd(n, m);

	return 0;
}