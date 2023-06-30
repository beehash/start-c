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

typedef int number;
typedef char string;

// typedef enum {string, number, Book} ndata;

union BookStatus {
  Book book;
  int err;
};

typedef union {
  int num;
  char *str;
  Book book;
} UnionData;

typedef struct LNode{
  UnionData data;
  struct LNode *next;
} lnode, *plnode;

static lnode *InitLNode () {
  lnode *p=(lnode*)malloc(sizeof(lnode));
  p->next = p;
  return p;
}

static Status GetItem(lnode *L, int i, UnionData *e){
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

static lnode* LocateElem(lnode *L, UnionData *e) {
  lnode *p = L;
  while(p && memcmp(&p->data, e, sizeof(UnionData)) != 0) {
    p = p->next;
  }
  return p;
}
// 结构：头结点-首元结点-结点2-结点3-尾结点
static Status LNodeInsert(lnode *L, int i, UnionData e) {// 从0开始
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