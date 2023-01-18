/*
 * @Author: Amelia
 * @email: zhangshan1@able-elec.com
 * @Date: 2022-08-15 12:38:53
 */
#include <stdio.h>
#include <stdlib.h>
// #include "List.c"
// #include "chapter2.c"
// #include "DuLNode.c"
// #include "DoubleStack.c"
// #include "QueueNode.c"
extern int isPalindromic(char *s);

int main() {
  int result = isPalindromic("abcba");
  // char str[4] = "abba";
  // printf("a[3], %c", *(str+3));
  printf("isPalindromic: %d", result);
  return 0;
}
