#include <stdio.h>
#define SQUARE(x) (x * x)

int main(void)
{
   int num, ans;

   printf("整数を入力してください。\n");
   scanf("%d", &num);

   ans = SQUARE(num);

   printf("%dの2乗は%dです。\n", num, ans);

   return 0;
}
