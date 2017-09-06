#include <iostream>
using namespace std;

const int MAX_ARR_SIZE = 5;

void rotateMat(int mat[MAX_ARR_SIZE][MAX_ARR_SIZE], int n, int si = 0, int sj = 0) {
	int temp[MAX_ARR_SIZE];

	for (int i = si, j = 0; i < si + n - 1; ++i, ++j) {
		temp[j] = mat[si][i];
	}

	for (int i = si; i < si + n; ++i) {
		mat[si][i] = mat[i][sj+n-1];
	}

	for (int i = sj+n-2, j = si+1; i >= sj; --i, ++j) {
		mat[j][sj+n-1] = mat[si+n-1][i];
	}

	for (int i = si+n-2; i > si; --i) {
		mat[si+n-1][i] = mat[i][sj];
	}

	for (int i = si+n-1, j = 0; i > si; --i, ++j) {
		mat[i][sj] = temp[j];
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	rotateMat(mat, n);
	cout << "\n\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}