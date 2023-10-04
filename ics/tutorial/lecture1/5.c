#include <stdio.h>
#define NAMES(X) \
  X(Tom) X(Jerry) X(Tyke) X(Spike)

int main() {
  #define PRINT(x) puts("Hello, " #x "!");
  NAMES(PRINT)
  #define PRINT1(x) puts("good bye, " #x "!");
  NAMES(PRINT1)
}
