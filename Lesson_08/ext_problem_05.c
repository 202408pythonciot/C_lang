#include <stdio.h>
#define NUMBER_OF_PRIMES 15

// 素数
int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };

// 以下は自分で実装する。
void factorize_primes(int m)
{
    int counter[NUMBER_OF_PRIMES] = { 0 };
    int p, n = m;
    p = NUMBER_OF_PRIMES - 1;
        
    while(p >= 0){
        if (n % primes[p] == 0) {
            n = n / primes[p];
            counter[p] += 1;
        }
        else {
            p -= 1;
        }
    }
    int flag = 0;
    printf("%d = ", m);
    for (int i = 0; i < NUMBER_OF_PRIMES; i += 1) {
        if (flag != 0 && counter[i] > 0) {
            printf(" + ");
        }
        if (counter[i] > 0) {
            printf("%d^%d", primes[i], counter[i]);
            flag = 1;
        }
    }
    printf("\n");
}

int main(void) {
    factorize_primes(81);
    factorize_primes(121);
    factorize_primes(504);
}
