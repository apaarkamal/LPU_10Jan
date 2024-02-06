#include<bits/stdc++.h>
#define int long long int

using namespace std;

bool isOperand(char ch) {
	return (ch >= 'a' && ch <= 'z')
	       || (ch >= 'A' && ch <= 'Z')
	       || (ch >= '0' && ch <= '9');
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string prefix;
	cin >> prefix;

	stack<string> St;

	reverse(prefix.begin(), prefix.end());

	cout << prefix << '\n';

	// cout << prefix;
	// ABC/-AK/L-*
	for (auto x : prefix) {
		if (isOperand(x)) {
			string op = string(1, x);
			St.push(op);
		}
		else {
			string op1 = St.top();
			St.pop();
			string op2 = St.top();
			St.pop();
			// postfix to prefix
			St.push(x + op2 + op1);
		}
	}

	cout << St.top() << '\n';

	reverse(St.top().begin(), St.top().end());

	cout << St.top();

	return 0;
}