#include <stdio.h>

int a = 0; 

/* func関数の定義 */
void func(void)
{
   int c = 2;

   printf("func関数では変数aとcが使えます。\n");
   printf("変数aの値は%dです。\n", a);
   /* printf("変数bの値は%dです。\n", b); */
   printf("変数cの値は%dです。\n", c);
}

/* main関数の定義 */
int main(void)
{
   int b = 1;

   printf("main関数では変数aとbが使えます。\n");
   printf("変数aの値は%dです。\n", a);
   printf("変数bの値は%dです。\n", b);
   /* printf("変数cの値は%dです。\n", c); */

   func();

   return 0;
}
