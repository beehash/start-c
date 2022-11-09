/*
 * @Author: Amelia
 * @email: zhangshan1@able-elec.com
 * @Date: 2022-08-15 12:38:53
 */
#include <stdlib.h>
#include <stdio.h>
// #include "List.c"
#include "character2.c"
// #include "DuLNode.c"
// extern  getSameSuffixPosition();

int main() {
  plnode node1 = InitLNode();
  plnode node2 = InitLNode();

  Book book1 = { "b", "book", 2 };
  Book book2 = { "o", "book2", 5 };
  Book book3 = { "o", "book3", 6 };
  Book book4 = { "k", "book3", -12 };
  Book book5 = { "i", "book3", 12 };
  Book book6 = { "n", "book3", -12 };
  Book book7 = { "g", "book3", 13 };
  LNodeInsert(node1, 0, book1);
  LNodeInsert(node1, 1, book2);
  LNodeInsert(node1, 2, book3);
  LNodeInsert(node1, 3, book4);
  LNodeInsert(node1, 4, book5);
  LNodeInsert(node1, 5, book6);
  LNodeInsert(node1, 6, book7);

  Book book8 = { "r", "book", 2 };
  Book book9 = { "e", "book2", 5 };
  Book book10 = { "a", "book3", 6 };
  Book book11 = { "d", "book3", 12 };
  LNodeInsert(node2, 0, book8);
  LNodeInsert(node2, 1, book9);
  LNodeInsert(node2, 2, book10);
  LNodeInsert(node2, 3, book11);
  LNodeInsert(node2, 4, book5);
  LNodeInsert(node2, 5, book6);
  LNodeInsert(node2, 6, book7);

  plnode node = deleteAbsSameLNode(node1, 12);
  printf("%s, %s, %s", node->data.no, node->next->data.no, node->next->next->data.no);
  return 0;
}
