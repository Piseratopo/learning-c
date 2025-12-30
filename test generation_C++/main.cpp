// main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include "gen.h"

int main() {
   std::string random_string = generate_random_string(
      1000, 
      {"punctuation", "digit", "letter"},
      " "
   );

   std::ofstream input_file("input.txt");
   if (input_file.is_open()) {
      input_file << random_string << '\n';
      input_file.close();
   }

   std::ofstream output_file("output.txt");
   if (output_file.is_open()) {
      output_file << '"' << random_string << '"';
      output_file.close();
   }

   return 0;
}