#include <stdio.h>
#include <windows.h>
#define MAX 10
#define G_MAX 21
#define TIMER  750
#define STACKSIZE 16

void printGraph(int* data, int len, int src, int dst) {
	Sleep(TIMER);
	printf("\x1b[2J");
	printf("\x1b[0;0H");
	for (int y = 0; y < len; y += 1) {
		if (y == src) {
			printf("\x1b[31m");
		}
		else if (y == dst) {
			printf("\x1b[36m");
		}
		printf(" | ");
		for (int x = 1; x < G_MAX; x += 1) {
			if (x <= *(data + y)) {
				printf("*");
			}
		}
		printf("\x1b[39m");
		printf("\n");
	}
}

// クイックソート（再帰呼び出しを使うバージョン）
void quicksort(int data[], int first, int last) {
	printGraph(data, MAX, -1, -1);
	int i, j;
	int x, tmp;

	x = data[(first + last) / 2];
	i = first;
	j = last;
	for (;;) { // 無限ループ
		while (data[i] < x) i += 1;
		while (x < data[j]) j -= 1;
		if (i >= j) break;
		tmp = data[i];
		data[i] = data[j];
		data[j] = tmp;
		i += 1;
		j -= 1;
	}
	if (first < i - 1)	quicksort(data, first, i - 1);
	if (j + 1 < last)	quicksort(data, j + 1, last);
}

int main(void) {
	int data[MAX] = { 10, 2, 1, 9, 7, 4, 5, 3, 6, 8 };
	quicksort(data, 0, MAX - 1);
	printGraph(data, MAX, -1, -1);
	return 0;
}
