#include <stdio.h>

// ユークリッド互除法による最大公約数
int gcd(int x, int y){
    int temp;

    while (y != 0) {
        temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

int lcm(int x, int y){
  return x * y / gcd(x, y);
}

int main(void){
    int x = 3, y = 7, z = 12;
    printf("%dと%dの最小公倍数は%dです\n", x, y, lcm(x, y));
    printf("%d，%d，%dの最小公倍数は%dです\n", x, y, z, lcm(lcm(x, y), z)); // 3つの整数の最小公倍数
}
