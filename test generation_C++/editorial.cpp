#include <stdio.h>
#include <math.h>

void printNoSolution() {
   printf(
      "V\u00F4 nghi\u1EC7m"
   );
}

int main() {
   int T;
   scanf("%d", &T);
   for(int i = 0; i < T; i++) {
      double a, b, c;
      scanf("%lf %lf %lf", &a, &b, &c);
      double x, y, z;
      if (fabs(a - b) < 10e-6 && fabs(c + 1) < 10e-6) {
         x = 1.0f;
         y = a - x;
         z = x * c;
         printf("%f %f %f\n", x, y, z);
      } else if (fabs(a - b) < 10e-6 || fabs(c + 1) < 10e-6) {
         printNoSolution();
         printf("\n");
      } else {
         x = (a - b) / (c + 1.0);
         y = a - x;
         z = c * x;
         printf("%f %f %f\n", x, y, z);
      }
    }
}
