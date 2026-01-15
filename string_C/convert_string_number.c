#include <stdio.h>
#include <stdlib.h>

int main() {
   char long_str[] = "12345";
   char *end;
   long int num = strtol(long_str, &end, 13);
   printf("%ld\n", num);
   return 0;
}