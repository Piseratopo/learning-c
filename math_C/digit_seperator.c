#include <stdio.h>

int main(){
   printf("C supports digit separator, such as 123'45'6789 can be interpreted as %d.\n", 123'45'6789);
   printf("This works with decimals: 10'035.677'789 is %f.\n", 10'035.677'789);
   
   printf("It also works with hexadecimal: 0xFF'AB'CD is %x.\n", 0xFF'AB'CD);
   printf("It works with binary too: 0b1010'1010 is %d.\n", 0b1010'1010);
   return 0;
}