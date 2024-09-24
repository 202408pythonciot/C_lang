#include <stdio.h>

int a = 0;

/* funcŠÖ”‚Ì’è‹` */
void func(void)
{
   int b = 0;
   static int c = 0;

   printf("•Ï”a‚Í%d•Ï”b‚Í%d•Ï”c‚Í%d‚Å‚·B\n", a, b, c);

   a++;
   b++;
   c++;
}

/* mainŠÖ”‚Ì’è‹` */
int main(void)
{
   int i;

   for(i=0; i<5; i++)
      func();

  return 0;
}
