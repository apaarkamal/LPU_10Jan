#include<bits/stdc++.h>
#define int long long int

using namespace std;

struct Mat {
	int sz;
	vector<vector<int>> data;
	Mat(int _sz) {
		sz = _sz;
		data.resize(sz, vector<int>(sz, 0));
	}

	void identity() {
		for (int i = 0; i < sz; i++) {
			data[i][i] = 1;
		}
	}

	// Mat operator+ (Mat &b) {


	// 	return res;
	// }

	// Mat operator- (Mat &b) {


	// 	return res;
	// }

	// Mat operator* (int c) {

	// }

	// O()
	Mat operator* (Mat &b) {
		Mat res(sz);

		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				// res.data[i][j]
				for (int k = 0; k < sz; k++) {
					res.data[i][j] += (data[i][k] * b.data[k][j]);
				}

			}
		}
		return res;
	}

	void print() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				cout << data[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
	}
};

Mat power(Mat a, int sz, int b) {
	Mat res(sz);
	res.identity();

	while (b) {
		if (b & 1) {
			res = res * a;
		}
		a = a * a;
		b /= 2;
	}

	return res;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Mat a(2);

	a.data[0][0] = 5;
	a.data[0][1] = 15;
	a.data[1][0] = 7;
	a.data[1][1] = 12;

	// a.print();

	Mat b(2);
	b.data[0][0] = 2;

	a = a * b;

	b.print();

	Mat b_5 = power(b, b.sz, 5);

	b_5.print();

	return 0;
}