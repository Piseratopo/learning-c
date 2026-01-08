#include <stdio.h>

int main() {
   int T;
   scanf("%d", &T);
   for(int i = 0; i < T; i++) {
      double X, Y;
      scanf("%lf %lf", &X, &Y);
      double sumigrezulto = X + Y;
      double subtrahrezulto = X - Y;
      double obligrezulto = X * Y;
      double dividrezulto = X / Y;
      printf("%.3e %.3e %.3e %.3e\n", sumigrezulto, subtrahrezulto, obligrezulto, dividrezulto);
   }
}
