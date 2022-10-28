//
// Created by 41018 on 2022/8/29.
// 数据结构与算法·第一章
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <errno.h>

#define ERROR 0;
#define OVERFLOW -2
#define OK 1
#define bool int;
#define true 0;
#define false 1;
typedef int Status;

#define MAXSIZE 10000 // 为顺序表分配内存空间
typedef struct {
    char no[20]; // 图书编号
    char name[60]; // 图书名字
    float price; // 图书价格
} Book;

typedef struct {
    Book *elem; // 存储空间的基地址
    int length; // 图书表中当前图书个数
} SqList; // 图书表的顺序存储结构类型为SqList

static Status createList(SqList *L) { // 构造一个空的顺序表 L
    L->elem = (Book *)malloc(MAXSIZE); // 为顺序表分配一个大小为 MAXSIZE 的数组空间
    if(!L->elem) exit(OVERFLOW); // 存储分配失败退出
    L->length = 0; // 空表长度为 0
    return OK;
}

static void GetItem(SqList *L, int i, Book *e) {
  if(i < 0 || i > L->length -1) return; // 判断i 值是否合理，若不合理，返回ERROR
  *e = L->elem[i];
}

static int unnamedFn(Book item, int (*callback)(Book item)) {
  return callback(item);
}

static int LocateElemByFn(SqList L, int (*callback)(Book item)) { // 在顺序表L查找图书编号相同的书
    for(int i=0; i<L.length; i++) {
      int flag = 0;
      flag = unnamedFn(L.elem[i], callback);
      if(flag) return i;
    }
    return 0; // 查找失败 返回0
}

static int LocateElemByV(SqList L, char *e) { // 在顺序表L查找图书编号相同的书
  for(int i=0; i<L.length; i++) {
    if(L.elem[i].no == e) return i; // 查找成功，但返回 i+1
  }
  return 0; // 查找失败 返回0
}

static Status ListInsert(SqList *L, int i, Book e) { // 从 0 开始
  if(L->length == MAXSIZE) {
    printf("数组溢出！不能再添加\n");
    return ERROR;
  }
  if(i < 0 || i > L->length) {
    printf("不能超出数组范围！ %d~%d\n", 0, L->length);
    return ERROR;
  }
  

  for(int j = L->length-1; j >= i; j--) {
    L->elem[j+1] = L->elem[j];
  }
  
  L->elem[i] = e;
  ++L->length;
  return OK;
}

static Status ListDelete(SqList *L, int i) {
  if(i<0 || i > L->length-1) return ERROR;
  for(int j = i; j<L->length-1; j++) {
    L->elem[j] = L->elem[j+1];
  }
  --L->length;
  return OK;
}
static Status ListMerge(SqList *L, SqList *Q) {
  int len = Q->length; int j = 0;
  int start = L->length;
  for(int i = 0; i < len; i++) {
    ListInsert(L, start+i, Q->elem[i]);
  }
  return true;
}
/*
 * main 函数中调用
 * int findBook(Book book) {
    if(strcmp(book.no, "wf") == 0) return OK;
    return ERROR;
    }
 * main() {
 *  SqList L;
 *  Book book1 = {"wf", "book1", 2};
    Book book2;
    createList(&L);
    ListInsert(&L, 1, book1);
    GetItem(&L, 0, &book2);

    int index = LocateElemByFn(L, findBook);
    printf("find by value ,%d\n", index);
    ListDelete(&L, 1);
    printf("L.length: %d\n", L.length);
    ListInsert(&L, 1, book1);
    printf("L.length: %d\n", L.length);
 * }
 *
 * */