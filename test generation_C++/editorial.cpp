#include <stdio.h>
#include <stdlib.h>

int main() {
   int N;
   scanf("%d", &N);

   int last_digit = N % 10;
   int prefix_N = N / 10;
   int pos;
   for (pos = 1; pos <= prefix_N; pos *= 10);
   
   int diff = abs(last_digit * pos + prefix_N - N);
   printf("%d", diff);
   
   return 0;
}
