// コラッツ(Collatz)予想
// オーバーフロー対策済み＆再帰呼び出し
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT ((ULONG_MAX - 1) / 3)

int solve_collatz(int n) {
    printf(" %lu", n);
    if (n == 1) {
        return 1;
    }else if (n & 1) {  // 奇数
        if (n > LIMIT) {
            printf("\nOverflow\n");
            return 0;
        }
        else {
            return solve_collatz(3 * n + 1);
        }
    }
    else {  // 偶数
        return solve_collatz(n / 2);
    }
    return n;
}

int main(void)
{
    unsigned long  n;

    printf("n = ");
    scanf("%lu", &n);
    printf("\n");
    solve_collatz(n);
    printf("\n");
    return 0;
}
