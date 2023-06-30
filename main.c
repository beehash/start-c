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
#include "String.c"
// extern int isPalindromic(char *s);
// extern int InputStack();
// extern int computeSuffixStr();
// extern isLegalSequence(char *str);
// extern Ack2(int m, int n);

int main() {
  // int result = isPalindromic("abcba");
  // char str[4] = "abba";
  // printf("a[3], %c", *(str+3));
  // printf("isPalindromic: %d", result);
  // computeSuffixStr();
  // char *str = "IOIIOIOO";
  // int result = isLegalSequence(str);
  // printf("result: %d\n", result);
  // int result = Ack2(2, 1);
  // printf("result=%d\n", result);
  char tmp[19]= "abcaabbabcaaacbacba";
  char needle[10] = "ababaabab";
  char haystack[12] = "mississippi";
  char phrapy[] = "   aaeerdxpffbb ddwwsxcododkkv d ";
  // int *next = getNext2(tmp);
  // getnextval2(tmp);
  revertString2(haystack);
  printf("\nreverted string is: %s\n", haystack);
  // Insert(needle, haystack, 5);
  // char s2[9];char s3[25];
  // printf("%s----%d\n", phrapy, strlen(s2));
  // Format(phrapy, s2, s3, 8);
  // printf("%s----%s----%d\n", phrapy, s2, strlen(s2));
  // printf("%s-- ,--%s-- , --%s--, --%d", phrapy, s2, s3, strlen(s2));
  // int darr[][10] = {
  //   {21,5,113,11,149,147,173,182,146,80},
  //   {108,50,59,81,74,65,71,40,97,90},
  //   {45,83,282,165,13,43,20,171,63,27},
  //   {25,62,85,56,79,66,21,32,42,91},
  // };
  // int arr[] = {-21,5,113,-11,149,147,173,-182,146,-80, -25,-62,85,-56,79,66,21,-32,42,91};
  // int result = hasSameInDarr(darr, 4, 10);
  // printf("hasSame=%d", result);
  // sortInt(arr, 20);

  return 0;
}
