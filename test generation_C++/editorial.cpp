#include <stdio.h>

int main() {
   char s[1010];
   scanf("%[^\n]", s);
   printf("\"%s\"", s);
   return 0;
}