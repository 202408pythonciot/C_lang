#include <stdio.h>

int main(void)
{
   int a, b;
   int *pA;

   a = 5;
   b = 10;

   pA = &a;

   printf("変数aの値は%dです。\n", a);
   printf("ポインタpAの値は%pです。\n", pA);	
   printf("*pAの値は%dです。\n", *pA);	

   pA = &b;

   printf("変数bの値は%dです。\n", b);
   printf("ポインタpAの値は%pに変更されました。\n", pA);	
   printf("*pAの値は%dです。\n", *pA);	

   return 0;
}
