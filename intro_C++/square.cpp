#include <iostream>

int square(int x);
float square(float x);

int main() {
   int a;
   float b;
   std::cout << "Enter an integer: ";
   std::cin >> a;
   std::cout << "Square of " << a << " is " << square(a) << "\n";

   std::cout << "Enter a float: ";
   std::cin >> b;
   std::cout << "Square of " << b << " is " << square(b) << "\n";

   return 0;
}

int square(int x) {
   return x * x;
}

float square(float x) {
   return x * x;
}