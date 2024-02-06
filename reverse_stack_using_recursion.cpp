#include<bits/stdc++.h>
#define int long long int

using namespace std;

void pushAtBottom(stack<int> &St, int x) {
	if (St.empty()) {
		St.push(x);
		return;
	}

	int y = St.top();
	St.pop();

	pushAtBottom(St, x);

	St.push(y);
}

void reverseStack(stack<int> &St) {
	if (St.empty()) return;

	int x = St.top();
	St.pop();

	reverseStack(St);

	pushAtBottom(St, x);
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	stack<int> St;
	St.push(1);
	St.push(2);
	St.push(3);
	St.push(4);
	St.push(5);

	// while (!St.empty()) {
	// 	cout << St.top() << '\n';
	// 	St.pop();
	// }

	reverseStack(St);

	while (!St.empty()) {
		cout << St.top() << '\n';
		St.pop();
	}

	return 0;
}