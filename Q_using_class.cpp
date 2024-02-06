#include<bits/stdc++.h>
#define int long long int

using namespace std;

class Queue {
private:
	vector<int> v;
	int n, start, end, cnt;
public:
	Queue(int _n) {
		n = _n;
		v.resize(n);
		start = 0;
		end = 0;
		cnt = 0;
	}
	bool empty() {
		return (cnt == 0);
	}
	bool full() {
		return (cnt == n);
	}
	void push(int x) {
		if (full()) {
			cout << "queue full, next time\n";
			return;
		}
		v[end] = x;
		end++; end %= n;
		cnt++;
	}
	int front() {
		if (empty()) {
			cout << "empty queue\n";
			return -1;
		}
		return v[start];
	}
	int top() {
		if (empty()) {
			cout << "empty queue\n";
			return -1;
		}
		return v[start];
	}
	void pop() {
		if (empty()) {
			cout << "already empty, cant pop\n";
			return;
		}
		cnt--;
		start++; start %= n;
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n = 10;
	Queue Q(n);

	Q.push(1);
	Q.push(2);
	Q.push(3);

	cout << Q.front() << '\n';

	Q.pop();
	Q.pop();
	Q.pop();

	cout << Q.front() << '\n';








	return 0;
}