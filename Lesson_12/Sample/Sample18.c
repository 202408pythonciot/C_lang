#include <stdio.h>
int main(void)
{
   int i;
   int sum = 0;

   fprintf(stderr, "ソースファイル名：%s\n", __FILE__);
   fprintf(stderr, "作成日付：%s\n", __DATE__);
   fprintf(stderr, "作成時刻：%s\n", __TIME__);
   for(i=1; i<=5; i++){
      sum = i + sum;
   }
   printf("1～5までの合計値は%dです。\n", sum);

   return 0;
}
