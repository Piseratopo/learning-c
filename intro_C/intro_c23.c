#include <stdio.h>

int main() {
   printf("Hello, C23!\n");
   printf("To compile, run: gcc -std=c23 -Wall -o intro_c23 intro_c23.c -lm\n");

   int* ptr = nullptr;
   if (ptr == nullptr) {
      printf("Pointer is null as expected in C23.\n");
   }

   return 0;
}