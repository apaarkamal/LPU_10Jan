#include<bits/stdc++.h>
#define int long long int

using namespace std;

bool isOperand(char ch) {
	return (ch >= 'a' && ch <= 'z')
	       || (ch >= 'A' && ch <= 'Z')
	       || (ch >= '0' && ch <= '9');
}

int precedence(char op) {
	if (op == '^') {
		return 3;
	}
	else if (op == '/' || op == '*') {
		return 2;
	}
	else {
		return 1;
	}
}

bool isOperator(char ch) {
	return (ch == '+' || ch == '/' || ch == '*' || ch == '-' || ch == '^');
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string infix, postfix;
	cin >> infix;

	stack<char> St;

	for (int i = 0; i < infix.size(); i++) {
		if (isOperand(infix[i])) {
			// operand
			postfix += infix[i];
		}
		else if (infix[i] == '(' || infix[i] == ')') {
			// brackets
			if (infix[i] == '(') {
				St.push('(');
			}
			else {
				// closing bracket
				while (St.top() != '(') {
					postfix += St.top();
					St.pop();
				}
				// pop out the opening bracket as well
				St.pop();
			}
		}
		else {
			// operator

			// pop out the operator from stack if
			// they have higher precedence then current
			// oprator
			while (!St.empty()
			        && isOperator(St.top())
			        && precedence(infix[i]) < precedence(St.top())) {
				postfix += St.top();
				St.pop();
			}

			// remove same precedence left asociative
			while (!St.empty()
			        && isOperator(St.top())
			        && precedence(infix[i]) == precedence(St.top())
			        // left associative +, -, *, /
			        && precedence(infix[i]) <= 2) {
				postfix += St.top();
				St.pop();
			}

			St.push(infix[i]);
		}
	}

	// empty the monotonic stack
	while (!St.empty()) {
		postfix += St.top();
		St.pop();
	}

	cout << postfix;

	return 0;
}