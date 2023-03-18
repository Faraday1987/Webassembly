#include <string.h>

void numLog( int n);
void strLog( char * offset, length);

int main() { 
  return 42;
}

int getNumber() {
  return 22;
}

int getDoubbleNumber( int x) {
  return x*2;
}

void getDoubble( int x) {
  numLog(x*2);
}

void greet() {
  char * msg = "Hello from C !";
  strLog(msg, strlen(msg) );
}