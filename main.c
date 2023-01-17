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
#include "StackNode.c"

int main() {
  StackL s = initStackNode();
  int isEmpty = isEmptyStack(s);
  printf("isEmpty: %d \n", isEmpty);
  pushStack(s, 1);
  isEmpty = isEmptyStack(s); 
  printf("isEmpty: %d , s->top->data: %d \n", isEmpty, s->top->data);
  return 0;
}
