#include<bits/stdc++.h>

using namespace std;

int turnoffkth(int n, int k) {
	return (n & (~(1 << k)));
}

int turnonkth(int n, int k) {
	return (n | (1 << k));
}

bool kthset(int n, int k) {
	return (1 << k) & n;
}

int togglekthbit(int n, int k) {
	return n ^ (1 << k);
}

int unsetRightMostSetBit(int n) {
	return n & (n - 1);
}

bool checkIfPowerOfTwo(int n) {
	return (n & (n - 1)) == 0;
}

// O(32) times
int countBits(int n) {
	int cnt = 0;
	for (int bit = 0; bit < 32; bit++) {
		if ((1 << bit)&n) {
			cnt++;
		}
	}
	return cnt;
}

// O(count of set bits)
int countBitsOptimised(int n) {
	int cnt = 0;

	while (n) {
		cnt++;
		// remove its rightmost bit
		n &= (n - 1);
	}

	return cnt;
}

int multiply(int a, int b) {
	int res = 0;

	while (b) {

		if (b & 1) {
			res = res + a;
		}

		a = 2 * a;
		b >>= 1;
	}

	return res;

}

int findPower(int a, int b) {
	int res = 1;

	while (b) {

		if (b & 1) {
			res = res * a;
		}

		a = a * a;
		b >>= 1;
	}

	return res;


	// int res = 1;
	// for (int bit = 0; bit < 32; bit++) {

	// 	if ((1 << bit)&b) {
	// 		// b's bit is set
	// 		// include that a's power into the res
	// 		res = res * a;
	// 	}

	// 	a = a * a;
	// }

	// return res;
}

void generateAllSubsets(string name) {
	int n = name.size();

	// 0 .... 2^n
	for (int num = 0; num < (1 << n); num++) {
		for (int bit = 0; bit < n; bit++) {
			if ((num >> bit) & 1) {
				cout << name[bit];
			}
		}
		cout << '\n';
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// bitset<8> b1(14), b2(26), b3(20);

	// cout << b1 << '\n' << b2 << '\n' << (b1 & b2) << '\n' << (b1 | b2) << '\n' << (b1 ^ b2) << '\n';

	// cout << b3;

	// int n = 13;
	// cout << (n & 1);
	// bitset<10> num(13);
	// cout << num[0];

	// detect if two integers have opposite signs
	// int pos = 19, neg = -188;
	// if ((pos ^ neg) < 0) {
	// 	cout << "opposite";
	// }
	// else {
	// 	cout << "same";
	// }

	// int n = 10;
	// bitset<32> bt(n), one_c(~10), minus_10(-10);
	// cout << bt << "\n" << one_c << "\n" << minus_10;

	// int x = 10;
	// cout << -(~x) << '\n';
	// cout << ~(-x);

	// 10100
	// cout << turnoffkth(20, 2) << '\n';
	// cout << turnonkth(20, 1) << '\n';
	// cout << kthset(20, 2) << '\n';

	//
	// cout << unsetRightMostSetBit(12);

	// cout << checkIfPowerOfTwo(20);

	// cout << countBits(30);
	// cout << countBitsOptimised(16);

	// 0001000001
	// 0001100001
	// upper -> lower
	// for (char ch = 'A'; ch <= 'Z'; ch++) {
	// 	cout << char(ch | ' ') << '\n';
	// }

	// lower to upper
	// for (char ch = 'a'; ch <= 'z'; ch++) {
	// 	cout << char(ch ^ ' ') << '\n';
	// }

	// binary exponentiation
	// cout << findPower(4, 7);

	string name = "abcde";
	generateAllSubsets(name);






	return 0;
}