#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5;

template<typename T>
class Stack {
private:
	T a[N];
	int topIndex = -1;
public:
	bool empty() {
		return topIndex == -1;
	}
	void pop() {
		if (empty()) {
			cout << "can't pop, coz empty";
			return;
		}
		topIndex--;
	}
	int size() {
		return topIndex + 1;
	}
	bool isFull() {
		return size() == N;
	}
	T top() {
		if (empty()) {
			cout << "empty stack\n";
			return NULL;
		}
		return a[topIndex];
	}
	void push(T val) {
		if (isFull()) {
			cout << "stack is full, can't push\n";
			return;
		}
		topIndex++;
		a[topIndex] = val;
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Stack<string> St;


	St.push("apaar");

	St.push("kamal");

	cout << St.top() << '\n';

	St.pop();

	cout << St.top() << '\n';

	// St.push(1);
	// St.push(2);
	// St.push(3);
	// St.push(4);
	// St.push(5);

	// cout << St.top() << '\n';

	// St.pop();

	// cout << St.top() << '\n';

	// St.pop();

	// St.push(6);

	// St.pop();

	// cout << St.top() << '\n';

	// St.push(6);

	// cout << St.top() << '\n';

	return 0;
}