#include <stdio.h>

/* 構造体型struct Personの宣言 */
typedef struct Person{
   int age;
   double weight;
   double height;
}Person;

/* aging関数の宣言 */
void aging(Person *p);

int main(void)
{
   Person prs;
   
   printf("年齢を入力してください。\n");
   scanf("%d", &prs.age);

   printf("体重を入力してください。\n");
   scanf("%lf", &prs.weight);

   printf("身長を入力してください。\n");
   scanf("%lf", &prs.height);

   printf("年齢%d体重%f身長%fです。\n", 
        prs.age, prs.weight, prs.height);

   aging(&prs);

   printf("1年経過しました。\n");

   printf("年齢%d体重%f身長%fです。\n", 
        prs.age, prs.weight, prs.height);

   return 0;
}

/* aging関数の定義 */
void aging(Person* p)
{
   p->age++;
}
