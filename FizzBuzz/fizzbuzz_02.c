#include <stdio.h>

// 100までのFizzBuzz（15の倍数をチェックしない）
int main(void){
  for(int i = 1; i < 101; i += 1){
    int f3 = i % 3, f5 = i % 5;
    if(!f3){  // 3で割り切れる
      printf("Fizz");
    }
    if(!f5){  // 5で割り切れる
      printf("Buzz");
    }
    if(f3 && f5){
      printf("%d", i);
    }
    printf("\n");
  }
  return 0;
}
