#include <stdio.h>

/* —ñ‹“Œ^enum Week‚ÌéŒ¾ */
typedef enum Week{SUN, MON, TUE, WED, THU, FRI, SAT} Week;

int main(void)
{
   Week w;
   w = SUN;

   switch(w){
      case SUN: printf("“ú—j‚Å‚·B\n"); break;
      case MON: printf("Œ—j‚Å‚·B\n"); break;
      case TUE: printf("‰Î—j‚Å‚·B\n"); break;
      case WED: printf("…—j‚Å‚·B\n"); break;
      case THU: printf("–Ø—j‚Å‚·B\n"); break;
      case FRI: printf("‹à—j‚Å‚·B\n"); break;
      case SAT: printf("“y—j‚Å‚·B\n"); break;
      default: printf("‰½—j“ú‚¾‚©‚í‚©‚è‚Ü‚¹‚ñB\n"); break;
   }

   return 0;
}
