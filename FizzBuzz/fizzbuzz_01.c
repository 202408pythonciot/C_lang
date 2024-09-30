#include <stdio.h>

// 100までのFizzBuzz
int main(void){
    for(int i = 1; i < 101; i += 1){
        if(i % 15 == 0){   // 15で割り切れる i % 5 == 0 && i % 3 ==0 でも同等
            printf("FizzBuzz\n");
        }else if(i % 3 == 0){  // 3で割り切れる
            printf("Fizz\n");
        }else if(i % 5 == 0){  // 5で割り切れる
            printf("Buzz\n");
        }else{
            printf("%d\n", i);
        }
    }
    return 0;
}
