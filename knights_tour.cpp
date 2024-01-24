#include<bits/stdc++.h>
#define int long long int

using namespace std;

int n, m;
vector<vector<int>> board;

void printBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int dx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2};

bool isSafe(int new_row, int new_col, int step) {
	if (new_row < 0 || new_col < 0 || new_row >= n || new_col >= m) {
		return false;
	}
	if (board[new_row][new_col] > 1) {
		return false;
	}
	if (board[new_row][new_col] == 1) {
		return (step == n * m);
	}
	return true;
}

void knightTour(int row, int col, int step) {
	// (0, 0)
	if (step == n * m + 1 && row == 0 && col == 0) {
		printBoard();
		return;
	}

	// enter the cell and mark the step
	board[row][col] = step;
	for (int i = 0; i < 8; i++) {
		// add the delta in the previous values
		int new_row = row + dx[i];
		int new_col = col + dy[i];

		// the new row and col should be within the board
		if (isSafe(new_row, new_col, step)) {
			knightTour(new_row, new_col, step + 1);
		}
	}
	// exit the cell, unmark the step
	board[row][col] = 0;
	return;
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m;
	board.resize(n, vector<int>(m, 0));

	knightTour(0, 0, 1);

	return 0;
}