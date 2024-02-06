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

bool isOperand(char ch) {
	return (ch >= 'A' && ch <= 'Z')
	       || (ch >= 'a' && ch <= 'z')
	       || (ch >= '0' && ch <= '9');
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string postfix;
	cin >> postfix;

	stack<string> St;

	for (int i = 0; i < postfix.size(); i++) {
		if (isOperand(postfix[i])) {
			// convert character to string ??
			string post = string(1, postfix[i]);
			// db(post);
			St.push(post);
		}
		else {
			string operand_1 = St.top();
			St.pop();
			string operand_2 = St.top();
			St.pop();
			string res = "(" + operand_2 + postfix[i] + operand_1 + ")";
			St.push(res);
		}
	}

	cout << St.top() << '\n';

	return 0;
}