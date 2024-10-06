#include <stdio.h>

/* square関数の宣言 */
int square(int x);

int main(void)
{
   int num, ans;

   printf("整数を入力してください。\n");
   scanf("%d", &num);

   ans = square(num);

   printf("%dの2乗は%dです。\n", num, ans);

   return 0;
}

/* square関数の定義 */
int square(int x)
{
   return x * x;
}
