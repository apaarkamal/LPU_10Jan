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

// O(sqrt(x))
int getParathasByCook(int rank, int x) {
	int parathas = 0;
	while (rank * parathas * (parathas + 1) <= 2 * x) {
		parathas++;
	}
	return parathas - 1;
}

// O(log(1e9))
int getParathasByCookBinarySearch(int rank, int x) {
	int left = 0, right = 1e9;
	while (left < right) {
		int mid = (left + right) / 2;
		if (rank * mid * (mid + 1) <= 2 * x) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left - 1;
}

// Total Parathas by all cooks in x minutes
// O(log(1e9)*c)
int getTotalParatas(int x, int ranks[], int c) {
	int totalParathas = 0;
	for (int i = 0; i < c; i++) {
		int parathas_by_cook = getParathasByCookBinarySearch(ranks[i], x);
		totalParathas += parathas_by_cook;
	}
	return totalParathas;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int p;
		cin >> p;
		int c;
		cin >> c;
		int ranks[c];
		for (int i = 0; i < c; i++) {
			cin >> ranks[i];
		}

		// O(min*log(1e9)*c)
		// [0....4010000]
		// for (int min = 1; min < 400; min++) {
		// 	int paratas = getTotalParatas(min, ranks, c);
		// 	db(min, paratas);
		// }

		// O(log(1e7) * log(1e9) * c)
		int left = 0, right = 1e7;
		while (left < right) {
			int mid = (left + right) / 2;
			if (getTotalParatas(mid, ranks, c) >= p) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}

		cout << left << '\n';
	}


	return 0;
}