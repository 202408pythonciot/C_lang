#include <stdio.h>

/* 構造体型struct Carの宣言 */
typedef struct Car{
   int num;
   double gas;
}Car;

/* show関数の宣言 */
void show(Car *pC);

int main(void)
{
   Car car1 = {1234, 20.5};

   printf("ナンバーを入力してください。\n");
   scanf("%d", &car1.num);

   printf("ガソリン量を入力してください。\n");
   scanf("%lf", &car1.gas);

   show(&car1);

   return 0;
}

/* show関数の定義 */
void show(Car *pC)
{
   printf("車のナンバーは%d：ガソリン量は%fです。\n", pC->num, pC->gas);
}
