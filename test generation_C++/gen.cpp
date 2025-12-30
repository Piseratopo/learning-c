// gen.cpp
#include "gen.h"
#include <random>
#include <set>
#include <cctype>

std::string generate_random_string(
   size_t length,
   const std::vector<std::string>& allowed_types,
   const std::string& allowed_chars
) {
   std::set<char> chars(allowed_chars.begin(), allowed_chars.end());
   
   for (const auto& type : allowed_types) {
      if (type == "letter") {
         for (char c = 'a'; c <= 'z'; c++) {
            chars.insert(c);
            chars.insert(toupper(c));
         }
      }
      else if (type == "digit") {
         for (char c = '0'; c <= '9'; c++) {
            chars.insert(c);
         }
      }
      else if (type == "punctuation") {
         std::string punct = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
         chars.insert(punct.begin(), punct.end());
      }
      else if (type == "whitespace") {
         chars.insert(' ');
         chars.insert('\t');
         chars.insert('\n');
         chars.insert('\r');
         chars.insert('\v');
         chars.insert('\f');
      }
   }
   
   std::vector<char> char_vector(chars.begin(), chars.end());
   if (char_vector.empty()) {
      return "";
   }
   
   std::random_device rd;
   std::mt19937 gen(rd());
   std::uniform_int_distribution<> dis(0, char_vector.size() - 1);
   
   std::string result;
   result.reserve(length);
   for (size_t i = 0; i < length; ++i) {
      result += char_vector[dis(gen)];
   }
   
   return result;
}