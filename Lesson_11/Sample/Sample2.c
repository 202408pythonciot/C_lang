#include <stdio.h>

/* 構造体型struct Carの宣言 */
struct Car{
   int num;
   double gas;
};

int main(void)
{
   struct Car car1;

   printf("ナンバーを入力してください。\n");
   scanf("%d", &car1.num);

   printf("ガソリン量を入力してください。\n");
   scanf("%lf", &car1.gas);

   printf("車のナンバーは%d：ガソリン量は%fです。\n", car1.num, car1.gas);

   return 0;
}
