#include <stdio.h>

int main(void)
{
   int num, sum;
   int i;

   num = 0;
   sum = 0;

   printf("いくつまでの合計を求めますか？\n");
   scanf("%d", &num);

   for(i=1; i<=num; i++){
      sum += i; 
   }

   printf("1から%dまでの合計値は%dです。\n", num, sum);

   return 0;
}
