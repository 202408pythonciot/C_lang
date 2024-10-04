# 乱数
## 標準ライブラリのrand関数
0 ～ RAND_MAX の範囲で整数の一様な疑似乱数を生成する関数が用意されている。
```
#include <stdio.h>

int rand();
```

ただし，乱数の種が同じであると，同じ乱数列を`rand()`は返す。そこで`srand()`を現在時刻を与えて乱数の種を初期化することが行われる。

```
#include <stdio.h>
#include <time.h>

int main(void){
    srand((unsigned int) time(NULL)); //現在時刻を元に種を生成
    printf("%d\n", rand());
    return 0;
}
```

