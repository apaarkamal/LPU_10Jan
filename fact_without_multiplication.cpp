#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	int sum = n, ans = 0;

	for (int i = n - 1; i >= 1; i--) {
		int temp_i = i;
		ans = 0;
		while (temp_i--) ans += sum;
		sum = ans;
	}
	cout << sum;

	return 0;
}