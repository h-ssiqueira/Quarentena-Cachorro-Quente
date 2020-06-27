#include<stdio.h>

int main(){


/*     ██╗*/ printf("     %c%c%c\n",219,219,187);
/*   ██╔═╝*/ printf("   %c%c%c%c%c\n",219,219,201,205,188);
/*   ╚═╝  */ printf("   %c%c%c  \n",200,205,188);
/*███████╗*/ for(int i = 0; i < 7; i++) printf("%c",219); printf("%c\n",187);
/*██╔════╝*/ printf("%c%c",219,219); printf("%c",201);for(int i = 0; i < 4; i++) printf("%c",205);printf("%c\n",188);
/*█████╗  */ for(int i = 0; i < 5; i++) printf("%c",219); printf("%c  \n",187);
/*██╔══╝  */ printf("%c%c",219,219); printf("%c",201); printf("%c%c",205,205); printf("%c  \n",188);
/*███████╗*/ for(int i = 0; i < 7; i++) printf("%c",219); printf("%c\n",187);
/*╚══════╝*/ printf("%c",200); for(int i = 0; i < 6; i++) printf("%c",205); printf("%c\n",188);

/*  ██╗ ██╗*/ printf("  %c%c%c %c%c%c\n",219,219,187,219,219,187);
/*██╔═██╔═╝*/ printf("%c%c%c%c%c%c%c%c%c\n",219,219,201,205,219,219,201,205,188);
/*╚═╝ ╚═╝  */ printf("%c%c%c %c%c%c  \n",200,205,188,200,205,188);
/* █████╗ */ printf(" ");for(int i = 0; i < 5; i++) printf("%c",219); printf("%c ",187);
/*██╔══██╗*/ printf("%c%c",219,219);printf("%c",201);printf("%c%c",205,205);printf("%c%c",219,219);printf("%c",187);
/*███████║*/ for(int i = 0; i < 7; i++) printf("%c",219); printf("%c",186);
/*██╔══██║*/ printf("%c%c",219,219);printf("%c",201);printf("%c%c",205,205);printf("%c%c",219,219);printf("%c",186);
/*██║  ██║*/ printf("%c%c",219,219);printf("%c  ",186);printf("%c%c",219,219);printf("%c",186);
/*╚═╝  ╚═╝*/ printf("%c%c%c  %c%c%c",200,205,188,200,205,188);

return 0;
}
