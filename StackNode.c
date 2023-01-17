#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top; 
} Stack, *StackL;

static StackL initStackNode() {
  StackL s = (StackL)malloc(sizeof(Stack));
  s->top = NULL;
  return s;
}

// 链表不需要预先分配内存 不用判断是否栈满
static bool isEmptyStack(StackL s) {
  if(s->top == NULL) return true;
  return false;
}

// 入栈
static void pushStack(StackL s, int e) {
   Node *p = (Node *) malloc(sizeof(Node));
   p->data = e;
   p->next = s->top;
   s->top = p;
}

// 出栈
static int popStack(StackL s) {
  if(isEmptyStack(s)) return 1;
  int e = s->top->data;
  Node *p = s->top;
  s->top = s->top->next;
  free(p);
  return e;
}

// 取栈顶元素
static int getTop(StackL s) {
  if(isEmptyStack(s)) return INT_MIN;
  return s->top->data;
}
