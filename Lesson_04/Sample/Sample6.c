#include <stdio.h>

int main(void)
{
   int sum = 0;
   int num = 0;

   printf("1番目の整数を入力してください。\n");
   scanf("%d", &num);
   sum += num;

   printf("2番目の整数を入力してください。\n");
   scanf("%d", &num);
   sum += num;

   printf("3番目の整数を入力してください。\n");
   scanf("%d", &num);
   sum += num;

   printf("3つの数の合計は%dです。\n", sum);

   return 0;
}
