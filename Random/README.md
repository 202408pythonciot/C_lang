# 乱数
## 標準ライブラリのrand関数
0 ～ RAND_MAX の範囲で整数の一様な疑似乱数を生成する関数が用意されている。
```C
#include <stdio.h>

int rand();
```

ただし，乱数の種が同じであると，`rand()`は同じ乱数列の順番で返す。そこで`srand()`を現在時刻を与えて乱数の種を初期化することが行われる。

```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand((unsigned int) time(NULL)); //現在時刻を元に種を生成
    printf("%d\n", rand());
    return 0;
}
```

## 任意の整数の範囲の乱数
```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 整数 m から nの間の範囲の乱数を戻す
int my_rand(int m, int n){
    return (int)(m + rand() % (n - m + 1));
}

int main(void){
    srand((unsigned int) time(NULL)); //現在時刻を元に種を生成
    printf("%d\n", my_rand(5, 10));   // 5から10の範囲の乱数を戻す
    return 0;
}
```

