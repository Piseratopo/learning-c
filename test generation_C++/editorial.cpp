#include <iostream>
#include <string>

int main() {
   std::string input;

   // Read a line of UTF-8 text from the terminal
   std::getline(std::cin, input);

   // Print it back in quotation marks
   std::cout << "\"" << input << "\"" << std::endl;

   return 0;
}
