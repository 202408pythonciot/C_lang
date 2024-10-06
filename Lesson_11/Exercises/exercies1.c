#include <stdio.h>

/* 構造体型struct Personの宣言 */
typedef struct Person{
   int age;
   double weight;
   double height;
}Person;

int main(void)
{
   Person prs1, prs2;
   
   printf("年齢を入力してください。\n");
   scanf("%d", &prs1.age);

   printf("体重を入力してください。\n");
   scanf("%lf", &prs1.weight);

   printf("身長を入力してください。\n");
   scanf("%lf", &prs1.height);

   printf("年齢を入力してください。\n");
   scanf("%d", &prs2.age);

   printf("体重を入力してください。\n");
   scanf("%lf", &prs2.weight);

   printf("身長を入力してください。\n");
   scanf("%lf", &prs2.height);

   printf("年齢%d体重%f身長%fです。\n", 
         prs1.age, prs1.weight, prs1.height);

   printf("年齢%d体重%f身長%fです。\n", 
         prs2.age, prs2.weight, prs2.height);

   return 0;
}
