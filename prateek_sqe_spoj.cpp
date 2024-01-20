#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int mod = 1e9;

struct Mat {
	// sz x sz
	int sz;
	vector<vector<int>> data;

	// constructor
	Mat(int _sz) {
		sz = _sz;
		data.resize(sz, vector<int>(sz, 0));
	}

	void identity() {
		data.resize(sz, vector<int>(sz, 0));

		for (int i = 0; i < sz; i++) {
			data[i][i] = 1;
		}
	}

	// O(sz^2)
	Mat operator+(Mat& b) {
		Mat res(this->sz);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				res.data[i][j] = (data[i][j] + b.data[i][j]) % mod;
			}
		}
		return res;
	}

	// O(sz^2)
	Mat operator-(Mat& b) {
		Mat res(this->sz);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				res.data[i][j] = (data[i][j] - b.data[i][j] + mod) % mod;
			}
		}
		return res;
	}

	// O(sz^2)
	Mat operator*(int b) {
		Mat res(this->sz);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				res.data[i][j] = ((data[i][j] % mod) * (b % mod)) % mod;
			}
		}
		return res;
	}

	// O(sz^3)
	Mat operator*(Mat& b) {
		Mat res(this->sz);
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				// make res[i][j]
				for (int k = 0; k < sz; k++) {
					res.data[i][j] += (data[i][k] * b.data[k][j]) % mod;
					res.data[i][j] %= mod;
				}
			}
		}
		return res;
	}

	// O(log(b)*(sz^3))
	Mat operator^(int b) {
		Mat a = (*this);

		Mat res(sz);
		res.identity();

		while (b) {
			if (b & 1) {
				res = res * a;
			}
			a = a * a;
			b >>= 1;
		}

		return res;
	}

	void print() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				cout << data[i][j] << " ";
			} cout << '\n';
		}
		// cout << '\n';
	}
};

Mat makeT(int c[], int k) {
	Mat T(k);

	// first row
	for (int i = 0; i < k; i++) {
		// c is 1-based indexed
		T.data[0][i] = c[i + 1];
	}

	// first row till last row
	for (int i = 1; i < k; i++) {
		T.data[i][i - 1] = 1;
	}

	return T;
}

int SEQ(int n, int b[], int c[], int k) {
	// n<=k
	if (n <= k) {
		return b[n];
	}

	// n>k
	Mat T = makeT(c, k);
	T = T ^ (n - k);

	int result = 0;
	for (int i = 0; i < k; i++) {
		result += (T.data[0][i] * b[k - i]) % mod;
		result %= mod;
	}

	return result;
}

// O(log(n)*O(k*k*k))
void solve() {
	int k;
	cin >> k;
	int b[k + 1], c[k + 1];

	for (int i = 1; i <= k; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
	}

	int n;
	cin >> n;

	cout << SEQ(n, b, c, k) << '\n';

}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}


	return 0;
}