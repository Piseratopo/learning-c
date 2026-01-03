#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <random>

int main() {
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(pow(10, 13), pow(10, 14) - 1);

   int T = 100000;
   std::string input_text = std::to_string(T) + "\n";
   std::string output_text;

   for (int t = 0; t < T; ++t) {
      int a = dis(gen);
      input_text += std::to_string(a) + "\n";
      output_text += (a % 11 == 0) ? "C\n" : "K\n";
   }

   std::ofstream input_file("input.txt");
   input_file << input_text;
   input_file.close();

   std::ofstream output_file("output.txt");
   output_file << output_text;
   output_file.close();

   return 0;
}