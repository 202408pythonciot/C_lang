#include <stdio.h>

/* avg関数の宣言 */
double avg(int *pT);

int main(void)
{
   int test[5];
   int i;
   double ans;

   printf("5人のテストの点数を入力してください。\n"); 

   for(i=0; i<5; i++){
      scanf("%d", &test[i]);
   }

   ans = avg(test);

   printf("5人の平均点は%f点です。\n", ans);

   return 0;
}

/* avg関数の定義 */
double avg(int *pT)
{
   int i;
   double sum;

   sum = 0.0;
   
   for(i=0; i<5; i++){
      sum += pT[i];
   }
   return sum/5;
}
