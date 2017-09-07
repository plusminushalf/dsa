#include <iostream>

using namespace std;

const int MAX_ARR_SIZE = 5;

void reverseArr(int *a, int s, int  e) {
	int temp;
	e = e-1;
	while(s < e) {
		temp = a[e];
		a[e] = a[s];
		a[s] = temp;
		s++;
		e--;
	}
}

void rotateArr(int *a, int n, int k) {

		if (n == 1) {
			return;
		}

		reverseArr(a, 0, k);
		reverseArr(a, k, n);
		reverseArr(a, 0, n);
}

// with extra space

void rotateMat(int mat[MAX_ARR_SIZE][MAX_ARR_SIZE], int n, int k, int si = 0, int sj = 0) {
	if (n == 1) {
		return;
	}
	int temp[n*4 - 4], j = 0, i = 0;

	for (i = sj; i < sj+n; ++i) {
		temp[j++] = mat[si][i];
	}

	for (i = si + 1; i < si + n; ++i) {
		temp[j++] = mat[i][sj+n-1];
	}

	for (i = sj + n - 2; i >= sj; --i) {
		temp[j++] = mat[si+n-1][i];
	}

	for (i = si + n - 2; i > si; --i) {
		temp[j++] = mat[i][sj];
	}

	rotateArr(temp, n*4 - 4, k);

	j = 0;

	for (i = sj; i < sj+n; ++i) {
		mat[si][i] = temp[j++];
	}

	for (i = si + 1; i < si + n; ++i) {
		mat[i][sj+n-1] = temp[j++];
	}

	for (i = sj + n - 2; i >= sj; --i) {
		mat[si+n-1][i] = temp[j++];
	}

	for (i = si + n - 2; i > si; --i) {
		mat[i][sj] = temp[j++];
	}

	if (n > 1) {
		rotateMat(mat, n-2, k, si+1, sj+1);
	}
}

int main() {
	int n = 5, k = 3;
	// cin >> n;

	int mat[MAX_ARR_SIZE][MAX_ARR_SIZE] = {
		{1, 2, 3, 4, 5},
		{16, 17, 18, 19, 6},
		{15, 24, 25, 20, 7},
		{14, 23, 22, 21, 8},
		{13, 12, 11, 10, 9}
	};

	int rot[MAX_ARR_SIZE][MAX_ARR_SIZE] = {
		{4, 5, 6, 7, 8},
		{3, 20, 21, 22, 9},
		{2, 19, 25, 23, 10},
		{1, 18, 17, 24, 11},
		{16, 15, 14, 13, 12}
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	rotateMat(mat, n, k);
	cout << "\n";


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}

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