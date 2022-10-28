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
  Book book9 = { "wf3", "book3", 12 };
  plnode node1 = InitLNode();
  LNodeInsert(node1, 0, book1);
  LNodeInsert(node1, 1, book2);
  LNodeInsert(node1, 2, book3);
  LNodeInsert(node1, 3, book9);

  Book book4 = { "wf", "book", 1 };
  Book book5 = { "wf2", "book2", 4 };
  Book book6 = { "wf3", "book3", 7 };
  Book book7 = { "wf3", "book3", 8 };

  plnode node2 = InitLNode();
  LNodeInsert(node2, 0, book4);
  LNodeInsert(node2, 1, book5);
  LNodeInsert(node2, 2, book6);
  LNodeInsert(node2, 3, book7);
  node1 = mergesortedLNode(node1, node2);
  printf("%.f, %.f, %.f, ", node1->data.price, node1->next->data.price, node1->next->next->data.price);
  node2 = node1->next->next->next;
  printf("%.f, %.f, %.f, ", node2->data.price, node2->next->data.price, node2->next->next->data.price);
  node1 = node2->next->next->next;
  printf("%.f, %.f", node1->data.price, node1->next->data.price);
  return 0;
}
