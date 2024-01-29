#include<bits/stdc++.h>
#define int long long int

using namespace std;

void gun(int n) {
	if (n <= 0) return;
	cout << n;
	gun(n - 2);
	return;
}

void fun(int n) {
	if (n <= 0) return;
	cout << n;
	fun(n - 1);
	cout << n;
	gun(n - 1);
	cout << n;
	return;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n = 5;
	fun(n);


	return 0;
}