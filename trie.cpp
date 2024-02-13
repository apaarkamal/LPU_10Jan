#include<bits/stdc++.h>
#define int long long int

using namespace std;

struct trie {
	trie* nxt[26];
	bool is_end;
	int cnt;
	trie() {
		cnt = 0;
		is_end = false;
		for (int i = 0; i < 26; i++) nxt[i] = NULL;
	}
};

// O(|string|)
void insertInTrie(trie* root, string s) {
	trie* cur = root;
	for (int i = 0; i < s.size(); i++) {
		if (cur->nxt[s[i] - 'a'] == NULL) {
			cur->nxt[s[i] - 'a'] = new trie();
		}
		cur = cur->nxt[s[i] - 'a'];
		cur->cnt++;
	}
	// cur??
	cur->is_end = true;
}

// O(|string|)
bool findInTrie(trie* root, string s) {
	trie* cur = root;
	for (int i = 0; i < s.size(); i++) {
		if (cur->nxt[s[i] - 'a'] == NULL) {
			return false;
		}
		cur = cur->nxt[s[i] - 'a'];
	}
	// node is end node or not
	return cur->is_end;
}

int cntOfStringWithPrefix(trie* root, string s) {
	trie* cur = root;
	for (int i = 0; i < s.size(); i++) {
		if (cur->nxt[s[i] - 'a'] == NULL) {
			return 0;
		}
		cur = cur->nxt[s[i] - 'a'];
	}
	// node is end node or not
	return cur->cnt;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// empty prefix
	trie* root = new trie();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insertInTrie(root, s);
	}

	int m;
	cin >> m;
	while (m--) {
		string s;
		cin >> s;
		// cout << findInTrie(root, s) << '\n';
		cout << cntOfStringWithPrefix(root, s) << '\n';

	}

	return 0;
}