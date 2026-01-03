#include <stdio.h>
#include <string.h>

int main() {
   int T;
   scanf("%d", &T);
   for(int i = 0; i < T; i++) {
      char N[100010];
      scanf(" %s ", N);
      int remainder = 0;
      for(int j = 0; j < strlen(N); j++) {
         remainder = (remainder * 10 + (N[j] - '0')) % 11;
      }
      if(remainder == 0) {
         printf("C\n");
      } else {
         printf("K\n");
      }
   }

   return 0;
}
