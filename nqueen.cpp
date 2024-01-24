#include<bits/stdc++.h>
#define int long long int

using namespace std;

int n, possiblities;
vector<vector<bool>>board;

void printBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (board[i][j] ? "Q" : "_");
		}
		cout << '\n';
	}
	cout << '\n';
}

// Is it safe to place a queen on this cell
bool isSafe(int row, int col) {
	// no queen on the same column
	int i = row, j = col;
	while (i >= 0) {
		if (board[i][j]) return false;
		i--;
	}

	// no queen on the up-left diagonal
	i = row, j = col;
	while (i >= 0 && j >= 0) {
		if (board[i][j]) return false;
		i--; j--;
	}

	// no queen on the up-right diagonal
	i = row, j = col;
	while (i >= 0 && j < n) {
		if (board[i][j]) return false;
		i--; j++;
	}

	// place the queen
	return true;
}

void nqueen(int row) {
	// printBoard();
	if (row == n) {
		printBoard();
		possiblities++;
		exit(0);
		return;
	}

	for (int col = 0; col < n; col++) {
		if (isSafe(row, col)) {
			// place the queen
			board[row][col] = true;
			nqueen(row + 1);
			// here  backtrack
			board[row][col] = false;
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;

	board.resize(n, vector<bool> (n, false));

	nqueen(0);

	cout << possiblities;

	return 0;
}