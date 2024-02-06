#include<bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k;
	cin >> k;

	queue<int> Q;
	Q.push(0);

	while (k--) {
		int num = Q.front();
		Q.pop();

		int a = num * 10 + 1;
		int b = num * 10 + 2;
		int c = num * 10 + 3;

		Q.push(a);
		Q.push(b);
		Q.push(c);
	}

	cout << Q.front();

	return 0;
}