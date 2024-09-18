#include <stdio.h>

void add(int* x, int a) {
	*x += a;
}

int main(void) {
	int x1, x2, a;
	printf("２科目分の点数を入力してください\n");
	scanf("%d", &x1);
	scanf("%d", &x2);
	printf("加点する点数を入力してください\n");
	scanf("%d", &a);
	add(&x1, a);
	printf("科目１は%d点となりました\n", x1);
	add(&x2, a);
	printf("科目２は%d点となりました\n", x2);
	return 0;
}
