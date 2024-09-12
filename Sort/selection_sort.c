// 選択ソート

#include <stdio.h>
#include <windows.h>
#define MAX 10
#define G_MAX 21

void printGraph(int* data, int len) {

	for (int y = 0; y < len; y += 1) {
		printf(" | ");
		for (int x = 1; x < G_MAX; x += 1) {
			if (x <=  *(data + y)) {
				printf("*");
			}
		}
		printf("\n");
	}
}

int main(void) {
	int data[MAX] = {10, 2, 1, 9, 7, 4, 5, 3, 6, 8};

	// 選択ソート
	for (int i = 0; i < MAX; i += 1) {
		printf("\x1b[2J");
		printf("\x1b[0;0H");
		printf("loop counter:%d\n", i);
		for (int j = i + 1; j < MAX; j += 1) {
			if (data[i] < data[j]) {
				int tmp = data[j];
				data[j] = data[i];
				data[i] = tmp;
			}
		}
		printGraph(data, MAX);
		Sleep(1000);
	}
	return 0;
}
