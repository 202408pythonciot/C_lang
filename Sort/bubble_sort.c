#include <stdio.h>
#include <windows.h>
#define MAX 10
#define G_MAX 21
#define TIMER  750

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
			if (x <=  *(data + y)) {
				printf("*");
			}
		}
		printf("\x1b[39m");
		printf("\n");
	}
}

int main(void) {
	int data[MAX] = {10, 2, 1, 9, 7, 4, 5, 3, 6, 8};

	// バブルソート
	for (int i = 0; i < MAX - 1; i += 1) {
		for (int j = MAX - 1; j > i; j -= 1) {
			printGraph(data, MAX, j, j - 1);
			if (data[j] < data[j - 1]) {
				int tmp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = tmp;
				printGraph(data, MAX, j - 1, j);
			}
			else {
				printGraph(data, MAX, j, j - 1);
			}
		}
	}
	return 0;
}
