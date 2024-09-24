// 入力した3変数の最大値を求める

#include <stdio.h>
#include <limits.h> // INT_MINを使うため

int max(int x, int y, int z);

int main(void) {
	printf("1, 99, 72のうちの最大値：%d\n", max(1, 99, 72));
	printf("81, 9, 82のうちの最大値：%d\n", max(81, 9, 82));
	printf("10, 8, 7のうちの最大値：%d\n", max(10, 8, 7));
	return 0;
}

int max(int x, int y, int z) {
	int max = INT_MIN;	// int型の最小値定義を代入
	if (x > max) max = x;
	if (y > max) max = y;
	if (z > max) max = z;
	return max;
}
