#include <stdio.h>

int main() {
    int a, b, c;
    scanf("+%d (%d)-%d", &a, &b, &c);
    printf("0%.3d %.3d %.3d", a, b, c);
}
