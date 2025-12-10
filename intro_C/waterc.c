/* Compute how many bowls are needed for a given amount of water put in a water box */

#include <stdio.h>

int main(void) {
   int height, length, width, volume, num_bowls;

   height = 8;
   length = 12;
   width = 10;
   printf("Height: %d,\nLength: %d,\nWidth: %d\n", height, length, width);
   
   volume = height * length * width;


   num_bowls = (volume + 122) / 123;
   printf("You need %d bowls of water\n", num_bowls);
   return 0;
}