#include <iostream>
int main() {
   #if __cplusplus == 202302L
      std::cout << "C++23\n";
   #elif __cplusplus == 202002L
      std::cout << "C++20\n";
   #elif __cplusplus == 201703L
      std::cout << "C++17\n";
   #else
      std::cout << "Older standard: " << __cplusplus << "\n";
   #endif
   return 0;
}