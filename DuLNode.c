/*
 * @Author: Amelia
 * @email: zhangshan1@able-elec.com
 * @Date: 2022-10-21 12:47:14
 */
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

typedef struct DuLNode {
  Book data;
  struct DuLNode *prev;
  struct DuLNode *next;
} dulnode, *dulList;

static dulList initDuLNode() {
  dulList p = (dulnode *)malloc(sizeof(dulnode));
  p->prev = NULL;
  p->next = NULL;
  return p;
}

// 双向链表的插入
static int DuLNodeInsert(dulList L, int i, Book e) {
  dulList p = L; int j = 0;
  if(i == 0) { // 首部插入
    p->data = e;
    p->prev = p;
    p->next = p;
    return 0;
  }

  while(p && j < i) {
    p = p->next;
    j++;
  }

  if(j > i) return ERROR;

  dulList node = initDuLNode();
  node->data = e;

  node->prev = p->prev;
  p->prev->next = node; // 原 p 上一个结点的 next 指向更改

  node->next = p; // node的下一个结点： node->next 指向 p
  p->prev = node; // p的prev指向 更改为 node
  return 0;
}

// 双链表的删除
static void DuLNodeDelete(dulList *L, int i) { // (dulList L, int i) {
  /****也可以通过返回 node 结点 来删除首结点***/
  dulList p = *L; int j = 0; // dulList p = L;
  dulList *q = &*L;
  dulList tmp = NULL;

  while(p->next != *L && j < i) { // 结尾的判断，p->next 不指向首结点
    p = p->next;
    j++;
  }

  if(j < i) {
    printf("超过链表长度! 最大长度：%d\n", j);
    return;
  }

  tmp = p; // tmp = p;

  p->prev->next = p->next; // p->prev->next = p->next;
  p->next->prev = p->prev; // p->next->prev = p->prev;

  if(i == 0) { // 首结点删除，更改指向地址
    *q = (*q)->next; // L = p->next;
  }

  free(tmp);
  tmp = NULL;

  // return L;
}

// 按位置获取对应位置的双链表
dulList getDulNode(dulList L, int i) {
  int j = 0; dulList p = L;
  while(p->next != L && j<i) {
    p = p->next;
    j++;
  }
  if(j<i) {
    printf("超过链表长度，最大长度：%d", j);
    return NULL;
  }

  return p;
}
/* ---- main()---------------------------------
  Book book1 = { "wf", "book", 2 };
  Book book2 = { "wf2", "book2", 3 };
  Book book3 = { "wf3", "book3", 4 };
  dulList node = initDuLNode();
  DuLNodeInsert(node, 0, book1);
  DuLNodeInsert(node, 1, book2);
  DuLNodeInsert(node, 1, book3);

  printf("%s, %s, %s\n", node->data.no, node->next->data.no, node->next->next->data.no);
  DuLNodeDelete(&node, 2);
  printf("%s,   ", node->data.no);
  DuLNodeDelete(&node, 2);
  printf("%s", node->data.no);
  dulList node2 = getDulNode(node, 1);
  printf("%s", node2->data.no);
 */