#include <stdio.h>

// ユークリッド互除法による最大公約数（再帰呼出し版）
int gcd(int x, int y){
    if(y == 0){
        return x;
    }else{
        return gcd(y, x % y);
    }
}

int main(void){
    int x = 72, y = 60, z = 42;
    printf("%dと%dの最大公約数は%dです\n", x, y, gcd(x, y));
    printf("%d，%d，%dの最大公約数は%dです\n", x, y, z, gcd(gcd(x, y), z)); // 3つの整数の最大公約数
}
