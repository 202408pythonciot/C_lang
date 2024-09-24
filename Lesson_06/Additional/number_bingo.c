#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CORRECT_NUMBER (41)
// 数あてゲーム（乱数使用版）
int main(void)
{
	int count = 0;
	int ans;
	printf("数字当てゲーム\n");
	while (1) {
		count += 1;
  	printf("1から100までの数字を入れてください\n");
		scanf("%d", &ans);
		if (ans < CORRECT_NUMBER) {
			printf("ざんねん、%d より大きいです\n", ans);
		}else if (CORRECT_NUMBER < ans) {
				printf("ざんねん、%d より小さいです\n", ans);
			}
		else {
			printf("正解！%d回であてました\n",count);
			break;
		}
	}
	return 0;
}
