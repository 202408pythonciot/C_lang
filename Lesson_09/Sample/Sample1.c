#include <stdio.h>

int main(void)
{
   int a;

   a = 5;

   printf("変数aの値は%dです。\n", a);
   printf("変数aのアドレスは%pです。\n", &a);	

   return 0;
}
