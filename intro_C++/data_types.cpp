#include <iostream>

int main() {
   int i = 10;
   int j = {20};
   int k{30};
   std::cout << "i = " << i << ", j = " << j << ", k = " << k << "\n";

   auto c = "c";
   auto i2 = 10;
   // char *
   // int
   auto f = 1.5;   // double
   auto b{false};  // bool
   std::cout << "c = " << c << ", i2 = " << i2 << ", f = " << f << ", b = " << b << "\n";
}