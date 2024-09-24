// int型の整数を10個格納する配列arrを宣言し、10個の値を格納して表示
#include <stdio.h>

#define NUM (10)

int main(void){
  int arr[NUM] = {1, 5, 7, 5, 3, 8, 20, 11, 19, 33};

  for(int i = 0; i < NUM; i+=1){
    printf("arr[%d] = %d\n", i, arr[i]);
  }
  return 0;
}
