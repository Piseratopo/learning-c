/*
   This program calculates the volume of a tank with integer sizes,
      then calculates how many 13-sized cups needed to fill the tank.
*/

#include <stdio.h>

int main() {
   int length, width, height, volume;
   int cup_needed;
   printf("Length of the tank: ");
   scanf("%d", &length);
   printf("Width of the tank: ");
   scanf("%d", &width);
   printf("Height of the tank: ");
   scanf("%d", &height);

   volume = length * width * height;
   printf("The volume of the tank is: %d\n", volume);
   
   cup_needed = (volume + 12) / 13;
   printf("The number of cups needed to fill the tank is: %d", cup_needed);

   return 0;
}