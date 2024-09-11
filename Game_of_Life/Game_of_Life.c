#include <stdio.h>
#include <windows.h>

#define N  22  /* 縦方向 */
#define M  78  /* 横方向 */
char a[N + 2][M + 2], b[N + 2][M + 2];  /* 盤 */

void clear(void) {
    printf("\x1b[2J");
}
void cursor(int x, int y) {
    printf("\x1b[%d;%dH", y + 1, x + 1);
}

int main(void)
{
    a[N / 2][M / 2] = a[N / 2 - 1][M / 2] = a[N / 2 + 1][M / 2]
        = a[N / 2][M / 2 - 1] = a[N / 2 - 1][M / 2 + 1] = 1;  /* 初期状態 */
    for (int g = 1; g <= 250; g++) {
        clear();
        printf("Generation %4d\n", g);  /* 世代 */
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (a[i][j]) {
                    cursor(j, i);
                    printf("*");
                    b[i - 1][j - 1]++;  b[i - 1][j]++;  b[i - 1][j + 1]++;
                    b[i][j - 1]++;                b[i][j + 1]++;
                    b[i + 1][j - 1]++;  b[i + 1][j]++;  b[i + 1][j + 1]++;
                }
                else {
                    cursor(j, i);
                    printf(".");
                }
            }
            printf("\n");
        }
        for (int i = 0; i <= N + 1; i++) {
            for (int j = 0; j <= M + 1; j++) {
                if (b[i][j] != 2) a[i][j] = (b[i][j] == 3);
                b[i][j] = 0;
            }
        }
        Sleep(250);
    }
    return 0;
}
