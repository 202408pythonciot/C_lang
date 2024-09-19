#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 数あてゲーム（乱数使用版）
int main(void)
{
	int count = 0;
	int ans;
	srand((unsigned int)time(NULL)); // 疑似乱数発生器を時刻で初期化
	int rnd = 1 + rand() % 99; // 1から99までの乱数を発生
	printf("数字当てゲーム\n");
	while (1) {
		count += 1;
  	printf("1から100までの数字を入れてください\n");
		scanf("%d", &ans);
		if (ans < rnd) {
			printf("ざんねん、%d より大きいです\n", ans);
		}else if (rnd < ans) {
				printf("ざんねん、%d より小さいです\n", ans);
			}
		else {
			printf("正解！%d回であてました\n",count);
			break;
		}
	}
	return 0;
}
