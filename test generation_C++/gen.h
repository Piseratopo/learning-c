// gen.h
#ifndef GEN_H
#define GEN_H

#include <string>
#include <vector>

std::string generate_random_string(
   size_t length,
   const std::vector<std::string>& allowed_types = {"letter"},
   const std::string& allowed_chars = ""
);

#endif // GEN_H