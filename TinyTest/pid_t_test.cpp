#include <stdio.h>
#include <sys/types.h>

int main() {
  printf("sizeof(pid_t) = %zu bytes\n", sizeof(pid_t));
  printf("sizeof(int)   = %zu bytes\n", sizeof(int));
  printf("sizeof(long)  = %zu bytes\n", sizeof(long));
  printf("sizeof(size_t)  = %zu bytes\n", sizeof(size_t));
  return 0;
}