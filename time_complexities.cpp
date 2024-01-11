#include<bits/stdc++.h>

using namespace std;


// o(n)
// i-> 0, i+k, i+2*k, i+3k.... i<n

// j is running k number of times in every iteration of i
void fun(int n, int m) {

	// O()
	// for (i = 0; i < n; i += 2) {

	// }

	// int k = 0;
	// for (int i = 1; i < n; i++) {
	// 	for (int j = i; j < n; j += i) {
	// 		k++;
	// 	}
	// }

	// O(log3(n))
	// 1, 2, 4, 8, 16 ....
	for (int i = 1; i < n; i *= 3) {

	}

	// O(sqrt(n))
	for (int i = 1; i * i < n; i++) {

	}

	// O(log2(n))
	while (n > 0) {
		n /= 2;
	}


	// O(n*n) > O(nlog(n)) > O(n) > O(sqrt(n)) > log2(n) > log3(n)

	// int i = 0;
	// while (i < n) {
	// 	int j = i;
	// 	int k = 20;
	// 	while (j < n && k >= 0) {
	// 		k--;
	// 		j++;
	// 		cout << j << '\n';
	// 	}
	// 	i = j;
	// }
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	fun(100, 0);

	// 10^7 iterations in one sec.

	// 10^8 -> not in one sec

	// 10^9 -> not one sec

	// clock_t c_start = std::clock();

	// for (int i = 0; i < pow(10, 7); i++) {
	// operations
	// }

	// clock_t c_end = std::clock();

	// std::cout << std::fixed << std::setprecision(5) << "CPU time used: "
	// << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << "ms\n";

	// double a = 22, b = 7;
	// double pi = a / b;

	// cout << fixed << setprecision(7) << pi;

	// answer should be closest to 9 decimal places

	// n->10^5
	// O(n * log2(n)) -> 1.6*10^6

	// cout << log2(100000);



	return 0;
}