/*
 * @Author: Amelia
 * @email: zhangshan1@able-elec.com
 * @Date: 2022-08-15 12:38:53
 */
#include <stdlib.h>
#include <stdio.h>
// #include "List.c"
#include "LNode.c"
// #include "DuLNode.c"

int max2(int x, int y) {
  return x > y ? x : y;
}
int main() {
  Book book1 = { "wf", "book", 2 };
  Book book2 = { "wf2", "book2", 5 };
  Book book3 = { "wf3", "book3", 6 };
  plnode node1 = InitLNode();
  LNodeInsert(node1, 0, book1);
  LNodeInsert(node1, 1, book2);
  LNodeInsert(node1, 1, book3);

  Book book4 = { "wf", "book", 1 };
  Book book5 = { "wf2", "book2", 4 };
  Book book6 = { "wf3", "book3", 7 };

  plnode node2 = InitLNode();
  LNodeInsert(node2, 0, book4);
  LNodeInsert(node2, 1, book5);
  LNodeInsert(node2, 2, book6);
  node1 = mergesortedLNode(node1, node2);
  printf("%.1f, %.1f, %.1f", node1->data.price, node1->next->data.price, node1->next->next->data.price);
  return 0;
}
