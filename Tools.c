/*
 * @Author: Amelia
 * @email: zhangshan1@able-elec.com
 * @Date: 2023-03-27 12:35:05
 */
#include <stdio.h>
#include <string.h>

void printfArr(int *arr, int len) {
  int i;
  char str[len+1];
  for(i = 0; i < len; i++) {
    printf(" %d ", arr[i]);
  }
}
