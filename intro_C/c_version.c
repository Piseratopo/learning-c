#include <stdio.h>

int main() {
   printf("C Standard Version: ");
   
   #ifdef __STDC_VERSION__
      #if __STDC_VERSION__ == 199409L
         printf("C94/C95\n");
      #elif __STDC_VERSION__ == 199901L
         printf("C99\n");
      #elif __STDC_VERSION__ == 201112L
         printf("C11\n");
      #elif __STDC_VERSION__ == 201710L
         printf("C17\n");
      #elif __STDC_VERSION__ > 201710L
         printf("C2X (or later)\n");
      #else
         printf("Unknown C standard (__STDC_VERSION__ = %ld)\n", __STDC_VERSION__);
      #endif
   #else
      printf("Pre-C89/ANSI C\n");
   #endif

   printf("Compiled with GCC %d.%d.%d\n", 
         __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
   
   return 0;
}