#include <iostream>

using namespace std;

const int MAX_ARR_SIZE = 5;

void rotateMat(int mat[MAX_ARR_SIZE][MAX_ARR_SIZE], int n, int si = 0, int sj = 0) {
	int temp;

	for (int i = si; i < si + n - 1; ++i) {
		temp = mat[i][sj+n-1];
		mat[i][sj+n-1] = mat[si][i];
		mat[si][i] = temp;
	}

	for (int i = sj+n-1, j = si; i > sj; --i, ++j) {
		temp = mat[si+n-1][i];
		mat[si+n-1][i] = mat[j][sj+n-1];
		mat[j][sj+n-1] = temp;
	}

	for (int i = si+n-1; i > si; --i) {
		temp = mat[i][sj];
		mat[i][sj] = mat[si+n-1][i];
		mat[si+n-1][i] = temp;
	}

	if (n > 1) {
		rotateMat(mat, n-2, si+1, sj+1);
	}
}

int main() {
	int n = 5;
	// cin >> n;

	int mat[MAX_ARR_SIZE][MAX_ARR_SIZE] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 0},
		{2, 3, 4, 5, 6},
		{8, 7, 6, 5, 4},
		{5, 6, 7, 8, 9}
	};

	int rot[MAX_ARR_SIZE][MAX_ARR_SIZE] = {
		{5, 0, 6, 4, 9},
		{4, 9, 5, 5, 8},
		{3, 8, 4, 6, 7},
		{2, 7, 3, 7, 6},
		{1, 6, 2, 8, 5}
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	rotateMat(mat, n);
	cout << "\n";

	bool failed = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != rot[i][j]) {
				cout << "Failed!";
				failed = true;
				break;
			}
		}
	}

	if (!failed) {
		cout << "Passed!";
	}

	return 0;
}