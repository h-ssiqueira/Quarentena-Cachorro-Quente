#include <stdio.h>
int main(){
   int i;
   printf("\n");
/*██████╗     */for(i=0; i<6; i++) printf("%c",219); printf("%c",187);
/*██╔══██╗    */printf("\n%c%c%c%c%c%c%c%c",219,219,201,205,205,219,219,187);
/*██║  ██║    */printf("\n%c%c%c  %c%c%c",219,219,186,219,219,186);
/*██║  ██║    */printf("\n%c%c%c  %c%c%c\n",219,219,186,219,219,186);
/*██████╔╝    */for(i=0; i<6; i++) printf("%c",219);printf("%c%c",201,188);
/*╚═════╝     */printf("\n%c",200);for(i=0;i<5;i++) printf("%c",205);printf("%c",188);

printf("\n");

/* ██████╗ */  printf(" ");for(i=0; i<6; i++) printf("%c",219); printf("%c",187);
/*██╔═══██╗*/  printf("\n%c%c%c%c%c%c%c%c%c",219,219,201,205,205,205,219,219,187);
/*██║   ██║*/  printf("\n%c%c%c   %c%c%c",219,219,186,219,219,186);
/*██║   ██║*/  printf("\n%c%c%c   %c%c%c",219,219,186,219,219,186);
/*╚██████╔╝*/  printf("\n%c",200);for(i=0; i<6; i++) printf("%c",219);printf("%c%c",201,188);
/* ╚═════╝ */  printf("\n ");printf("%c",200);for(i=0;i<5;i++) printf("%c",205);printf("%c",188);


return 0;
}
