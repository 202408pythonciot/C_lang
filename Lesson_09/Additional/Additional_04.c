#include <stdio.h>

int add(int *a, int *b) {
	*a += 1;
	*b += 2;
	return *a + *b;
}

int main(void) {
	int a, b;
	printf("整数１を入力\n");
	scanf("%d", &a);
	printf("整数２を入力\n");
	scanf("%d", &b);
	int r = add(&a, &b);
	printf("a:%d, b:%d add:%d\n", a, b, r);
	return 0;
}
