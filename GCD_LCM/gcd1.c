#include <stdio.h>

// ユークリッド互除法による最大公約数
int gcd(int x, int y){
    int t;

    while (y != 0) {
        t = x % y;
        x = y;
        y = t;
    }
    return x;
}

int main(void){
    int x = 72, y = 60, z = 42;
    printf("%dと%dの最大公約数は%dです\n", x, y, gcd(x, y));
    printf("%d，%d，%dの最大公約数は%dです\n", x, y, z, gcd(gcd(x, y), z));
}
