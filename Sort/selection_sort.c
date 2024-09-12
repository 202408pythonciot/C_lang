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

	// 選択ソート
	for (int i = 0; i < MAX; i += 1) {
		for (int j = i + 1; j < MAX; j += 1) {
			printGraph(data, MAX, i, j);
			if (data[j] < data[i]) {
				int tmp = data[j];
				data[j] = data[i];
				data[i] = tmp;
				printGraph(data, MAX, j, i);
			}
			else {
				printGraph(data, MAX, i, j);
			}
		}
	}
	return 0;
}
