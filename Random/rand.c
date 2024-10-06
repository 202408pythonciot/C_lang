#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 乱数列の初期化
void rand_init(void){
    srand((unsigned int) time(NULL)); // 現在時刻を元に種を生成
}

// 整数mからnの範囲（ただし，m < n）での乱数取得
int rand_i(int m, int n){
    return (int)(m + rand() % (n - m + 1));
}

int main(void){
    rand_init();
    printf("%d\n", rand_i(5, 20));
    return 0;
}
