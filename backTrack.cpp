#include <iostream>
#include <cmath>
using namespace std;

void backTrack(int *a, const int &n) {
	a[0] = 0;
	int k = 0;
	while (k >= 0) {
		// a[k] += 1; // 将第k行的皇后后移一行
		while (a[k] < n && !place(a, n, k)) {
			a[k] += 1;
		}
	}
}

/** 
 * 判断是否能把皇后放在第k列
 * k从0开始取值
 */
bool place(int *a, const int &len, const int &k) {
	int i = 0;
	while (i < k) { // 把第k个皇后的位置与前k-1行的皇后位置进行比较
		if (
			a[i] == a[k] || 
			abs(k-i) == abs(a[k] - a[i])
			) {
			return false;
		}
		++i;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	const int n = 8;
	int *a = new int[n];
	backTrack(a, n);
	return 0;
}