// コラッツ(Collatz)予想
// オーバーフロー対策済み
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIMIT ((ULONG_MAX - 1) / 3)

int main(void)
{
    unsigned long  n;

    printf("n = ");
    scanf("%lu", &n);
    printf("\n");
    while (n > 1) {
        if (n & 1) {  // 奇数
            if (n > LIMIT) {
                printf("\nOverflow\n");  return 1;
            }
            else {
                n = 3 * n + 1;
            }
        }
        else {  // 偶数
            n = n / 2;
        }
        printf(" %lu", n);
    }
    printf("\n");
    return 0;
}
