#include <iostream>
#include <stack>
using namespace std;
/**
 * 计算两个数组的最长公共子序列
 * m, n分别为两数组长度
 * b 用来存储公共子序列标识
 */
template<typename T>
int lcs(T *x, const int &m, T *y, const int &n, int **b) {
	int **c = new int*[m+1]; // 保存最长公共子序列
	for (int t = 0; t <=m; ++t) {
		c[t] = new int[n+1];
	}
	// 如果一个数组为空，则最长公共子序列为0
	for (int i = 0; i <= m; ++i) {
		c[i][0] = 0;
	}
	for (int j = 0; j <= n; ++j) {
		c[0][j] = 0;
	}
	// dp求解
	for (int k = 0; k != m; ++k) {
		for (int r = 0; r != n; ++r) {
			if (x[k] == y[r]) {
				c[k+1][r+1] = c[k][r] + 1;
				b[k][r] = 0;
			} else if (c[k][r+1] < c[k+1][r]) {
				c[k+1][r+1] = c[k+1][r];
				b[k][r] = 1;
			} else {
				c[k+1][r+1] = c[k][r+1];
				b[k][r] = 2;
			}
		}
	}
	return c[m][n];
}

/**
 * m, n 为数组长度
 */
template<typename T>
void printLCS(const int &m, const int &n, int **b, T *x) {
	stack<T> sta;
	if (0 == m || 0 == n)
		return;

	if (0 == b[m-1][n-1]) {
		sta.push(x[m-1]);
		printLCS(m-1, n-1, b, x);
	}else if (1 == b[m-1][n-1]) {
		printLCS(m, n-1, b, x);
	} else {
		printLCS(m-1, n, b, x);
	}
	while (!sta.empty()) {
		cout << sta.top() << "\t";
		sta.pop();
	}
}

int main(int argc, char **argv) {
	const int m = 7;
	const int n = 6;
	char x[m] = {'a', 'b', 'c', 'b', 'd', 'a', 'b'};
	char y[n] = {'b', 'd', 'c', 'a', 'b', 'a'};
	int **b = new int*[m];
	for (int i = 0; i != m; ++i) {
		b[i] = new int[n];
	}
	int r = lcs(x, m, y, n, b);
	for (int i = 0; i != m; ++i) {
		for (int j = 0; j != n; ++j) {
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}
	printLCS(m, n, b, x);
	cout << endl;
	return 0;
}