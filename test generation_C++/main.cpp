// main.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include "gen.h"

int main() {
   // Generate a random string of length 1000
   std::string random_string = generate_random_string(
      1000, 
      {"letter", "digit", "punctuation"},
      ""
   );

   // Write to input.txt
   std::ofstream input_file("input.txt");
   if (input_file.is_open()) {
      input_file << random_string << '\n';
      input_file.close();
   }

   // Write to output.txt with quotes
   std::ofstream output_file("output.txt");
   if (output_file.is_open()) {
      output_file << '"' << random_string << '"';
      output_file.close();
   }

   return 0;
}