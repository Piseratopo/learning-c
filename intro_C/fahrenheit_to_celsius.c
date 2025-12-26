/* Converts a Fahrenheit temperature to Celsius */ 

#include <stdio.h>

#define FREEZING_POINT 32.0f
#define SCALING_FACTOR (5.0f / 9.0f)

int main() {
   float fahrenheit, celsius;

   printf("Enter Fahrenheit temperature: ");
   scanf("%f", &fahrenheit);

   celsius = (fahrenheit - FREEZING_POINT) * SCALING_FACTOR;
   printf("Celsius equivalent: %.1f\n", celsius);

   return 0;
}