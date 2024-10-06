#include <stdio.h>

/* power関数の宣言 */
int power(int x, int y);

int main(void)
{
   int num1, num2, ans;

   printf("1番目の整数を入力してください。（1～5）\n");
   scanf("%d",&num1);

   printf("2番目の整数を入力してください。（1～5）\n");
   scanf("%d",&num2);

   ans = power(num1, num2);

   printf("%dの%d乗は%dです。\n", num1, num2, ans);

   return 0;
}

/* power関数の定義 */
int power(int x, int y)
{
   int i;
   int pow = 1; 

   for(i=1; i<=y; i++){
      pow = pow * x;
   }
   return pow;
}
