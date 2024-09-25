#include <stdio.h>

int main(void)
{
   double num;
   
   printf("小数を入力してください。\n");
   scanf("%lf", &num);

   printf("小数点以下3ケタで出力すると%.3fです。\n", num);

   return 0;
}
