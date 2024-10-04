#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_init(void){
    srand((unsigned int) time(NULL)); //現在時刻を元に種を生成
}

int rand_i(int m, int n){
    return (int)(m + rand() % (n - m + 1));
}

int main(void){
    rand_init();
    printf("%d\n", rand_i(5, 20));
    return 0;
}
