#include <stdio.h>

// 100までのFizzBuzz（剰余算を使わない）
int main(void){
  int n3 = 3, n5 = 5;
  for(int i = 1; i < 101; i += 1){
    if(i != n3 && i != n5){
      printf("%d", i);
    }
    if(i == n3){  // 3で割り切れる
      printf("Fizz");
      n3 = n3 + 3;
    }
    if(i == n5){  // 5で割り切れる
      printf("Buzz");
      n5 = n5 + 5;
    }
    printf("\n");
  }
  return 0;
}
