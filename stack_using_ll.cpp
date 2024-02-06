#include<bits/stdc++.h>
#define int long long int

using namespace std;

const int N = 1e5;

template<typename T>
class Stack {
private:
	struct node {
		T val;
		node* nxt;
		node(T _val) {
			val = _val;
			nxt = NULL;
		}
	};
	node* head = NULL;
public:
	bool empty() {
		return head == NULL;
	}
	T top() {
		if (empty()) {
			cout << "empty, can't top\n";
			return NULL;
		}
		return head->val;
	}
	void pop() {
		if (empty()) {
			cout << "empty\n";
			return;
		}
		node* to_be_deleted = head;
		head = head->nxt;
		delete to_be_deleted;
	}
	void push(T val) {
		node* newnode = new node(val);
		newnode->nxt = head;
		head = newnode;
	}
	int size() {
		int cnt = 0;
		node* cur = head;
		while (cur) {
			cur = cur->nxt;
			cnt++;
		}
		return cnt;
	}
};

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// Stack<string> St;


	// St.push("apaar");

	// St.push("kamal");

	// cout << St.top() << '\n';

	// St.pop();

	// cout << St.top() << '\n';

	Stack<int> St;

	St.push(1);
	St.push(2);
	St.push(3);
	St.push(4);
	St.push(5);

	cout << St.top() << '\n';

	St.pop();

	cout << St.top() << '\n';

	St.pop();

	St.push(6);

	St.pop();

	cout << St.top() << '\n';

	St.push(6);

	cout << St.top() << '\n';

	return 0;
}