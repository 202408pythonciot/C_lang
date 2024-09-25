#include<stdio.h>

/* 構造体型struct Carの宣言 */
typedef struct Car{
   int num;
   double gas;
}Car;

int main(void)
{
   printf("int型のサイズは%dバイトです。\n", sizeof(int));
   printf("double型サイズは%dバイトです。\n", sizeof(double));
   printf("構造体struct Car型のサイズは%dバイトです。\n", sizeof(Car));
   printf("構造体struct Car型へのポインタのサイズは%dバイトです。\n", sizeof(Car *));

   return 0;
}
