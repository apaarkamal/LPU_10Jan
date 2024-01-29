#include<bits/stdc++.h>
#define int long long int

using namespace std;

vector<vector<int>> grid;
int n;

void sudokuSolver(int row, int col);

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void goNext(int row, int col) {
	if (col == n - 1) {
		col = 0;
		row++;
	}
	else {
		col++;
	}
	sudokuSolver(row, col);
}

bool isSafe(int row, int col, int digit) {
	// check the complete row
	for (int j = 0; j < n; j++) {
		if (grid[row][j] == digit) return false;
	}
	// check the complete column
	for (int i = 0; i < n; i++) {
		if (grid[i][col] == digit) return false;
	}

	// check sqrt
	// n should be a perfect square
	int sqrt_n = sqrt(n);
	int start_row = (row / sqrt_n) * sqrt_n, start_col = (col / sqrt_n) * sqrt_n;
	for (int i = start_row; i < start_row + sqrt_n; i++) {
		for (int j = start_col; j < start_col + sqrt_n; j++) {
			if (grid[i][j] == digit) return false;
		}
	}

	return true;
}

void sudokuSolver(int row, int col) {
	if (row == n && col == 0) {
		print();
		return;
	}

	if (grid[row][col] > 0) {
		// prefilled values
		goNext(row, col);
	}
	else {
		// 0 values
		// try all values from 1..9
		for (int digit = 1; digit <= 9; digit++) {
			if (isSafe(row, col, digit)) {
				grid[row][col] = digit;
				goNext(row, col);
				// backtrack
				grid[row][col] = 0;
			}
		}
	}
}

int32_t main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	grid.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	sudokuSolver(0, 0);

	return 0;
}