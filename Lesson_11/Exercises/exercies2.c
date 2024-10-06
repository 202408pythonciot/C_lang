#include <stdio.h>

/* 構造体型struct Personの宣言 */
typedef struct Person{
   int age;
   double weight;
   double height;
}Person;

int main(void)
{
   Person prs[2];
   int i, j;
   
   for(i=0; i<2; i++){
      printf("年齢を入力してください。\n");
      scanf("%d", &prs[i].age);

      printf("体重を入力してください。\n");
      scanf("%lf", &prs[i].weight);

      printf("身長を入力してください。\n");
      scanf("%lf", &prs[i].height);
   }

   for(j=0; j<2; j++){
      printf("年齢%d体重%f身長%fです。\n", 
            prs[j].age, prs[j].weight, prs[j].height);
   }
   return 0;
}
