#include <stdio.h>
#include <float.h>

int main(void) {
   printf("=== Limits of float ===\n");
   printf("Precision (decimal digits): %d\n", FLT_DIG);
   printf("Minimum positive value: %e\n", FLT_MIN);
   printf("Maximum value: %e\n", FLT_MAX);
   printf("Epsilon: %e\n", FLT_EPSILON);
   printf("Min exponent (base %d): %d\n", FLT_RADIX, FLT_MIN_EXP);
   printf("Max exponent (base %d): %d\n", FLT_RADIX, FLT_MAX_EXP);
   printf("Min decimal exponent: %d\n", FLT_MIN_10_EXP);
   printf("Max decimal exponent: %d\n\n", FLT_MAX_10_EXP);

   printf("=== Limits of double ===\n");
   printf("Precision (decimal digits): %d\n", DBL_DIG);
   printf("Minimum positive value: %e\n", DBL_MIN);
   printf("Maximum value: %e\n", DBL_MAX);
   printf("Epsilon: %e\n", DBL_EPSILON);
   printf("Min exponent (base %d): %d\n", FLT_RADIX, DBL_MIN_EXP);
   printf("Max exponent (base %d): %d\n", FLT_RADIX, DBL_MAX_EXP);
   printf("Min decimal exponent: %d\n", DBL_MIN_10_EXP);
   printf("Max decimal exponent: %d\n\n", DBL_MAX_10_EXP);

   printf("=== Limits of long double ===\n");
   printf("Precision (decimal digits): %d\n", LDBL_DIG);
   printf("Minimum positive value: %Le\n", LDBL_MIN);
   printf("Maximum value: %Le\n", LDBL_MAX);
   printf("Epsilon: %Le\n", LDBL_EPSILON);
   printf("Min exponent (base %d): %d\n", FLT_RADIX, LDBL_MIN_EXP);
   printf("Max exponent (base %d): %d\n", FLT_RADIX, LDBL_MAX_EXP);
   printf("Min decimal exponent: %d\n", LDBL_MIN_10_EXP);
   printf("Max decimal exponent: %d\n", LDBL_MAX_10_EXP);

   return 0;
}
