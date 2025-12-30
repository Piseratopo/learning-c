// #include <stdio.h>

// int main() {
//    char s[1010];
//    scanf("%[^\n]", s);
//    printf("\"%s\"", s);
//    return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main() {
//    char s[1010];
//    fgets(s, sizeof(s), stdin);
//    size_t len = strlen(s);
//    if (len > 0 && s[len - 1] == '\n') {
//       s[len - 1] = '\0';
//    }
//    printf("\"%s\"", s);
//    return 0;
// }

#include <iostream>
#include <string>

int main() {
   std::string s;
   std::getline(std::cin, s);

   std::cout << "\"" << s << "\"";

   return 0;
}
