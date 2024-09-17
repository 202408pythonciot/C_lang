// 基数と指数を入力してべき乗を計算するpower関数

#include <stdio.h>

int power(int e, int x);

int main(void) {
	printf("2の3乗：%d\n", power(2, 3));
	printf("-9の7乗：%d\n", power(-9, 7));

	for (int i = 0; i < 5; i += 1) {
		printf("11の%d乗：%d\n", i, power(11, i));
	}
	return 0;
}

int power(int e, int x){
	int r = 1;
	for (int i = 0; i < x; i += 1) {
		r = r * e;
	}
	return r;
}
