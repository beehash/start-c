//
// Created by 41018 on 2022/9/15.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ERROR 0;
#define OVERFLOW -2
#define OK 1
typedef int Status;

typedef struct {
  char no[20]; // 图书编号
  char name[60]; // 图书名字
  float price; // 图书价格
} Book;

union BookStatus {
  Book book;
  int err;
};

typedef struct LNode{
  Book data;
  struct LNode *next;
} lnode, *plnode;

static lnode *InitLNode () {
  lnode *p=(lnode*)malloc(sizeof(lnode));
  p->next = p;
  return p;
}

static Status GetItem(lnode *L, int i, Book *e){
  lnode *p = L;
  int j = 0;
  while(p && j<i) {
    p = p->next;
    ++j;
  }
  if(!p || j>i ) return ERROR;

  *e = p->data;
  return OK;
}

static lnode* LocateElem(lnode *L, char *e) {
  lnode *p = L;
  while(p && strcmp(p->data.no, e) != 0) {
    p = p->next;
  }
  return p;
}
// 结构：头结点-首元结点-结点2-结点3-尾结点
static Status LNodeInsert(lnode *L, int i, Book e) {// 从0开始
  lnode *p = L;
  int j = 0;
  lnode *c=(lnode*)malloc(sizeof(lnode));

  c->data = e;

  while(p && (j < i)) {
    p = p->next;
    ++j;
  }

  if(!p || j > i) return ERROR;

  c->next = p->next;
  p->next = c;
  return OK;
}

static Status NodeDelete(lnode *L, int i) {
  lnode *p = L;
  int j = 0;
  while(p->next && j<i-1) {
    p = p->next;
    ++j;
  }
  if(!p->next || j>i-1 ) return ERROR;

  lnode *q = p->next;
  p->next = q->next;
  free(q);
  return OK;
}
// mergesortedLNode
static plnode mergesortedLNode(plnode node1, plnode node2) {
  plnode head1 = node1->next;
  plnode head2 = node2->next;
  plnode node = InitLNode();
  plnode head = node;
  plnode tmp, tmp2;
  int a = 1;
  // head1 256 head2 147
  while(head1 != node1 && head2 != node2) {// node->next == node1 尾结点判断
    if(head1->data.price >= head2->data.price) {
      // head2 head1; head2++; 5, 4
      tmp = head2->next;
      head2->next = head1;
      node->next = head2;
      node->next->next->next = node->next;

      node = node->next->next;
      head2 = tmp;
    } else {// head1 head2; head1++;
      tmp = head1->next;
      head2->next = head1->next;
      head1->next = head2;
      node->next = head1;

      node = node->next->next;
      head1 = tmp;
    }
  }

  // if(head1 == node1) { // node1到结尾
  //   while(head != node2) { // 尾结点指针指向
  //     head2 = head2->next;
  //   }
  //   head2->next = node1;
  // }

  return node;
}
/**
*
* Book book1 = {"wf", "book", 2};
  lnode *node = InitLNode();
  LNodeInsert(node, 0, book1);
  LNodeInsert(node, 1, book1);
  printf("the head data.no: %s\nand the next: %s \n", node->data.no, node->next->data.no);
  Book book2;
  GetItem(node, 1, &book2);
  printf("book2.no: %s\n", book2.no);
  lnode *p = LocateElem(node, "wf");
  printf("address book.no === wf: %p\n", p);
  NodeDelete(node, 1);
  printf("lnode.next after delete: %s\n", node->next);
 *
 *
*/