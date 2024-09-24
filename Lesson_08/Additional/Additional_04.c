// 基数と指数を入力してべき乗を計算するpower関数

#include <stdio.h>
#include < math.h >
#define NUM 11


int main(void) {
	int scores[NUM] = { 45, 78, 12, 90, 32, 67, 5, 23, 88, 42, 99 };
	double sum, sum_v, mean, variance, variance_u, s_deviation;

	// バブルソート
	for (int i = 0; i < NUM - 1; i += 1) {
		for (int j = NUM - 1; j > i; j -= 1) {
			if (scores[j] > scores[j - 1]) {
				int tmp = scores[j];
				scores[j] = scores[j - 1];
				scores[j - 1] = tmp;
			}
		}
	}
	sum = 0.0;
	sum_v = 0.0;
	for (int i = 0; i < NUM; i += 1) {
		sum = sum + scores[i];
		sum_v = sum_v + scores[i] * scores[i];
	}
	mean = sum / (double)NUM;
	variance = (sum_v - sum * sum / NUM) / (NUM);
	variance_u = (sum_v - sum * sum / NUM) / (NUM - 1);
	s_deviation = sqrt(variance);
	printf("中央値：%d\n", scores[NUM / 2]);
	printf("平均値：%f\n", mean);
	printf("分散：%f\n", variance);
	printf("不偏分散：%f\n", variance_u);
	printf("標準偏差：%f\n", sqrt(s_deviation));
	printf("\n");
	for (int i = 0; i < NUM; i += 1) {
		printf("%d位： 得点：%d　偏差値：%f\n", i + 1, scores[i], 10.0 * ((double)scores[i] - mean)/ s_deviation + 50.0);
	}
	return 0;
}
